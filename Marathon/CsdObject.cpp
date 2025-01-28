#include "CsdObject.h"

void Sonicteam::CsdObject::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);

}

void Sonicteam::CsdObject::CsdLink0x4()
{
}

void Sonicteam::CsdObject::CsdLink0x8(double)
{

}

Sonicteam::CsdObject::~CsdObject(void)
{

}

Sonicteam::CsdObject::CsdObject(void)
{

}

void Sonicteam::CsdObject::CsdObject0x4(unsigned int)
{

}

void Sonicteam::CsdObject::MarathonPlaySceneAnimation(const char* Scene_Name,const char* Animation_Name)
{
	Sonicteam::CsdObject* v = this->GetObject<Sonicteam::CsdObject>();
	((void (__fastcall *)(...))0x824CE670)(&v,Scene_Name,Animation_Name);	
}

void Sonicteam::CsdObject::MarathonStopSceneAnimation(const char* Scene_Name,const char* Animation_Name)
{
	Sonicteam::CsdObject* v = this->GetObject<Sonicteam::CsdObject>();
	((void (__fastcall *)(...))0x824CEFF0)(&v,Scene_Name,Animation_Name);	
}

void Sonicteam::CsdObject::MarathonPlaySceneLoopAnimation(const char* Scene_Name,const char* Animation_Name)
{
	Sonicteam::CsdObject* v = this->GetObject<Sonicteam::CsdObject>();
	((void (__fastcall *)(...))0x824CEE20)(&v,Scene_Name,Animation_Name);
}

void Sonicteam::CsdObject::MarathonStopSceneLoopAnimation(const char* Scene_Name)
{
	Sonicteam::CsdObject* v = this->GetObject<Sonicteam::CsdObject>();
	((void (__fastcall *)(...))0x824CDA90)(&v,Scene_Name);
}

void Sonicteam::CsdObject::MarathonSetSceneNodeText(const char* Scene_Name,const char* Node_Name,const char* value)
{
	Sonicteam::CsdObject* v = this->GetObject<Sonicteam::CsdObject>();
	((void (__fastcall *)(...))0x824CDDF0)(&v,Scene_Name,Node_Name,value);
}

void Sonicteam::CsdObject::MarathonSetSceneNodeSpriteIndex(const char* Scene_Name,const char* Node_Name,int index)
{
	Sonicteam::CsdObject* v = this->GetObject<Sonicteam::CsdObject>();
	((void (__fastcall *)(...))0x824CDCE0)(&v,Scene_Name,Node_Name,index);
}

void Sonicteam::CsdObject::SetFlag0x20(int flag)
{
	this->FCsdObject0x20 = flag;
}
