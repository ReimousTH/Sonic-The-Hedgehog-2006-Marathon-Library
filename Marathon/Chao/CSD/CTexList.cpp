#include "CTexList.h"


using namespace Chao::CSD;


Chao::CSD::CTexList::CTexList(void)
{

}

Chao::CSD::CTexList::~CTexList(void)
{

}

void* Chao::CSD::CTexList::DestroyObject(unsigned int flag)
{
	if ( (flag & 1) != 0){
		Sonicteam::CMemoryAllocMarathon::GetInstance()->FFreeMemoryA((void*)this);
	}
	return this;


}

