#ifndef SONICTEAM__SPANVERSE__ISPAN
#define SONICTEAM__SPANVERSE__ISPAN


#include <Spanverse/Defs.h>
#include <Sox/Memory/Destruction.h>
#include <SpanverseHeap.h>
#include <SpanverseMemory.h>




#include <new>
#include <map>
#include "ISpan.h"

//#include <Spanverse/Env.h>



namespace Sonicteam{
	namespace Spanverse{
		class AcroartsPostLoad{
			public:
			AcroartsPostLoad();
			~AcroartsPostLoad();

			std::map<void*,void*> AcroartsMap; //0x0
//			Sonicteam::Spanverse::Env* Env; //0xC
			unsigned int unk0x10; //? 
			unsigned int unk0x14; //?
			//REF_TYPE
//			Sonicteam::Spanverse::SpanSSGS* SpanSSGS; //0x18
//			Sonicteam::Spanverse::SpanSSES* SpanSSES; //0x1C
			//?



			DESTRUCTION_H;
			
		};
	};
};



#endif