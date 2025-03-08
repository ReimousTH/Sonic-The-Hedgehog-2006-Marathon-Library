#ifndef SONICTEAM__PACKAGEMODEL__ANIMATIONCB
#define SONICTEAM__PACKAGEMODEL__ANIMATIONCB

#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>

namespace Sonicteam{
	namespace Player{
		namespace PackageModel{

			class AnimationCB:public Sonicteam::SoX::RefCountObject{
			public:

				unsigned int unk0x8;
				unsigned int type; //0xC;
				unsigned int value; //0x10 ????

				DESTRUCTION_H;

			};


		};

	}
}




#endif



