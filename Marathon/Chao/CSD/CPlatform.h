#pragma once

#include <xtl.h>
#include <CMemoryAllocMarathon.h>





namespace Chao{
	namespace CSD{


	 
	//Or SonicTeamSoxComponent
	class CPlatform
		{
		public:
			CPlatform(void);
			~CPlatform(void);


		public:
			virtual void DestroyObject(unsigned int flag); //0x0 + 0x10
			virtual void DebugMessageA(LPCSTR  lpOutputString) = 0;
			virtual int GetCPlatform0x4() = 0;
			virtual void CPDrawPrimiteCache0x8(unsigned int) = 0;
			
			virtual void CPSSetDrawPrimiteFlag0xC(unsigned int) = 0;
			virtual void CPlatform0x10(unsigned int, unsigned int) = 0; 
			virtual void CPlatform0x14() = 0; 

			virtual void CPSSetDrawPrimiteFlagA0x18(unsigned int) = 0;  
			virtual void CPlatform0x1C(unsigned int, unsigned int) = 0; 
			virtual void CPlatform0x20() = 0; // -> CPlatform0x14 ??? 
			virtual void CPDrawPrimiteCache0x24() = 0; // no args
			virtual void CPDrawPrimiteCache0x28() = 0; // no args
		


	


	};
};
};