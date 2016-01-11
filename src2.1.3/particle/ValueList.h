//
//  ValueList.h
//  Stoneage
//
//  Created by gamebean on 12-12-7.
//  Copyright (c) 2012年 Home. All rights reserved.
//

#ifndef Stoneage_ValueList_h
#define Stoneage_ValueList_h

#include "Util.h"
#include "./util/Stream.h"
#include "math.h"
#include <vector>

//结点帧数据的基类
struct ValueObject
{
    ValueObject(){}
    ~ValueObject(){}
    float time;
    virtual void ReadObject(particle::InputStream& is){}
    virtual void SetMixValue(ValueObject* v1, ValueObject* v2){}
    virtual void Set(ValueObject* v){}//拷贝数据
};

// 结点帧数据-数值 
struct FloatValue : public ValueObject
{
    FloatValue(){
        value = 0;
        time = 0;
    }
    
    FloatValue(float cv, float ct){
        value = cv;
        time = ct;
    }
    
    virtual void ReadObject(particle::InputStream& is){
        time = ParticleUtil::Float_Java2C(is.ReadFloat());
        value = ParticleUtil::Float_Java2C(is.ReadFloat());
    }
    
    inline void Set(float v){
        value = v;
    }
    
    virtual void Set(ValueObject* v){
        value = ((FloatValue*)v)->value;
    }
    
    inline float Get(){
        return value;
    }
    
    inline void AddLocal(float v){
        value += v;
    }
    
    inline void ScaleLocal(float scale)
    {
        value *= scale;
    }
    
    virtual void SetMixValue(ValueObject* v1, ValueObject* v2){
        value = ((FloatValue*)v1)->value + ParticleUtil::RandFloat(((FloatValue*)v2)->value) - ((FloatValue*)v2)->value*0.5;
    }
    
    float value;
};

//结点帧数据-颜色
struct ColorValue:ValueObject
{
    ColorValue(){
        r = 0;
        g = 0;
        b = 0;
        time = 0;
    }
    
    ColorValue(float cr, float cg, float cb, float ct){
        r = cr;
        g = cg;
        b = cb;
        time = ct;
    }
    
    virtual void ReadObject(particle::InputStream& is){
        time = ParticleUtil::Float_Java2C(is.ReadFloat());
        r = ParticleUtil::Float_Java2C(is.ReadFloat());
        g = ParticleUtil::Float_Java2C(is.ReadFloat());
        b = ParticleUtil::Float_Java2C(is.ReadFloat());
    }
    
    inline void Set(float cr, float cg, float cb){
        r = cr;
        g = cg;
        b = cb;
    }
    
    virtual void Set(ValueObject* v){
        r = ((ColorValue*)v)->r;
        g = ((ColorValue*)v)->g;
        b = ((ColorValue*)v)->b;
    }
    
    inline float GetR(){
        return r;
    }
    
    inline float GetG(){
        return g;
    }
    
    inline float GetB(){
        return b;
    }
    
    inline void AddLocal(float r, float g, float b){
        this->r += r;
        this->g += g;
        this->b += b;
    }
    
    inline void ScaleLocal(float scale)
    {
        this->r *= scale;
        this->g *= scale;
        this->b *= scale;
    }
    
    virtual void SetMixValue(ValueObject* v1, ValueObject* v2){
        r = ((ColorValue*)v1)->r + ParticleUtil::RandFloat(((ColorValue*)v2)->r) - ((ColorValue*)v2)->r*0.5;
        g = ((ColorValue*)v1)->g + ParticleUtil::RandFloat(((ColorValue*)v2)->g) - ((ColorValue*)v2)->g*0.5;
        b = ((ColorValue*)v1)->b + ParticleUtil::RandFloat(((ColorValue*)v2)->b) - ((ColorValue*)v2)->b*0.5;
    }
    
    float r;
    float g;
    float b;
};

//结点帧数据-向量
struct Vector3f: public ValueObject
{
    Vector3f(){
        x = 0;
        y = 0;
        z = 0;
        time = 0;
    }
    
    Vector3f(float cx, float cy, float cz, float ct){
        x = cx;
        y = cy;
        z = cz;
        time = ct;
    }
    
    virtual void ReadObject(particle::InputStream& is){
        time = ParticleUtil::Float_Java2C(is.ReadFloat());
        x = ParticleUtil::Float_Java2C(is.ReadFloat());
        y = ParticleUtil::Float_Java2C(is.ReadFloat());
        z = ParticleUtil::Float_Java2C(is.ReadFloat());
    }
    
    inline void Set(float cx, float cy, float cz){
        x = cx;
        y = cy;
        z = cz;
    }
    
    virtual void Set(ValueObject* v){
        x = ((Vector3f*)v)->x;
        y = ((Vector3f*)v)->y;
        z = ((Vector3f*)v)->z;
    }
    
    inline float GetX(){
        return x;
    }
    
    inline float GetY(){
        return y;
    }
    
    inline float GetZ(){
        return z;
    }
    
    inline void SetX(float x){
        this->x = x;
    }
    
    inline void SetY(float y){
        this->y = y;
    }
    
    inline void SetZ(float z){
        this->z = z;
    }
    
    inline void AddLocal(float x, float y, float z){
        this->x += x;
        this->y += y;
        this->z += z;
    }
    
