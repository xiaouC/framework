//
//  Generator.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-5.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "Generator.h"
#include "ParticleSystemManager.h"
#include "Util.h"
#include "shaders/ccGLStateCache.h"
//#include "CCControlSwitch.h"
using namespace cocos2d;

void GLDrawArrays(CCTexture2D* txt, float* vertices, float* coordinates, float* rgba, int size, bool uRepeat, bool vRepeat);

Generator::Generator(GeneratorData* gd)
{
    age = 0.0f; //该发射器的年龄
	genCount = 0; //总共生成的粒子数
	isVisible = true;
    currentRate = 0;
    genSpinV = 0;
    genSpinH = 0;
    genData = gd;
    position.Set(0, 0, 0);
}

Generator::~Generator()
{
    for(int i = 0; i < sim.size(); i ++){
        delete sim[i];
    }
    sim.clear();
}

void BlendFunc(int sfactor, int dfactor)
{
//#ifdef ANDROID
//    glBlendFunc(sfactor, dfactor);
//#else
    if(sfactor == GL_SRC_ALPHA && dfactor == GL_ONE_MINUS_SRC_ALPHA) {
        glBlendFuncSeparate(sfactor, dfactor, GL_ONE, GL_ONE);
    } else {
        //glBlendFuncSeparate(sfactor, dfactor, sfactor, dfactor);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE );
        //glBlendFunc(sfactor, dfactor);
    }
//#endif
}


void GLTransform(float* vertices)
{
    
    kmMat4* pM = new kmMat4;
    kmGLGetMatrix(KM_GL_MODELVIEW, pM);
    for(int i=0;i<4;i++)
    {
        float x, y, z;
        x = vertices[i*3+0] * pM->mat[0] + vertices[i*3+1] * pM->mat[4] + vertices[i*3+2] * pM->mat[8] + pM->mat[12];
        y = vertices[i*3+0] * pM->mat[1] + vertices[i*3+1] * pM->mat[5] + vertices[i*3+2] * pM->mat[9] + pM->mat[13];
        z = vertices[i*3+0] * pM->mat[2] + vertices[i*3+1] * pM->mat[6] + vertices[i*3+2] * pM->mat[10] + pM->mat[14];
        
        vertices[i*3+0] = x;
        vertices[i*3+1] = y;
        vertices[i*3+2] = z;
    }
    delete pM;
}

