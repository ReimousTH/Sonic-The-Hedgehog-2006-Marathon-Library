#ifndef CHAOS__CSD__CMEMORYALLOC
#define CHAOS__CSD__CMEMORYALLOC


#include <Chao/Misc/Destruction.hpp> //Base Destruction
#include <Chao/CSD/Defs.h>





//Allocation definitions
#define CMInstanceSET(ptr) Chao::CSD::CMemoryAlloc::m_instance = (Chao::CSD::CMemoryAlloc*)ptr
#define CMInstance (Chao::CSD::CMemoryAlloc::m_instance)
#define CMAllocator CMInstance->FAllocMemoryA
#define CMDeAllocator CMInstance->FFreeMemoryA
#define CMAlloc(size,cpp_name,padding) CMAllocator(size,cpp_name,padding)
#define CMFree(pointer) CMDeAllocator(pointer)

//operators (need to test)
#define CMNEWEX(Class,cpp_file,line,...) new (CMAlloc(sizeof(Class))) Class(__VA_ARGS__)


#define CMNEW(Class, ...) \
	CMNEWEX(Class, __FILE__, __LINE__, ##__VA_ARGS__)


//Forward objects Alloc/Dealloc
#define CMADestuctionBaseHPP(cname) CDESTRUCTION_HPP_EX(cname,::operator delete)
#define CMADestuctionHPP(cname) CDESTRUCTION_HPP_EX(cname,CMDeAllocator)



namespace Chao{
	namespace CSD{

		
		class CMemoryAlloc{

		public:

			CMemoryAlloc();
			~CMemoryAlloc();
			CMADestuctionBaseHPP(CMemoryAlloc);

		protected:
			//Void
			virtual void* AllocMemory(size_t size) = 0;
			virtual void FreeMemory(void* pointer) = 0;


		public:
			//more like template to call Alloc,Free
			virtual void* FAllocMemoryA(size_t size,const char* cpp_name,int padding); // "C++ file,padding?, not need because new[] 100% ir"
			virtual void FFreeMemoryA(void* pointer);

			//more like template to call Alloc,Free, yea once more
			virtual void* FAllocMemoryB(size_t size);
			virtual void FFreeMemoryB(void* pointer);

		//Instance
			static CMemoryAlloc* m_instance;

		};


	};
};


#endif

