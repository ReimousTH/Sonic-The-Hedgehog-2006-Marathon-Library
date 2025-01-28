#include "Class.h"

void Sonicteam::Prop::Class::DestroyObject(unsigned int flag)
{
	Sonicteam::Prop::Class::~Class();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);

}

Sonicteam::Prop::Class::~Class()
{

}

Sonicteam::Prop::Class::Class(ClassPropParamData* ClassPropData,REF_TYPE(Sonicteam::Prop::AllocatedData) ClassPropAllocatedData):
ClassPropData(ClassPropData),
ClassPropAllocatedData(ClassPropAllocatedData)
{

}
