//
//  Util.h
//  Stoneage
//
//  Created by fanxiaoli on 12-12-9.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_Util_h
#define Stoneage_Util_h

struct Vector2f;
struct Vector3f;
class ParticleUtil {    
public:
    ParticleUtil();
    ~ParticleUtil();
     
    inline static ParticleUtil& GetInstance(){
        static ParticleUtil self;
        return self;
    }
    inline static float Float_Java2C(float f){
        char* buffer=(char*)&f;
        char floatBuffer[4];
        floatBuffer[0]=buffer[3];
        floatBuffer[1]=buffer[2];
        floatBuffer[2]=buffer[1];
        floatBuffer[3]=buffer[0];
        return *(float*)floatBuffer;
    }
    static void InitUtil();
    static float RemFloat(float v1, float v2); //对float v1 对 float v2取余数 
    static float RandFloat();//随即生成float随机数(0-1) 
    static float RandFloat(float end); //随即生产(0-end)之间的float随机数 
    static float RandFloat(float begin, float end); //随即生产begin-end之间的float随机数 
    static void rotateOnAngleVector(Vector3f& position, float angleX, float angleY, float angleZ);
    static void rotate2f(Vector3f& v, float angle);
    static void rotate2f(Vector2f& v, float angle);
    static float CreateRandFloat();//随即生成float随机数(0-1) 
    static float CreateRandFloat(float end); //随即生产(0-end)之间的float随机数 
    static float CreateRandFloat(float begin, float end); //随即生产begin-end之间的float随机数 
    
    static const int MAX_FLOAT_COUNT = 20000;
    static float randPool[MAX_FLOAT_COUNT];
};


#endif
