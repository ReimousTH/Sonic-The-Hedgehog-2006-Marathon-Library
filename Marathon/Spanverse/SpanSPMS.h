#ifndef SONICTEAM__SPANVERSE__SPANSPMS
#define SONICTEAM__SPANVERSE__SPANSPMS

#include <Sox/Memory/Destruction.h>
#include <Spanverse/ISpan.h>


#define SONICTEAM__SPANVERSE_HEADER__SPANSPMS 0x53504D53

namespace Sonicteam{
	namespace Spanverse{
		class SpanSPMS:Sonicteam::Spanverse::ISpan{
			public:
			SpanSPMS(size_t TransformAllocCount);
			~SpanSPMS();

			XMMATRIX* TransformFirst; //0x10
			XMMATRIX* TransformLast; //0x14
			XMMATRIX* TransformEnd; //0x18
			size_t TransformCount; //0x1C



			DESTRUCTION_H;
			
		};
	};
};



#endif