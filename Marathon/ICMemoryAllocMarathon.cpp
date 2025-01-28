#include "ICMemoryAllocMarathon.h"


using namespace Sonicteam;


Sonicteam::ICMemoryAllocMarathon::ICMemoryAllocMarathon(void)
{

}

Sonicteam::ICMemoryAllocMarathon::~ICMemoryAllocMarathon(void)
{

}

void Sonicteam::ICMemoryAllocMarathon::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}


//cpp_name, padding can be ignored
void* Sonicteam::ICMemoryAllocMarathon::FAllocMemoryA(size_t size,const char* cpp_name = "ICMemoryAllocMarathon",int padding = 0)
{
	return AllocMemory(size);
}


void* Sonicteam::ICMemoryAllocMarathon::FAllocMemoryB(size_t size)
{
	return AllocMemory(size);
}


void Sonicteam::ICMemoryAllocMarathon::FFreeMemoryA(void* pointer)
{
	FreeMemory(pointer);
}

void Sonicteam::ICMemoryAllocMarathon::FFreeMemoryB(void* pointer)
{
	FreeMemory(pointer);
}
