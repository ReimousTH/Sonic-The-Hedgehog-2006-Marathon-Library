#include "RefCountObject.h"


using namespace Sonicteam::SoX;


void Sonicteam::SoX::RefCountObject::AddReference()
{
	++referenceCount;
}

void Sonicteam::SoX::RefCountObject::Release()
{
	if (--referenceCount == 0) {
		this->DestroyObject(1);
	}
}

DESTRUCTION_CPP(RefCountObject);


