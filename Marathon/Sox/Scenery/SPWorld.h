#ifndef SONICTEAM__SOX__SPWORLD
#define SONICTEAM__SOX__SPWORLD
#include "Defs.h"

#include <xtl.h>
#include <Sox/RefCountObject.h>
#include "SPAabbTree.h"

namespace Sonicteam{
	namespace SoX{
		namespace Scenery{


		
			//Missing Base Class, Lost Name
			class SPWorld:public Sonicteam::SoX::RefCountObject{
			public:
				SPWorld();
				~SPWorld();

				unsigned short Flags1;
				unsigned short Flags2;
				XMVECTOR SPWorldVector1; //0x10
				XMVECTOR SPWorldVector2; //0x20
				REF_TYPE(Sonicteam::SoX::Scenery::SPAabbTree) SceneryAabbTree; //0x30
				unsigned int unk0x34;
				unsigned int unk0x38;
				unsigned int unk0x3C;
				//0x40 Size


				virtual void DestroyObject(unsigned int flag) override;

			};



		}
	}
}

#endif