void Generator::OnRender(float sysX, float sysY)
{
    ParticleRender* pr = genData->pr;
    CCTexture2D* img = ParticleSystemManager::sharedParticleSystemManager()->GetImage(pr->textureName.Data());
    
    //    RenderUtil::SetColor(); 移植临时注释掉 
    //    ccGLBlendFunc(pr->sourceFactor, pr->destinationFactor); 
    BlendFunc(pr->sourceFactor, pr->destinationFactor);
	//ccGLBlendFunc(1, 771);
    pr->uOffset+=pr->uSpeed;
    pr->vOffset+=pr->vSpeed;
    
    static float vertices[1000*18];//绘制坐标，6个三维顶点 
    static float coordinates[1000*12];//纹理坐标，6个二维顶点 
    static float rgba[1000*6*4];
    
    int playAllCount=(pr->cutW*pr->cutH)*pr->delay;
    float cutWidth=1/(float)pr->cutW;//单个切块的宽 
    float cutHeight=1/(float)pr->cutH;//单个切块的高 
    
    int simsize = sim.size();
    if(simsize > 1000){//限制只画1000个 
        simsize = 1000;
    }
    
    int index = 0;
    int indexRgba = 0;
    int indexCoord = 0;
    int indexVert = 0;
    for(int i = 0; i < simsize; i ++){
        ParticleSpace* ps = sim[i];
        if(ps != NULL){
            std::vector<Particle*>& particles = ps->particles;
            int psize = particles.size();
            for(int j = 0; j < psize; j ++){
                Particle* p = particles[j];
                if(p != NULL && img != NULL){
                    if(p->alpha == 0){//alpha为0，全透明不处理 
                        continue;
                    }
                    // texture coordinates
                    float tsize = p->size * 0.5f;
                    
                    // apply width and height
                    float width =p->width*32;//p->width*64* 0.5f;
                    float height =p->height*32;//p->height*64 * 0.5f;
                    float sx = 1.0;
                    float sy = 0.0;
                    float sz = 0.0;
                    
                    float ux = 0.0;
                    float uy = 1.0;
                    float uz = 0.0;
                    Vector3f tup;
                    tup.Set(ux, uy, uz);
                    tup.ScaleLocal(height);
                    Vector3f tdir;
                    tdir.Set(sx, sy, sz);
                    tdir.ScaleLocal(width);
                    
                    Vector3f topleftT;
                    topleftT.SetX( -tup.GetX() - tdir.GetX() );
                    topleftT.SetY( -tup.GetY() - tdir.GetY() );
                    topleftT.SetZ( -tup.GetZ() - tdir.GetZ() );
                    Vector3f toprightT;
                    toprightT.SetX( -tup.GetX() + tdir.GetX() );
                    toprightT.SetY( -tup.GetY() + tdir.GetY() );
                    toprightT.SetZ( -tup.GetZ() + tdir.GetZ() );
                    Vector3f bottomleftT;
                    bottomleftT.SetX( tup.GetX() - tdir.GetX() );
                    bottomleftT.SetY( tup.GetY() - tdir.GetY() );
                    bottomleftT.SetZ( tup.GetZ() - tdir.GetZ() );
                    Vector3f bottomrightT;
                    bottomrightT.SetX( tup.GetX() + tdir.GetX() );
                    bottomrightT.SetY( tup.GetY() + tdir.GetY() );
                    bottomrightT.SetZ( tup.GetZ() + tdir.GetZ() );
                    
                    // apply scale
                    bottomrightT.ScaleLocal(tsize);
                    bottomleftT.ScaleLocal(tsize);
                    toprightT.ScaleLocal(tsize);
                    topleftT.ScaleLocal(tsize);
                    
                    float texWidth = 1.0 / p->texWidth;
                    float texHeight = 1.0 / p->texHeight;
                    
                    //                    int playAllCount=(pr->cutW*pr->cutH)*pr->delay;放到循环外 
                    if(p->cutIndex>playAllCount-1){
                        if(pr->repeatPlay){
                            p->cutIndex=ParticleUtil::RemFloat(p->cutIndex, playAllCount);
                        }else{
                            p->cutIndex=(short) (playAllCount-1);
                        }
                    }
                    
                    int hIndex=(p->cutIndex/pr->delay)/pr->cutW;//切块行索引 
                    int wIndex=(p->cutIndex/pr->delay)%pr->cutW;//切块列索引 
                    //                    float cutWidth=1/(float)pr->cutW;//单个切块的宽  放到循环外 
                    //                    float cutHeight=1/(float)pr->cutH;//单个切块的高 放到循环外 
                    Vector2f bl, br, tr, tl;
                    //                    bl.Set((wIndex)*cutWidth,	(hIndex+1)*cutHeight);
                    //                    br.Set((wIndex+1)*cutWidth, (hIndex+1)*cutHeight);
                    //                    tr.Set((wIndex+1)*cutWidth, (hIndex)*cutHeight);
                    //                    tl.Set((wIndex)*cutWidth, (hIndex)*cutHeight);
                    
                    bl.Set(-cutWidth*0.5f,	 cutHeight*0.5f);
                    br.Set(cutWidth*0.5f,    cutHeight*0.5f);
                    tr.Set(cutWidth*0.5f,    -cutHeight*0.5f);
                    tl.Set(-cutWidth*0.5f,   -cutHeight*0.5f);
                    
                    float uvAngle=p->age*pr->rotateSpeed+pr->rotateDegree;
                    
                    ParticleUtil::rotate2f(bl, uvAngle);
                    ParticleUtil::rotate2f(br, uvAngle);
                    ParticleUtil::rotate2f(tr, uvAngle);
                    ParticleUtil::rotate2f(tl, uvAngle);
                    
                    bl.Set(bl.x+(wIndex+0.5f)*cutWidth, bl.y+(hIndex+0.5f)*cutHeight);
                    br.Set(br.x+(wIndex+0.5f)*cutWidth, br.y+(hIndex+0.5f)*cutHeight);
                    tr.Set(tr.x+(wIndex+0.5f)*cutWidth, tr.y+(hIndex+0.5f)*cutHeight);
                    tl.Set(tl.x+(wIndex+0.5f)*cutWidth, tl.y+(hIndex+0.5f)*cutHeight);
                    
                    float tempangle=p->angle;
                    if(genData->pb->isAutoAngle){
                        tempangle+=atan2f(p->direction.GetY(), p->direction.GetX());
                    }
                    
                    ParticleUtil::rotate2f(bottomleftT, tempangle);
                    ParticleUtil::rotate2f(bottomrightT, tempangle);
                    ParticleUtil::rotate2f(toprightT, tempangle);
                    ParticleUtil::rotate2f(topleftT, tempangle);
                    
                    bl.Set(pr->uOffset+bl.x * texWidth, pr->vOffset+bl.y * texHeight );
                    br.Set(pr->uOffset+br.x * texWidth, pr->vOffset+br.y * texHeight );
                    tr.Set(pr->uOffset+tr.x * texWidth, pr->vOffset+tr.y * texHeight );
                    tl.Set(pr->uOffset+tl.x * texWidth, pr->vOffset+tl.y * texHeight );
                    
                    if(index < genData->gb->getNumber()){
                        for(int k = 0; k < 6; k ++){
                            rgba[indexRgba + k*4] = p->color.GetR();
                            rgba[indexRgba + k*4 + 1] = p->color.GetG();
                            rgba[indexRgba + k*4 + 2] = p->color.GetB();
                            rgba[indexRgba + k*4 + 3] = p->alpha;
                        }
                        
                        coordinates[indexCoord +0] = tl.x;
                        coordinates[indexCoord+1] = tl.y;
                        coordinates[indexCoord+2] = tr.x;
                        coordinates[indexCoord+3] = tr.y;
                        coordinates[indexCoord+4] = bl.x;
                        coordinates[indexCoord+5] = bl.y;
                        coordinates[indexCoord+6] = br.x;
                        coordinates[indexCoord+7] = br.y;
                        coordinates[indexCoord+8] = bl.x;
                        coordinates[indexCoord+9] = bl.y;
                        coordinates[indexCoord+10] = tr.x;
                        coordinates[indexCoord+11] = tr.y;
                        
                        float tempV[12];
                        tempV[0] = sysX + p->position.GetX() + topleftT.x;
                        tempV[1] = sysY + p->position.GetY() + topleftT.y;
                        tempV[2] = 0;
                        tempV[3] = sysX + p->position.GetX() + toprightT.x;
                        tempV[4] = sysY + p->position.GetY() + toprightT.y;
                        tempV[5] = 0;
                        tempV[6] = sysX + p->position.GetX() + bottomleftT.x;
                        tempV[7] = sysY + p->position.GetY() + bottomleftT.y;
                        tempV[8] = 0;
                        tempV[9] = sysX + p->position.GetX() + bottomrightT.x;
                        tempV[10] = sysY + p->position.GetY() + bottomrightT.y;
                        tempV[11] = 0;
                        
//                        GLTransform(tempV);//计算当前矩阵   移植临时注释掉 
                        
                        vertices[indexVert+0] = tempV[0];
                        vertices[indexVert+1] = tempV[1];
                        vertices[indexVert+2] = tempV[2];
                        vertices[indexVert+3] = tempV[3];
                        vertices[indexVert+4] = tempV[4];
                        vertices[indexVert+5] = tempV[5];
                        vertices[indexVert+6] = tempV[6];
                        vertices[indexVert+7] = tempV[7];
                        vertices[indexVert+8] = tempV[8];
                        vertices[indexVert+9] = tempV[9];
                        vertices[indexVert+10] = tempV[10];
                        vertices[indexVert+11] = tempV[11];
                        vertices[indexVert+12] = tempV[6];
                        vertices[indexVert+13] = tempV[7];
                        vertices[indexVert+14] = tempV[8];
                        vertices[indexVert+15] = tempV[3];
                        vertices[indexVert+16] = tempV[4];
                        vertices[indexVert+17] = tempV[5];
                        index ++;
                        indexRgba+=24;
                        indexCoord+=12;
                        indexVert+=18;
                    }
                }
            }
        }
    }
    if(index > 0){
    	//if(genData->noColor){
            //GLDrawArrays(img, vertices, coordinates,
                         //0, index, pr->uRepeat, pr->vRepeat);
    	//}else{
            GLDrawArrays(img, vertices, coordinates,
                         rgba, index, pr->uRepeat, pr->vRepeat);
    	//}
        
    }
    //    ccGLBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //    RenderUtil::SetColor();  移植临时注释掉 
}

