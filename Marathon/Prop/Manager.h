

#ifndef Sonicteam_Prop_Manager
#define Sonicteam_Prop_Manager


#include "PropClass.h"
#include "Scene.h"
#include "GenerateArea.h"
#include "ClassRegistry.h"


#include <map>
#include <Sox/Misc/LinkSoxNode.h>
#include <vector>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>


namespace Sonicteam { class GameImp; namespace Prop {


	//0x4C
	class Manager{

		friend class GenerateArea;
		friend class Scene;

	public:

		Manager();
		~Manager();

		Sonicteam::GameImp* GameImpulse; //0x0
		char Flag1;
		char Flag2; //pad?
		char Flag3; //pad?
		char Flag4; //pad?
		LinkSoxNode<int> NodeLink; // 0x8-0x10, No iDea
		LinkSoxNode<Sonicteam::Prop::GenerateArea> GenerateAreaLink; // 0x14-0x1C
		std::vector<boost::weak_ptr<Sonicteam::Prop::Scene>> ManagerPropScenes; // ?? unknown typwe //0x20-0x2C // Sonicteam::Prop::Scene //0x20 , why weak_ptr cuz  //824618AC
		std::map<std::string,int> unk0x30; //unsigned int* type_82619550; // 82619550 (unnamed-types) template seems because 824BAFE0 (std::list ???) cuz 823EB2C0 //0x30
		boost::weak_ptr<Sonicteam::Prop::ActorCreators> ActorCreators; // boost::shared_ptr<Sonicteam::Prop::ActorCreators> //0x3C-0x40
		boost::shared_ptr<Sonicteam::Prop::ClassRegistry> PropClassRegistry; // boost::shared_ptr<Sonicteam::Prop::ClassRegistry> //0x44-0x48


	};

}}

#endif


