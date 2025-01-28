#include "Instance.h"


Sonicteam::Prop::Instance::Instance()
{

}

Sonicteam::Prop::Instance::~Instance()
{

}

void Sonicteam::Prop::Instance::DestroyObject(unsigned int flag)
{

}

void Sonicteam::Prop::InstanceSetDataParams::SetTValue(bool value)
{
	this->Type = 0;
	this->Value._bool_ = value;
}

Sonicteam::Prop::InstanceSetDataParams::~InstanceSetDataParams()
{
	if (this->Type == 3 && this->Value._string_ != 0){
		delete this->Value._string_;
	}
}

void Sonicteam::Prop::InstanceSetDataParams::SetTValue(int value)
{
	this->Type = 1;
	this->Value._int32_ = value;
}

void Sonicteam::Prop::InstanceSetDataParams::SetTValue(float value)
{
	this->Type = 2;
	this->Value._single_ = value;
}

void Sonicteam::Prop::InstanceSetDataParams::SetTValue(const char* value)
{
	this->Type = 3;
	this->Value._string_ = new char[strlen(value) + 1];
	strcpy((char*)this->Value._string_,value);
}

void Sonicteam::Prop::InstanceSetDataParams::SetTValue(XMVECTOR value)
{
	this->Type = 4;
	*(XMVECTOR*)&this->Value._vector_ = value;
}





Sonicteam::Prop::InstanceSetData::InstanceSetData(const char* ObjectName,const char* ObjectTypeName,XMVECTOR Position,XMVECTOR Rotation)
{
	this->ObjectName = new char[strlen(ObjectName) + 1]; 
	this->ObjectTypeName = new char[strlen(ObjectTypeName) + 1];
	strcpy((char*)this->ObjectName, ObjectName);
	strcpy((char*)this->ObjectTypeName, ObjectTypeName);
	this->Position.x = Position.x;
	this->Position.y = Position.y;
	this->Position.z = Position.z;


	this->Rotation.x = Rotation.x;
	this->Rotation.y = Rotation.y;
	this->Rotation.z = Rotation.z;
	this->Rotation.w = Rotation.w;


	
}

Sonicteam::Prop::InstanceSetData::~InstanceSetData()
{
	if (ObjectName) delete ObjectName;
	if (ObjectTypeName) delete ObjectTypeName;
	if (Params) delete Params;
}
