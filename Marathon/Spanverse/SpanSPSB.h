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
			Sonicteam::Spanverse::SpanSPMS* SpanSPMS; //0x10
			Sonicteam::Spanverse::SpanSPCM* SpanSPCM; //0x14
			unsigned int unk0x18; //0x18
			unsigned int unk0x1C; //0x1c
			unsigned int unk0x20; //0x20
			unsigned int unk0x24; //0x24
			unsigned int count2; //0x28
			void* array2; // 0x2C size 0x50
			XMVECTOR Vector0x30; //0x30
			XMVECTOR Vector0x40; //0x40
			unsigned int unk0x50; //0x50 400?
			unsigned int unk0x54; //0x54 300?
			unsigned int unk0x58; //0x58 
			unsigned int unk0x5C; //0x5C
			XMMATRIX Transform; //0x60




			DESTRUCTION_H;
			
		};
	};
};



#endif