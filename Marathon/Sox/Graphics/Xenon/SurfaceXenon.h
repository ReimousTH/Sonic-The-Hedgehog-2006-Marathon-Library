#ifndef Sonicteam__SOX__Graphics__XENON__SURFACEXENON
#define Sonicteam__SOX__Graphics__XENON__SURFACEXENON


#include "Defs.h"
#include <Sox/IResource.h>



namespace Sonicteam{
	namespace SoX{
		namespace Graphics{
			namespace Xenon{
	



				//TODO Original Destructor 
				class SurfaceXenon:public Sonicteam::SoX::IResource //Need Aditional Methods, FullClearLink()
				{

				public:
					SurfaceXenon();
					~SurfaceXenon();

					unsigned int SFlag1; //0x64
					unsigned int SFlag2;  //0x68
					void* unk0x6C; //0x6c
					void* SurfaceRoot; //same as in TextureXenon(look at destructor) 0x70
					unsigned int unk0x74;
					unsigned int unk0x78;
					unsigned int unk0x7C;
					unsigned long long unk0x80;
					//all

					virtual unsigned int GetSFlag1();
					virtual unsigned int GetSFlag2();
					virtual bool IsSurfaceRoot();
					DESTRUCTION_H;
			

				};
			};
		};
	};
};

#endif

