#ifndef SONICTEAM__SOX__SCENERY__WORLD
#define SONICTEAM__SOX__SCENERY__WORLD
#include "Defs.h"


#include <string>
#include <xtl.h>
#include <XboxMath.h>

#include <Sox/RefCountObject.h>
#include <Sox/Scenery/Drawable.h>
#include <Sox/Memory/Destruction.h>
#include <boost/shared_ptr.hpp>

namespace Sonicteam{
	namespace SoX{
		namespace Scenery{


		
			class World{
			public:
				World();
				~World();

				//SizePoint1 - SizePoint2
				XMVECTOR SizePoint1;
				XMVECTOR SizePoint2;
				std::string WorldName;

				DESTRUCTION_H; //0
				virtual bool WorldInitilize() = 0; //  ?
				//Set Camaera To Voxel Space?
				virtual void WorldSetCamera(boost::shared_ptr<Sonicteam::SoX::Scenery::Camera>&) = 0;
				virtual void WorldUnknown02(void*) = 0; //no idea  (void*, either boost ptr, or RefCount or just ref)
				virtual void WorldAddClump(REF_TYPE_REF(Sonicteam::SoX::Scenery::Drawable)) = 0;  // or drawable ,3D, does not add ref
 				virtual void WorldAddDrawable(REF_TYPE_REF(Sonicteam::SoX::Scenery::Drawable)) = 0;   //2D 0x14 does not add ref
				virtual void WorldAddRefCountObj(REF_TYPE_REF(Sonicteam::SoX::Scenery::Drawable)) = 0; //or  //0x18  ,does not add ref
				virtual void WorldUnknown06(void*) = 0;//no idea  (void*, either boost ptr, or RefCount or just ref) 0x1C
				virtual void WorldGetLatestIndex(void*) ; //out,ptr  size 0x20 ;
				virtual void WorldProcessDeltaEx(LARGE_INTEGER*,double) = 0; //use BOTH Deltas(second seems negative ) XD // yes large_integer, i see pointer to PerfomanceFraq, but not dirrect from return register
				virtual void WorldProcessDelta(double*) = 0 ; // size 0x28 ; no idea really

				//Almost Same, Seems Repsend To Same buffer i think
				virtual void WorldProcessUnk0A(Sonicteam::SoX::Scenery::Camera*,unsigned int index1,unsigned int index2) =0; //0x2C
				virtual void WorldProcessUnk0B(unsigned int index1,unsigned int index2) = 0; //0x30

				virtual void WorldProcessUnk0C(void*) =0; // no idea but clearly not boost* or refptr //0x34
				virtual void WorldProcessUnk0B(void*) = 0; // no idea but clearly not boost* or refptr //0x38
				virtual void WorldProcessUnk0D(void*) = 0; // no idea but clearly not boost* or refptr //0x3c
				virtual void WorldProcessUnk0F(void*) = 0; // no idea but clearly not boost* or refptr //0x40
				virtual void WorldProcessUnk10(void*) = 0; // no idea but clearly not boost* or refptr //0x44
				virtual void WorldGetFlag(unsigned int flag_index) = 0; //0x48
				virtual void WorldSetFlag(unsigned int flag_index,unsigned int flag) = 0; //0x4C
				virtual void WorldProcessUnk13() = 0; //0x50
				virtual void WorldProcessUnk14() = 0; //0x54
				virtual REF_TYPE(Sonicteam::SoX::RefCountObject) WorldGetWorldPipelineNormal() = 0; //0x58
				virtual REF_TYPE(Sonicteam::SoX::RefCountObject) WorldGetWorldPipelineTerrain() =0; //0x5C
				virtual void WorldSetWorldPipelineNormal(REF_TYPE(Sonicteam::SoX::RefCountObject)) = 0; //0x60
				virtual void WorldSetWorldPipelineTerrain(REF_TYPE(Sonicteam::SoX::RefCountObject)) = 0; //0x64
				virtual void WorldSetWorldUnk19(REF_TYPE(Sonicteam::SoX::RefCountObject)) = 0; //0x68
				virtual std::string WorldGetName() = 0;
				virtual void WorldSetFlag2(char flag) = 0;
				virtual bool WorldIsUnk1C() = 0;
			};



		}
	}
}

#endif