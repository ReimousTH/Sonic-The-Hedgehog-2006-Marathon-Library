#ifndef Sonicteam__SOX__Graphics__SHADERFXL
#define Sonicteam__SOX__Graphics__SHADERFXL

#include "Defs.h"
#include <Sox/IResource2.h>
#include <Sox/Graphics/Shader.h>




namespace Sonicteam{
	namespace SoX{
		namespace Graphics{
			class ShaderFXL:public Sonicteam::SoX::Graphics::Shader{

				DESTRUCTION_H;

				unsigned int unk0x64; // ?
				unsigned int unk0x68; //?
				unsigned int unk0x6C; //?
				void* unk0x70; // D3D-Resource???
				void* unk0x74; // 
				std::map<void*,void*> unk0x78;  // ShaderPassFXL ???





			};
		};
	};
};
#endif
