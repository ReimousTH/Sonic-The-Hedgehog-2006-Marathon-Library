#include "Heap.h"
using namespace Sonicteam;

void Sonicteam::Heap::Initialize(SIZE_T HeapSize) {
	

	this->HeapArea = new _HeapArea();
	this->HeapAreaFlag = 1;

	
	this->HeapArea->Magic = SONICTEAM_HEAP_HEAPAREA_MAGIC; 
	this->HeapArea->TotalSize = 0x1000000; //1MB


	this->HeapArea->UsedSize = 0;     
	this->HeapArea->FreeSize = this->HeapArea->TotalSize; 


	this->HeapArea->Alignment = 0x20;   
	this->HeapArea->LastAllocated = NULL;   
	this->HeapArea->FreeListHead = NULL; 
	this->HeapArea->AllocListHead = 0;   
	this->HeapArea->AllocCount = 0;   
	this->HeapArea->FreeBlockCount = 0;  
	this->HeapArea->AllocatedBlocks = 0; 
	this->HeapArea->Unused1 = 0; 
	this->HeapArea->Unused2 = 0;


	unsigned char* heapMemory = new unsigned char[this->HeapArea->TotalSize];
	memset(heapMemory, 0, this->HeapArea->TotalSize);
	_HeapBlock* initialFreeBlock = reinterpret_cast<_HeapBlock*>(heapMemory);
	initialFreeBlock->Flags = 0;  
	initialFreeBlock->AllocTag = 0;  
	initialFreeBlock->PreviousFree = 0;  
	initialFreeBlock->NextFree = NULL;
	initialFreeBlock->BlockSize = this->HeapArea->TotalSize - sizeof(_HeapBlock);
	this->HeapArea->FreeListHead = initialFreeBlock;
}

Sonicteam::Heap::Heap()
{

}

Sonicteam::Heap::~Heap()
{

}

void* Sonicteam::Heap::HeapAlloc(size_t memsize,void* ptr)
{
	return 0;
}

void* Sonicteam::Heap::HeapFree(void* memory,void* pointer)
{
	return 0;
}

void Sonicteam::Heap::HeapInfo(_HeapInfo* outHeapArea,void* pointer)
{

}

_HeapArea* Sonicteam::Heap::GetHeapArea(void* pointer)
{
	return 0;
}

void* Sonicteam::Heap::HeapAllocCustom(void* function_1,void* function_2,size_t memsize,void* pointer)
{
	return 0;
}

size_t Sonicteam::Heap::GetHeapPadding()
{
	return 0;
}

bool Sonicteam::Heap::GetHeapStatus()
{
	return 0;
}

void* Sonicteam::Heap::GetHeapStart(void* pointer)
{
	return 0;
}

void* Sonicteam::Heap::GetHeapEnd(void* pointer)
{
	return 0;
}

_HeapArea* Sonicteam::Heap::GetHeapArea()
{
	return 0;
}

DESTRUCTION_CPP(Heap);
