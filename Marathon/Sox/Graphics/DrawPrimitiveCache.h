#ifndef Sonicteam__SOX__Graphics__DRAWPRIMITIVECACHE
#define Sonicteam__SOX__Graphics__DRAWPRIMITIVECACHE


#include "Defs.h"
#include <Sox/RefCountObject.h>
#include <Sox/Misc/Array.h>




namespace Sonicteam{
	namespace SoX{
		namespace Graphics{




			struct PrimitiveCache1_SUB{ //0x8
				float unk0x0;
				float unk0x4;
			};
			struct PrimitiveCache1{ //0x3C
				float unk0x0;
				float unk0x4;
				float unk0x8;
				float unk0xC;
				float unk0x10;
				float unk0x14;
				size_t unk0x18;
				Array<PrimitiveCache1_SUB,2> unk0x1C; //0x20,0x24,0x28,0x2C
				size_t unk0x2C;
				size_t unk0x30;
				size_t unk0x34;
				size_t unk0x38;
			};

	
			//:)
			class DrawPrimitiveCache:public Sonicteam::SoX::RefCountObject //Need Aditional Methods, FullClearLink()
			{

			public:
				DrawPrimitiveCache();
				~DrawPrimitiveCache();
				size_t unk0x8;
				ArrayPtr<Sonicteam::SoX::Graphics::PrimitiveCache1> unk0xC; //0xC-0x10
				ArrayPtr<Sonicteam::SoX::Graphics::PrimitiveCache1> unk0x14; //0x14-0x18
				void* unk0x1C; //0x5DC0
				size_t unk0x20;
				size_t unk0x24;
				size_t unk0x28;
				size_t unk0x2C;
				size_t unk0x30;
				size_t unk0x34;
				size_t unk0x38;
				size_t unk0x3C;
				size_t unk0x40;

				DESTRUCTION_H;
			

		

			};
		};
	}
}

#endif

