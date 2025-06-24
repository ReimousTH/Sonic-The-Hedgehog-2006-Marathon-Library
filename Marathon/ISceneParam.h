#ifndef SONICTEAM__ISCENELIGHTPARAM
#define SONICTEAM__ISCENELIGHTPARAM


#include <Sox/RefCountObject.h>
#include <Sox/Misc/LinkSoxNode.h>

namespace Sonicteam{




	class ISceneParam:public Sonicteam::SoX::RefCountObject{
	public:
		ISceneParam();
		~ISceneParam();
		LinkSoxNode<void*> LinkArray; //not same class cuz not point to himself
		size_t unk0x14; //ID kindof?


		DESTRUCTION_H;
	};

};





#endif