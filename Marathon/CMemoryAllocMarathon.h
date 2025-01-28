	#pragma once
#include <ICMemoryAllocMarathon.h>




namespace Sonicteam{


	 
	//Or SonicTeamSoxComponent
	class CMemoryAllocMarathon:public ICMemoryAllocMarathon
		{

		protected:

			virtual void* AllocMemory(size_t size);
			virtual void FreeMemory(void* pointer);


		public:
			CMemoryAllocMarathon(void);
			~CMemoryAllocMarathon(void);	
			


			static CMemoryAllocMarathon* GetInstance();
			static CMemoryAllocMarathon*& GetInstanceMarathon();



			static CMemoryAllocMarathon* Instance;
			static CMemoryAllocMarathon** InstanceMarathon;
	};
};