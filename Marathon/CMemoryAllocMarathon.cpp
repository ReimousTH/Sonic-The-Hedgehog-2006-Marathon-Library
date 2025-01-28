#include "CMemoryAllocMarathon.h"


using namespace Sonicteam;




void* Sonicteam::CMemoryAllocMarathon::AllocMemory(size_t size)
{
	
	return operator new[](size);
}

void Sonicteam::CMemoryAllocMarathon::FreeMemory(void* pointer)
{
	return operator delete(pointer);
}	

Sonicteam::CMemoryAllocMarathon::CMemoryAllocMarathon(void)
{
	if (!CMemoryAllocMarathon::Instance){
		CMemoryAllocMarathon::Instance = this;
	}
}

//not complete
Sonicteam::CMemoryAllocMarathon::~CMemoryAllocMarathon(void)
{

}



CMemoryAllocMarathon* Sonicteam::CMemoryAllocMarathon::GetInstance()
{
	
	if (!CMemoryAllocMarathon::Instance){

		CMemoryAllocMarathon::Instance = new CMemoryAllocMarathon();
	}
	return CMemoryAllocMarathon::Instance;
	
}

CMemoryAllocMarathon*& Sonicteam::CMemoryAllocMarathon::GetInstanceMarathon()
{
	return *InstanceMarathon;
}

CMemoryAllocMarathon* Sonicteam::CMemoryAllocMarathon::Instance;
CMemoryAllocMarathon** Sonicteam::CMemoryAllocMarathon::InstanceMarathon;