//循环发射粒子，dt为粒子系统刷新的单帧时间 
void Generator::OnUpdate(float dt)
{
    GeneratorBehaviour* gb = genData->gb;
    ParticleBehaviour* pb = genData->pb;
    std::vector<Modifier*>& modifiers = genData->md;
    if (gb == NULL){
        return;
    }
    
    age += dt;
    bool needgen = true;
    if(age < gb->bias){//判断是否已满足等待时间 
        needgen = false;
    }else if(age > (gb->bias + gb->lifeTime)){//超出发射器的生命周期 
        if(gb->repeat){
            age = ParticleUtil::RemFloat(age+gb->bias, gb->bias + gb->lifeTime);
        }else{
            needgen=false;
        }
    }
    if(needgen){//需要发射粒子 
        gb->OnUpdate(this, age - gb->bias, dt);  //更新发射器属性（减去等待偏移时间才是发射器真正生效的时间） 
        Generate(age - gb->bias, dt);  //根据发射器属性发射粒子（减去等待偏移时间才是发射器真正生效的时间） 
    }
    
    if(modifiers.size()==0){
        int simsize = sim.size();
        for(int i=0;i<simsize;i++){
            ParticleSpace* ps = sim[i];
            std::vector<Particle*>& particles = ps->particles;
            pb->OnUpdate(particles); //根据粒子关键帧属性组更新粒子属性 
            
            for(std::vector<Particle*>::iterator it = particles.begin(); it != particles.end();){
                Particle* p = *it;
                if(p != NULL){
                    p->OnUpdate(dt);//粒子自身基本属性数据更新 
                    if(p->particleLife < 0 && pb->killParticles){
                        //                        delete p; 不再删除，改为录入回收池 
                        ParticleSpace::RecycleParticle(p);
                        it = particles.erase(it);
                    }else{
                        it ++;
                    }
                }
            }
        }
    }else{
        int simsize = sim.size();
        for(int i=0;i<simsize;i++){
            ParticleSpace* ps = sim[i];
            std::vector<Particle*>& particles = ps->particles;
            pb->OnUpdate(particles); //根据粒子关键帧属性组更新粒子属性 
            
            for(std::vector<Particle*>::iterator it = particles.begin(); it != particles.end();){
                Particle* p = *it;
                if(p != NULL){
                    int modifysize = modifiers.size();
                    for(int k = 0; k < modifysize; ++k)
                    {
                        Modifier* m= modifiers[k];
                        m->Modify(p, dt);
                    }
                    p->OnUpdate(dt);//粒子自身基本属性数据更新 
                    if(p->particleLife < 0 && pb->killParticles){
                        //                        delete p; 不再删除，改为录入回收池 
                        ParticleSpace::RecycleParticle(p);
                        it = particles.erase(it);
                    }else{
                        it ++;
                    }
                }
            }
        }
    }
}

