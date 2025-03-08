#ifndef Sonicteam__SOX__Graphics__SAMPLERCOMMON
#define Sonicteam__SOX__Graphics__SAMPLERCOMMON



#include "Defs.h"
#include <Sox/IResource.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/Graphics/Xenon/TextureXenon.h>



namespace Sonicteam{
	namespace SoX{
		namespace Graphics{


	
			//:)
			class SamplerCommon:public Sonicteam::SoX::IResource //Need Aditional Methods, FullClearLink()
			{

			public:
				SamplerCommon();
				~SamplerCommon();
				REF_TYPE(Sonicteam::SoX::Graphics::Xenon::TextureXenon) Texture; //0
				size_t size1; //4
				size_t size2; //8
				size_t size3; //C
				const char* texstr; //10
				void* cdata;//14 no idea
				///size == 0x18

		

			};
		};
	}
}

#endif

