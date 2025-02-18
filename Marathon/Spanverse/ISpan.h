#ifndef SONICTEAM__SPANVERSE__ISPAN
#define SONICTEAM__SPANVERSE__ISPAN

#include <Sox/Memory/Destruction.h>
#include "System/CreateStatic.h"
#include "System/Singleton.h"
#include <SpanverseHeap.h>
#include <SpanverseMemory.h>
#include <new>

#define SONICTEAM__SPANVERSE_HEADER__ISPAN 0x42415345

namespace Sonicteam{
	namespace Spanverse{
		class ISpan{
			public:
			ISpan();
			~ISpan();


			unsigned int HEADER; // 0x4  SONICTEAM__SPANVERSE__ISPAN_HEADER
			unsigned int unk0x8; //0x8
			short SpanFlag; //0xC


			static Sonicteam::SpanverseHeap* SpanverseHeapInstance; 



			DESTRUCTION_H;
			
		};
	};
};



#endif