#include "RefCountObject.h"


using namespace Sonicteam::SoX;


void Sonicteam::SoX::RefCountObject::AddReference()
{
	++referenceCount;
}

void Sonicteam::SoX::RefCountObject::Release()
{
	if (--referenceCount == 0) {
		DestroyObject(1);
	}
}

void Sonicteam::SoX::RefCountObject::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}



