#ifndef SONICTEAM__HEAP
#define SONICTEAM__HEAP

#include <xtl.h>
#include <Sox/Memory/Destruction.h>
#define SONICTEAM_HEAP_HEAPAREA_MAGIC 0x4C485A49

//no idea about size or type
//0x10




struct _HeapBlock {
	unsigned int Flags;          // 0x00: Flags (e.g., is_free, block_size)
	unsigned int AllocTag;       // 0x04: Allocation tag (for debugging/tracking)
	unsigned int PreviousFree;   // 0x08: Pointer to the previous free block (or metadata)
	_HeapBlock* NextFree;       // 0x0C: Pointer to the next free block
	unsigned int Unused1;          // 0x10: Unused
	unsigned int Unused2;          // 0x14: Unused
	unsigned int Unused3;          // 0x18: Unused
	unsigned int BlockSize;      // 0x1C: Total size of this block (including metadata)
	unsigned int Unused4;          // 0x20: Unused
	unsigned int Unused5;          // 0x24: Unused
	unsigned int Unused6;          // 0x28: Unused
	unsigned int Unused7;          // 0x2C: Unused
};




struct _HeapArea {
	unsigned int Magic;            // 0x00: Magic number (e.g., 0x4C485A49)
	size_t TotalSize;              // 0x04: Total size of the heap
	size_t UsedSize;               // 0x08: Currently used memory
	size_t FreeSize;               // 0x0C: Currently free memory
	unsigned int Alignment;        // 0x10: Alignment requirement for allocations
	_HeapBlock* LastAllocated;    // 0x14: Last block allocated
	_HeapBlock* FreeListHead;      // 0x18: Head of the free block list
	unsigned int AllocListHead;    // 0x1C: Head of the allocated block list
	unsigned int AllocCount;       // 0x20: Number of allocations
	unsigned int FreeBlockCount;   // 0x24: Number of free blocks
	unsigned int AllocatedBlocks;  // 0x28: Number of allocated blocks
	unsigned int Unused1;            // 0x2C: Unused/Reserved
	unsigned int Unused2;
};




//no idea about , size  == 0x1C (void*...) i think or int values
struct _HeapInfo{

};



namespace Sonicteam{
	class __declspec(align(4)) Heap{
	public:
		Heap();
		~Heap();
		DESTRUCTION_H;
		virtual void* HeapAlloc(size_t memsize,void* ptr); // ptr, not used anymore
		virtual void* HeapFree(void* memory,void* pointer = 0); //memory= heapblock? //pointer? not used just used to print debug info     nullsub_1("INFO: pointer is NULL. @ %x.", pointer);    nullsub_1("Illegal free call @ %x.", pointer);
		virtual void HeapInfo(_HeapInfo* outHeapArea,void* pointer); //pointer is obsolete
		virtual _HeapArea* GetHeapArea(void* pointer); //  nullsub_1("Illegal heap area @ %x", pointer); pointer is obsolete
		virtual size_t GetHeapPadding(); //or size?
		virtual bool GetHeapStatus();//
		virtual void* GetHeapStart(void* pointer); // at least i think? pointer= obsolete no way i guessed RIGHT
		virtual void* GetHeapEnd(void* pointer); // at least i think? pointer= obsolete
		virtual _HeapArea* GetHeapArea();
		virtual void* HeapAllocCustom(void* function_1,void* function_2,size_t memsize,void* pointer); //pointer is absolete

		void Sonicteam::Heap::Initialize(SIZE_T HeapSize);


		// Custom new operator (template version)
		template <typename ClassAlloc>
		ClassAlloc* alloc() {
			return new (HeapAlloc(sizeof(Class), 0)) Class();
		};


	private:
		_HeapArea* HeapArea; // HeapArea, (HEADER data = ) (LHZI) 0xC
		unsigned int HeapAreaFlag;
		unsigned int heap_last_rng; //  //   v8 ^= srand_ithink(0xFFu); =  heap_last_rng = v8, durring alloc/dealloc
		char unk0x10;
		char unk0x11;
		size_t HeapPadding; //0x14, or size == 0x20 , why 0x20?, BlockSize?


	};
};



#endif