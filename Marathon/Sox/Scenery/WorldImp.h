#ifndef SONICTEAM__SOX__SPWORLD
#define SONICTEAM__SOX__SPWORLD
#include "Defs.h"

#include <vector>
#include <Sox/Scenery/World.h>
#include <Sox/RefCountObject.h>
#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/RefCountObject.h>


namespace Sonicteam{
	namespace SoX{
		namespace Scenery{


		
			//Missing Base Class, Lost Name
			class WorldImp:Sonicteam::SoX::Scenery::World{
			public:
				WorldImp();
				~WorldImp();

				char WorldImpFlag; //4c
				unsigned int WorldImpTick; // 50
				LinkSoxNode<Sonicteam::SoX::Scenery::Camera> LinkCamera; //0x54,0x58,0x5C
				LinkSoxNode<void*> LinkVoid; // no idea about type //0x60,0x64,0x68
				LinkSoxNode<Sonicteam::SoX::Scenery::Drawable> LinkDrawable; // 0x6C,0x70,0x74
				LinkSoxNode<void*> LinkVoid2; //0x78,0x7C,0x80
				LinkSoxNode<void*> LinkVoid3; //0x84,0x88,0x8C
				LinkSoxNode<Sonicteam::SoX::Scenery::TerrainNode> LinkTerrain; //0x90,0x94,0x98
				LinkSoxNode<void*> LinkVoid4; //0x9C,0x0xA0,0xA4

				REF_TYPE(Sonicteam::SoX::RefCountObject) WorldPipeLineNormal; //0xA8
				REF_TYPE(Sonicteam::SoX::RefCountObject) TerrainPipeLineNormal; //0xAC
				REF_TYPE(Sonicteam::SoX::RefCountObject) WorldVoxelSpace; //0xB0 Sonicteam::SoX::Scenery::VoxelSpace

				unsigned int WorldUnk0xB4;
				unsigned int WorldUnk0xB8;
				unsigned int WorldUnk0xBC;
				unsigned int WorldUnk0xD0;
				unsigned int WorldUnk0xD4;
				unsigned int WorldUnk0xD8;
				unsigned int WorldUnk0xDC;
				unsigned int WorldUnk0xE0;
				unsigned int WorldUnk0xE4;
				unsigned int WorldUnk0xE8;
				unsigned int WorldUnk0xEC;
				unsigned int WorldUnk0xF0;
				unsigned int WorldUnk0xF4;
				unsigned int WorldUnk0xF8;
				unsigned int WorldUnk0xFC;
				unsigned int WorldUnk0x100;
				unsigned int WorldUnk0x104;
				unsigned int WorldUnk0x108;

				std::vector<REF_TYPE(Sonicteam::SoX::Scenery::Drawable)> DrawableFirst; //0x10C
				std::vector<REF_TYPE(Sonicteam::SoX::Scenery::Drawable)> DrawableSecond; //0x11C
				std::vector<REF_TYPE(Sonicteam::SoX::Scenery::Drawable)> DrawableThird; //0x12C

				unsigned int WorldUnk0x13C; //Flag?
				unsigned int WorldUnk0x140; //
				unsigned int WorldUnk0x144; //
				 
				std::vector<boost::shared_ptr<Sonicteam::SoX::Scenery::CullingInformation>> WorldCullingInformation; //0x148
				std::vector<unsigned int> WorldCullingInformationFlag; //0x158
				unsigned int WorldUnk0x168;
				unsigned int WorldUnk0x16C; //end
	
			





				DESTRUCTION_H;

			};



		}
	}
}

#endif