void Generator::Generate(float time, float dt) //生成粒子 
{
    GeneratorBehaviour* gb = genData->gb;//发射器属性组 
    std::vector<GeneratorSpace*>& allSpace = genData->allSpace;
    //    position.Set(0, 0, 0);
    if(!gb->regenerateParticles&&genCount>gb->getNumber()){
        return;
    }
    
    float curRate=currentRate;
    int spaceSize = allSpace.size();
    for(int k=0;k<spaceSize;k++){
        GeneratorSpace* space = allSpace[k];
        ParticleSpace* ps= sim[k];
        ps->age+=dt;
        std::vector<Particle*>& particles=ps->particles;
        curRate = currentRate*dt * space->rateScale;
        ps->totalGenerated += curRate;
        if(ps->totalGenerated < 1) {
            continue;
        }
        
        int frameCount = (int) ps->totalGenerated;
        int max = gb->getNumber();
        int size = particles.size();
        if (size < max) {//创建粒子 
            for (int i = 0; i < frameCount; i++) {
                if (particles.size() >= max ){
                    break;
                }
                Particle* p = ParticleSpace::AddParticle();//new Particle();
                if(p == NULL){//可能栗子池满了，就不再创建新的栗子了 
                    continue;
                }
                particles.push_back(p);
                ++genCount;
                
                space->InitParticle(p, ps, time);//根据发射器空间类型初始化粒子的位置 
                p->position.AddLocal(position.GetX(), position.GetY(), position.GetZ());//发射器的位置加到粒子的位置坐标中 
                gb->InitParticle(this, p, time);//根据发射器属性设定粒子初始属性 
                if(!gb->regenerateParticles&&genCount>gb->getNumber()){
                    break;
                }
            }
        }
        
        ps->totalGenerated -= frameCount;
    }
}

