#ifndef SONICTEAM__KHRONOCONTROLLER
#define SONICTEAM__KHRONOCONTROLLER


#include <Defs.h>
#include <string>
#include <deque>

#include <Sox/Graphics/Defs.h>


namespace Sonicteam{




	class SceneParamManager{

	public:
		SceneParamManager(Sonicteam::DocMarathonImp*); //no idea THRERE TWO OF THEM
		~SceneParamManager();


		DESTRUCTION_H;
		Sonicteam::DocMarathonImp* doc; //4
		std::map<std::string,REF_TYPE(Sonicteam::ISceneParam)> SceneParams; //0x8 + 0xC
		std::deque<REF_TYPE(Sonicteam::ISceneParam)> SceneParamsQueue; //0x14 + 0x10


		size_t unk0x24;
		Sonicteam::SoX::Graphics::TechniqueFXL ShaderTechnique;
		std::string scene_stage; //0x2C //scripts/stage/kdv/scene_kdv_a.lua





		


	};

};




#endif