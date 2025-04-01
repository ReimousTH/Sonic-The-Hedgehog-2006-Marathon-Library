#include "CMemoryAlloc.h"


using namespace Chao::CSD;

CMemoryAlloc::CMemoryAlloc()
{

}

CMemoryAlloc::~CMemoryAlloc()
{

}

void* CMemoryAlloc::AllocMemory(size_t size)
{
	return ::operator new(size);
}

void CMemoryAlloc::FreeMemory(void* pointer)
{
	return ::operator delete(pointer);
}

void* CMemoryAlloc::FAllocMemoryA(size_t size,const char* cpp_name,int padding)
{
	return AllocMemory(size);
}

void CMemoryAlloc::FFreeMemoryA(void* pointer)
{
	FreeMemory(pointer);
}

void* CMemoryAlloc::FAllocMemoryB(size_t size)
{
	return AllocMemory(size);
}

void CMemoryAlloc::FFreeMemoryB(void* pointer)
{
	FreeMemory(pointer);
}

Chao::CSD::CMemoryAlloc* Chao::CSD::CMemoryAlloc::m_instance = 0;