void Generator::Reset()
{
    int size = sim.size();
    for(int i=0;i<size;i++){
        ParticleSpace* ps = sim[i];
        int psize = ps->particles.size();
        for(int j = 0; j < psize; j++){
            //            delete ps->particles[j]; 不再删除，改为录入回收池 
            ParticleSpace::RecycleParticle(ps->particles[j]);
        }
        ps->age = 0;
        ps->particles.clear();
        //此处不能delete ps,因为还会循环用 
    }//此处不能clear sim，因为sim还要用 
    
    //    position.Set(0, 0, 0);
    age = 0.0f; //该发射器的年龄 
	genCount = 0; //总共生成的粒子数 
	isVisible = true;
    currentRate = 0;
    genSpinV = 0;
    genSpinH = 0;
    
}

void GLDrawArrays(CCTexture2D* txt, float* vertices, float* coordinates, float* rgba, int size, bool uRepeat, bool vRepeat)
{
//#ifdef ANDROID
//    if (!m_bIsSupportEs2) {
//        RenderUtilEs1::GLDrawArrays(txt,vertices, coordinates, rgba, size, uRepeat, vRepeat);
//        return;
//    }
//#endif
    
    if(txt==NULL)
    {
        return;
    }
    
    if(rgba)
    {
        ccGLEnableVertexAttribs(kCCVertexAttribFlag_PosColorTex);
    }
    else
    {
        ccGLEnableVertexAttribs(kCCVertexAttrib_Position|kCCVertexAttrib_TexCoords);
    }
    //float* vs = new float[sizeof(float)*6*3*size];
    //memcpy(vs, vertices, sizeof(float)*6*3*size);
    glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    //glEnableVertexAttribArray(kCCVertexAttrib_Position);
    //delete [] vs;
    
    ///float* cs = new float[sizeof(float)*6*2*size];
    //memcpy(cs, coordinates, sizeof(float)*6*2*size);
    glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, 0, coordinates);
    //glEnableVertexAttribArray(kCCVertexAttrib_TexCoords);
    //delete [] cs;
    
	if(rgba)
	{
		glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_FLOAT, GL_FALSE, 0, rgba);
		glEnableVertexAttribArray(kCCVertexAttrib_Color);
	}
    
    //glActiveTexture(GL_TEXTURE0);
    ccGLBindTexture2D(txt->getName());
    //    glUniform1i(m_uTextureLocation, 0); 移植临时注释掉 
    ParticleSystem::shader->use();
    //ParticleSystem::shader->updateUniforms();
    ParticleSystem::shader->setUniformsForBuiltins();
    
    if(uRepeat) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    } else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    }
    
    if(vRepeat) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    } else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
    
    glDrawArrays(GL_TRIANGLES, 0, size*6);
}