    inline void ScaleLocal(float scale){
        this->x *= scale;
        this->y *= scale;
        this->z *= scale;
    }
    
    inline void DivideLocal(float scalar) {
        scalar = 1.0 / scalar;
        x *= scalar;
        y *= scalar;
        z *= scalar;
    }
    
    virtual void SetMixValue(ValueObject* v1, ValueObject* v2){
        x = ((Vector3f*)v1)->x + ParticleUtil::RandFloat(((Vector3f*)v2)->x) - ((Vector3f*)v2)->x*0.5;
        y = ((Vector3f*)v1)->y + ParticleUtil::RandFloat(((Vector3f*)v2)->y) - ((Vector3f*)v2)->y*0.5;
        z = ((Vector3f*)v1)->z + ParticleUtil::RandFloat(((Vector3f*)v2)->z) - ((Vector3f*)v2)->z*0.5;
    }
    
    //向量长度
    inline float Length() {
        return sqrt(LengthSquared());
    }
       
    inline float LengthSquared() {
        return x * x + y * y + z * z;
    }
    
    inline void NormalizeLocal() {
        float length = Length();
        if (length != 0) {
            DivideLocal(length);
        }
    }
    
    float x;
    float y;
    float z;
};

struct Vector2f
{    
    inline Vector2f(float x=0,float y=0){
        this->x = x; 
        this->y = y;
    };
    inline void Set(float x=0,float y=0){
        this->x = x; 
        this->y = y;
    };
    inline float GetX(){
        return x;
    }
    
    inline float GetY(){
        return y;
    }
    
    inline void SetX(float x){
        this->x = x;
    }
    
    inline void SetY(float y){
        this->y = y;
    }
    
    inline void AddLocal(float x, float y, float z){
        this->x += x;
        this->y += y;
    }
    
    inline void ScaleLocal(float scale){
        this->x *= scale;
        this->y *= scale;
    }
    
    inline void DivideLocal(float scalar) {
        scalar = 1.0 / scalar;
        x *= scalar;
        y *= scalar;
    }
    
    float x;
    float y;
};

// 时间轴数据结构 
class ListObject
{
public:
    ListObject();
    ~ListObject();
public:
	// 设置解析度，30帧/秒 
	int resolution;
	// 该数据列表的开始时间 
	float startTime;
	// 该数据列表的最后时间 
	float lastTime;
    	
	// 在工具中的关键帧数据----------------- 
    std::vector<ValueObject*> values;
    
    // 存储实际的插值 
	std::vector<ValueObject*> array;
	
	void ReadObject(int listType, particle::InputStream& dis);
    
    inline void SetResolution(int resolution){
        this->resolution = resolution;
    }
    
    ValueObject* GetValueAt(float time);
    
    void CreateArray(int listType);//创建插值数组    
    void CreateArrayElements(int listType, std::vector<ValueObject*>& array, ValueObject* current, ValueObject* next);
    FloatValue* CalculateFloatResult(FloatValue* current, FloatValue* next, float dt, float tt);
    ColorValue* CalculateColorResult(ColorValue* current, ColorValue* next, float dt, float tt);
    Vector3f* CalculateVector3fResult(Vector3f* current, Vector3f* next, float dt, float tt);
};

//时间轴数据的基类
class ValueList
{
public:
    enum VALUE_TYPE
    {
        FLOAT_VALUE,
        COLOR_VALUE,
        VECTOR3F_VALUE
    };
public:
    ValueList();
    ~ValueList();
public:
    ListObject* mainValueList; //主数据表 
    ListObject* randomValueList; //时间数据表 
	bool repeat; //当时间超过主时间时 是否重复 
	float bias; //更新数据时的偏移时间 
	bool active; //该属性列表是否激活	 
    bool random; //是否在主数据基础上添加随机数 
    
    //该列表是否属于激活状态------------------ 
	inline bool IsActive() {
		return active;
	}
    
	inline void SetActive(bool active) {
		this->active = active;
	}
	
	//该列表的使用时应偏移时间----------------
	//偏移时间操作
	inline float GetBias() {
		return bias;
	}
    
	inline void SetBias(float bias) {
		this->bias = bias;
	}
    //
    //	//该列表是否使用随机列表----------------
	inline bool IsRandom() {
		return random;
	}
    
	inline void SetRandom(bool random) {
		this->random = random;
	}
	
	// 设置时间超过时是否重复采样----------- 
	inline bool IsRepeat() {
		return repeat;
	}
    
	inline void SetRepeat(bool repeat) {
		this->repeat = repeat;
	}
    
    //获取混合数据
    void GetValueAt(float time, ValueObject& v);
    
    inline void SetResolution(int resolution){
        mainValueList->SetResolution(resolution);
        randomValueList->SetResolution(resolution);
    }

	virtual void ReadList(particle::InputStream& is);
};

class FloatList:public ValueList
{
public:
    FloatList();
    ~FloatList();
public:
    void SetFirstValue(float v);
};

class ColorList:public ValueList
{
public:
    ColorList();    
    ~ColorList();
public:
    void SetFirstValue(float r, float g, float b);
};

class Vector3fList:public ValueList
{
public:
    Vector3fList();
    ~Vector3fList();    
public:
    void SetFirstValue(float x, float y, float z);
};

#endif
