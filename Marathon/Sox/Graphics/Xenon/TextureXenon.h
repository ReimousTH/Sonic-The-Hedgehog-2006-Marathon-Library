#ifndef Sonicteam__SOX__Graphics__XENON__TEXTUREXENON
#define Sonicteam__SOX__Graphics__XENON__TEXTUREXENON


#include "Defs.h"
#include <Sox/Graphics/Device.h>
#include <Sox/IResource.h>
#include <Sox/Misc/Array.h>
#include <Sox/Graphics/Xenon/SurfaceXenon.h>

namespace Sonicteam{
	namespace SoX{
		namespace Graphics{
			namespace Xenon{
	



				//TODO Original Destructor 
				class TextureXenon:public Sonicteam::SoX::IResource //Need Aditional Methods, FullClearLink()
				{

				public:
					TextureXenon();
					~TextureXenon();
					void* SurfaceRoot; //0x64 -- class data :) (no idea), i think helper or root data 
					Array<Sonicteam::SoX::Graphics::Xenon::SurfaceXenon*,6> Surface; //0x68
					unsigned int TFlag1;
					unsigned int TFlag2;
					Sonicteam::SoX::Graphics::Device* GDevice; //0x88
					//end
 

					virtual unsigned int GetTXFlag1();
					virtual unsigned int GetTXFlag2();

					virtual REF_TYPE(Sonicteam::SoX::Graphics::Xenon::SurfaceXenon) GetSurface(unsigned int index);
					virtual bool GetSurfaceRoot(void* out1,void* out2); 
					virtual void ProcessSurfaceRoot(unsigned int flag);
					virtual REF_TYPE(Sonicteam::SoX::Graphics::Xenon::TextureXenon) LoadTexture(std::string& textype); //depthstenic_texture
					DESTRUCTION_H;
				};
			};
		};
	}
};

#endif

