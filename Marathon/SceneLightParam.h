#ifndef SONICTEAM__SCENELIGHTPARAM
#define SONICTEAM__SCENELIGHTPARAM


#include <Sox/IResource.h>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <ISceneParam.h>

namespace Sonicteam{




	class SceneLightParam:public Sonicteam::ISceneParam{
	public:

		//? (lost due vft missing, thanks to boost) here a hint to it 825F9770 
		//size == 0x10
		struct AmbientLight{
			XMVECTOR Color; //Vector3
		};
		//size == 0x20
		struct DirectionalLight{
			XMVECTOR Color; //RGB (from [0..1])
			XMVECTOR Direction; //0x10 maybe vector3
			//? others are unknown 
		};

		//later anymouse namespace
		struct CurrentAmbientLight:AmbientLight{
			boost::shared_ptr<AmbientLight> Light0;
			boost::shared_ptr<AmbientLight> Light1;
		};
		struct CurrentDirectionalLightBase{
			char __pading_[0x10]; //0
		};
		struct CurrentDirectionalLight:CurrentDirectionalLightBase,DirectionalLight // (0x10-0x30)
		{
			boost::shared_ptr<DirectionalLight> Light0; //0x30-0x34
			boost::shared_ptr<DirectionalLight> Light1; //0x38-0x3C
			float Time; // Maybe?????
		};





		SceneLightParam();
		~SceneLightParam();
		DESTRUCTION_H;

		size_t unk0x14;
		std::map<std::string,boost::shared_ptr<AmbientLight>> Global; // 0x18  first element is global for for  now
		std::map<std::string,boost::shared_ptr<DirectionalLight>> MainSub; // 0x24  first element is main/sub for for  now
		std::map<std::string,boost::shared_ptr<void*>> unk0x30; // 0x30  probably for animated objets???? or others stuff?
		//unk0x3C
		boost::shared_ptr<SceneLightParam::AmbientLight> _AmbientLight; //0x3c-0x40
		boost::shared_ptr<SceneLightParam::DirectionalLight> _DirectionalLight; //0x44-0x48
		boost::shared_ptr<SceneLightParam::DirectionalLight> _DirectionalLightSub; //0x4C-0x50

		
		//0x54 --data
		//Sonicteam::`anonymous namespace'::CurrentAmbientLight  (no vft) always in edit 
		//Sonicteam::`anonymous namespace'::CurrentAmbientLight  (no vft) always in edit 
		//Sonicteam::`anonymous namespace'::CurrentAmbientLight  (no vft) always in edit 
		//Sonicteam::`anonymous namespace'::CurrentAmbientLight  (no vft) always in edit 


		//CurrentAmbientLight size = 0x24 (why, cuz 825F8B78 )

		std::vector<boost::shared_ptr<CurrentAmbientLight>> _CurrentAmbientLight; // i'll think at least  //0x54

		//0x64 -- data
		//data mixed with sub std::vectors
		//Sonicteam::`anonymous namespace'::CurrentDirectionalLight
		//Sonicteam::`anonymous namespace'::CurrentDirectionalLight

		//CurrentDirectionalLight size = 0x40 (why, cuz  825F8DD0)
		std::vector<std::vector<boost::shared_ptr<CurrentDirectionalLight>>> _CurrentDirectionalLight;//0x64 CurrentDirectionalLight

		LinkSoxNode<int> unk0x74; //no idea


	
	};

};





#endif