#include "CPlatform.h"


using namespace Chao::CSD;


Chao::CSD::CPlatform::CPlatform(void)
{

}

Chao::CSD::CPlatform::~CPlatform(void)
{

}

void Chao::CSD::CPlatform::DestroyObject(unsigned int flag)
{
	if ( (flag & 1) != 0){
		Sonicteam::CMemoryAllocMarathon::GetInstance()->FFreeMemoryA((void*)this);
	}

}
