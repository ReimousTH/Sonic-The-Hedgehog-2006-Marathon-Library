#include "AllocatedData.h"

void Sonicteam::Prop::AllocatedData::DestroyObject(unsigned int flag)
{
	Sonicteam::Prop::AllocatedData::~AllocatedData();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);

}

Sonicteam::Prop::AllocatedData::AllocatedData()
{

}

Sonicteam::Prop::AllocatedData::~AllocatedData()
{

}
