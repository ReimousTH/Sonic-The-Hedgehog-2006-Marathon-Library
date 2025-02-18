#ifndef SONICTEAM__SPANVERSE__SPANSPCM
#define SONICTEAM__SPANVERSE__SPANSPCM


#include <Spanverse/ISpan.h>

#define SONICTEAM__SPANVERSE_HEADER__SPANSPCM 0x5350434D

namespace Sonicteam{
	namespace Spanverse{
		class SpanSPCM:Sonicteam::Spanverse::ISpan{
			public:
			SpanSPCM();
			~SpanSPCM();

			XMMATRIX Transform; //0x10
			XMFLOAT3 Vector1; //0x50
			XMFLOAT3 Vector2; //0x60
			XMFLOAT3 Vector3; //0x70

			unsigned int unk0x80; //0x80
			unsigned int unk0x84; //0x80 0x1FFE;
			float unk0x88; // = 1.0;
			float unk0x8C; // 10000.0;
			unsigned int unk0x90;
			unsigned int unk0x94;
			unsigned int unk0x98;
			unsigned int unk0x9C;


			DESTRUCTION_H;
			
		};
	};
};



#endif