//
//  ValueList.cpp
//  Stoneage
//
//  Created by gamebean on 12-12-7.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#include <iostream>
#include "ValueList.h"
//-----------------------
ListObject::ListObject()
{
	resolution = 30;
	startTime = 0.0f;
	lastTime = 0.0f;
}

ListObject::~ListObject()
{

    for(int i = 0; i < values.size(); i ++){
        delete values[i];
    }
    values.clear();
//91 del
//    for(int i = 0; i < array.size(); i ++){
//        delete array[i];
//    }
//    array.clear();
}

void ListObject::ReadObject(int listType, particle::InputStream& is){
    int length= is.ReadShort();
    for(int i=0;i<length;i++){
        ValueObject* vo = NULL;
        if(listType == ValueList::FLOAT_VALUE){
            vo = new FloatValue();
            ((FloatValue*)vo)->ReadObject(is);
        }else if(listType == ValueList::COLOR_VALUE){
            vo = new ColorValue();
            ((ColorValue*)vo)->ReadObject(is);
        }else if(listType == ValueList::VECTOR3F_VALUE){
            vo = new Vector3f();
            ((Vector3f*)vo)->ReadObject(is);
        }
        values.push_back(vo);
    }
    if(length > 0){
        CreateArray(listType);
        startTime = values[0]->time;
        lastTime = values[length - 1]->time;
    }
}

void ListObject::CreateArray(int listType)//创建插值数组 
{
    ValueObject* current = NULL;
    ValueObject* next = NULL;
    for (int i = 0; i < values.size(); i++) {
        current = values[i];
        if (i + 1 < values.size()) {
            next = values[i + 1];
        } else{
            next = NULL;
        }
        CreateArrayElements(listType, array, current, next);               
    }
}

void ListObject::CreateArrayElements(int listType, std::vector<ValueObject*>& array, ValueObject* current, ValueObject* next)
{
    // 如果已经是结尾了，那么直接添加当前的 
    if (next == NULL) {
        array.push_back(current);
        return;
    }
    
    int endIndex = 0;
    int startIndex = 0; // 开始时间为0 
    
    float maxTime = 0; //
    
    if (next != NULL) {
        maxTime = next->time - current->time;
        endIndex = (int) ((maxTime) * resolution);
    }
    
    float time = 0.0f;
    for (int i = startIndex; i < endIndex; i++) {
        time = (((float) i) / resolution);
        if(listType == ValueList::FLOAT_VALUE){
            FloatValue* fv = CalculateFloatResult((FloatValue*)current, (FloatValue*)next, time, maxTime);
            array.push_back(fv);
        }else if(listType == ValueList::COLOR_VALUE){
            ColorValue* cv = CalculateColorResult((ColorValue*)current, (ColorValue*)next, time, maxTime);
            array.push_back(cv);
        }else if(listType == ValueList::VECTOR3F_VALUE){
            Vector3f* v3v = CalculateVector3fResult((Vector3f*)current, (Vector3f*)next, time, maxTime);
            array.push_back(v3v);
        }
    }
}

FloatValue* ListObject::CalculateFloatResult(FloatValue* current, FloatValue* next, float dt, float tt)
{
    FloatValue* fv = new FloatValue();
    fv->Set(current->value + ((next->value - current->value) / tt) * dt);   
    return fv;
}
ColorValue* ListObject::CalculateColorResult(ColorValue* current, ColorValue* next, float dt, float tt)
{
    ColorValue* cv = new ColorValue();
    float r = (current->GetR() + ((next->GetR() - current->GetR()) * dt/tt));
    float g = (current->GetG() + ((next->GetG() - current->GetG()) * dt/tt));
    float b = (current->GetB() + ((next->GetB() - current->GetB()) * dt/tt));
    cv->Set(r, g, b);
    return cv;
}
Vector3f* ListObject::CalculateVector3fResult(Vector3f* current, Vector3f* next, float dt, float tt)
{
    Vector3f* v3v = new Vector3f();
    float x = current->GetX() + (next->GetX() - current->GetX()) * dt / tt;
    float y = current->GetY() + (next->GetY() - current->GetY()) * dt / tt;
    float z = current->GetZ() + (next->GetZ() - current->GetZ()) * dt / tt;
    v3v->Set(x, y, z);
    return v3v;
}

