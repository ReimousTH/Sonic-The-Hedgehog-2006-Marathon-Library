#ifndef CHAO__CSD__CPLATFORM
#define CHAO__CSD__CPLATFORM



#include <Chao/Misc/API_DEFS.h>
#include <Chao/CSD/Defs.h>
#include <Chao/CSD/CMemoryAlloc.h>
#include <Chao/CSD/CBase.h>

//Defs
#define CPInstance (Chao::CSD::CPlatform::m_instance)
#define CPInstanceSET(ptr) Chao::CSD::CPlatform::m_instance = (Chao::CSD::CPlatform*)ptr
#define CPDebugMessageA(message) CPInstance->DebugMessageA(message)


namespace Chao{
	namespace CSD{



		//Or SonicTeamSoxComponent
		class CPlatform:Chao::CSD::CBase
		{
		public:
			CPlatform(void);
			~CPlatform(void);


		public:
			CMADestuctionHPP(CPlatform);

			virtual void DebugMessageA(LPCSTR  lpOutputString) = 0;
			virtual int GetCPlatform0x4() = 0;
			virtual void CPDrawPrimiteCache0x8(unsigned int) = 0;

			virtual void CPSSetDrawPrimiteFlag0xC(unsigned int) = 0;
			virtual void CPlatformDrawBase(unsigned int, unsigned int) = 0; 
			virtual void CPlatform0x14() = 0; 

			virtual void CPSSetDrawPrimiteFlagA0x18(unsigned int) = 0;  
			virtual void CPlatform0x1C(unsigned int, unsigned int) = 0; 
			virtual void CPlatform0x20() = 0; // -> CPlatform0x14 ??? 
			virtual void CPDrawPrimiteCache0x24() = 0; // no args
			virtual void CPDrawPrimiteCache0x28() = 0; // no args

			static CPlatform* m_instance;






		};
	};
};
#endif