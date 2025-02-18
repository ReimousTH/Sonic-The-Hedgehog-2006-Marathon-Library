#ifndef SONICTEAM__SPANVERSE__SPANSPSP
#define SONICTEAM__SPANVERSE__SPANSPSP


#include <Spanverse/ISpan.h>
#include <Spanverse/SpanSPMS.h>
#include <Spanverse/SpanSPCM.h>

#define SONICTEAM__SPANVERSE_HEADER__SPANSPSB 0x53505342;

namespace Sonicteam{
	namespace Spanverse{
		class SpanSPSB:Sonicteam::Spanverse::ISpan{
			public:
			SpanSPSB(size_t count1,size_t count2);
			~SpanSPSB();
			Sonicteam::Spanverse::SpanSPMS* SpanSPMS;
			Sonicteam::Spanverse::SpanSPCM* SpanSPCM;




			DESTRUCTION_H;
			
		};
	};
};



#endif