#ifndef SONICTEAM__ISCENELIGHTPARAM
#define SONICTEAM__ISCENELIGHTPARAM


#include <Sox/RefCountObject.h>
#include <Sox/Misc/LinkSoxNode.h>
#include <Defs.h>
#include <Sox/Graphics/Defs.h>

#define ISPApplyArg1 Sonicteam::ISPApplyArg
#define ISPApplySPArg1 Sonicteam::ISPApplySPArg

namespace Sonicteam{



	struct ISPApplyArg{
		Sonicteam::DocMarathonImp* doc;
		Sonicteam::SoX::Graphics::Device* device; //my_graphic device
	};

	struct ISPApplySPArg{
		Sonicteam::SceneParamManager* scene_param_manager; //0
		Sonicteam::DocMarathonImp* doc; //4
		Sonicteam::LuaSystem* scene_file_lua; //scripts/stage/wvo/scene_wvo_a
		void* game_mode; // Sonicteam::MainMode
	};

	class ISceneParam:public Sonicteam::SoX::RefCountObject{
	public:
		ISceneParam();
		~ISceneParam();
		LinkSoxNode<void*> LinkArray; //not same class cuz not point to himself
		//0x14 ...

		DESTRUCTION_H;
		virtual const char* GetParamName() = 0;
		virtual void InitializeSceneParam(ISPApplySPArg1 for_now);
		virtual void SceneParamUpdate(double delta);
		virtual void ApplySceneParam(ISPApplyArg1);
	};

};





#endif