ValueObject* ListObject::GetValueAt(float time)
{
    if(time <startTime){
        return array[0];
    }
    
    int index = (int) ((float) time * resolution);
    if (index >= array.size()){
        index = array.size() - 1;
    }
    //return array[index];
    return array.data()[index];
}
//--------------------------

ValueList::ValueList()
{
    mainValueList = new ListObject();
    randomValueList = new ListObject();
    repeat = false; //当时间超过主时间时 是否重复 
	bias = 0; //更新数据时的偏移时间 
	active = false; //该属性列表是否激活	 
    random = false; //是否在主数据基础上添加随机数 
}

ValueList::~ValueList()
{
    delete mainValueList;
    delete randomValueList;
}

//获取混合数据 
void ValueList::GetValueAt(float time, ValueObject& vobj)
{
    if(time<bias){
        return;
    }
    
    float mtime = mainValueList->lastTime;
    if (time > mtime) {
        if (repeat) {
            time = ParticleUtil::RemFloat(time, mtime);
        } else {
            time = mtime;
        }
    }
    
    if (random) {
        ValueObject* v = mainValueList->GetValueAt(time);
        ValueObject* rv = randomValueList->GetValueAt(time);
        vobj.SetMixValue(v, rv);
    } else{
        ValueObject* v = mainValueList->GetValueAt(time);
        vobj.Set(v);
    }
}

void ValueList::ReadList(particle::InputStream& is){
    active=is.ReadBoolean();
    int listType = -1;
    FloatList* fl=dynamic_cast<FloatList*>(this);
    if(fl != NULL){
        listType = FLOAT_VALUE;
    }
    if(listType < 0){
        ColorList* cl=dynamic_cast<ColorList*>(this);
        if(cl != NULL){
            listType = COLOR_VALUE;
        }
    }
    if(listType < 0){
        Vector3fList* cl=dynamic_cast<Vector3fList*>(this);
        if(cl != NULL){
            listType = VECTOR3F_VALUE;
        }
    }
    if(listType < 0){
        listType = 0;
    }
    if(active){
        for(int i = 0; i < mainValueList->values.size(); i ++){
            delete mainValueList->values[i];
        }
        mainValueList->values.clear();
        mainValueList->ReadObject(listType, is);
        bias=ParticleUtil::Float_Java2C(is.ReadFloat());
        repeat=is.ReadBoolean();
    }else{
        mainValueList->CreateArray(listType);
        return;
    }
    
    random=is.ReadBoolean();
    if(random){
        for(int i = 0; i < randomValueList->values.size(); i ++){
            delete randomValueList->values[i];
        }
        randomValueList->values.clear();
        randomValueList->ReadObject(listType, is);
    }
}

//-----------------------
FloatList::FloatList()
{
    
}

FloatList::~FloatList()
{
}

void FloatList::SetFirstValue(float v)
{
    FloatValue* fv = new FloatValue(v, 0);
    mainValueList->values.clear();
    mainValueList->values.push_back(fv);
    randomValueList->values.clear();
    FloatValue* randfv = new FloatValue(0, 0);
    randomValueList->values.push_back(randfv);
}

//------------------------
ColorList::ColorList()
{
    
}

ColorList::~ColorList(){

}

void ColorList::SetFirstValue(float r, float g, float b)
{
    ColorValue* cv = new ColorValue(r, g, b, 0);
    mainValueList->values.clear();
    mainValueList->values.push_back(cv);
    randomValueList->values.clear();
    ColorValue* randcv = new ColorValue(0, 0, 0, 0);
    randomValueList->values.push_back(randcv);
}

//-------------------------
Vector3fList::Vector3fList()
{
    
}

Vector3fList::~Vector3fList(){

}

void Vector3fList::SetFirstValue(float x, float y, float z)
{
    Vector3f* v3f = new Vector3f(x, y, z, 0);
    mainValueList->values.clear();
    mainValueList->values.push_back(v3f);
    randomValueList->values.clear();
    Vector3f* randv3f = new Vector3f(0, 0, 0, 0);
    randomValueList->values.push_back(randv3f);
}

//--------------------------