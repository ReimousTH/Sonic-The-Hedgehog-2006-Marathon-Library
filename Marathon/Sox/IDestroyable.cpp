#include "RefCountObject.h"


using namespace Sonicteam::SoX;

Sonicteam::SoX::RefCountObject::RefCountObject(void)
{
	this->UnkReference = 0;

}

Sonicteam::SoX::RefCountObject::RefObjectDestroy(unsigned int flag)
{
	this->~RefCountObject();
	if ((flag & 1 ) != 0 ){
		delete this;
	}
}

