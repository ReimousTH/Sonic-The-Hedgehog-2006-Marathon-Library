#ifndef SONICTEAM__ISCENELIGHTPARAM
#define SONICTEAM__ISCENELIGHTPARAM


#include <Sox/RefCountObject.h>
#include <Sox/Misc/LinkSoxNode.h>
#include <Defs.h>

#define ISPApplyArg1 Sonicteam::ISPApplyArg

namespace Sonicteam{



	struct ISPApplyArg{
		Sonicteam::DocMarathonImp* doc;
		Sonicteam::SoX::Graphics::Device* device; //my_graphic device
	};

	class ISceneParam:public Sonicteam::SoX::RefCountObject{
	public:
		ISceneParam();
		~ISceneParam();
		LinkSoxNode<void*> LinkArray; //not same class cuz not point to himself
		size_t unk0x14; //ID kindof?


		DESTRUCTION_H;
		virtual const char* GetParamName() = 0;
		virtual void InitializeSceneParam(void* for_now);
		virtual void ISceneParam0xC();
		virtual void ApplySceneParam(ISPApplyArg1);
	};

};





#endif