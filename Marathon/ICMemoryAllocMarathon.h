#pragma once

#include <sox/Memory/IDestructible.h>





namespace Sonicteam{


	 
	//Or SonicTeamSoxComponent
	class ICMemoryAllocMarathon
		{
		public:
			ICMemoryAllocMarathon(void);
			~ICMemoryAllocMarathon(void);

	
			virtual void DestroyObject(unsigned int flag); //0x0 + 0x10
			
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


	};
};