


#ifndef Sonicteam_Prop_Scene
#define Sonicteam_Prop_Scene


#include "PropClass.h"
#include "Manager.h"
#include "Instance.h"
#include "Group.h"
#include "SceneData.h"
#include "EntityHandle.h"

#include <Sox/Misc/LinkSoxNode.h>
#include <boost/shared_ptr.hpp>
#include <string>
#include <map>
#include <vector>
#include <Actor.h>

namespace Sonicteam { namespace Prop {





	struct SceneActor{
		unsigned int Flag1;
		unsigned int Flag2;
		Sonicteam::Prop::EntityHandle* ObjActorHandle; // Sonicteam::Prop::EntityHandle
		Sonicteam::Actor* ObjActor; // Sonicteam::Actor | Sonicteam::Fixture | Sonicteam::PropFixture 
	};
	
	class Scene{


	public:
		Scene();
		~Scene();

		Sonicteam::Prop::Manager* PropManager; //0x0
		LinkSoxNode<Scene> LinkScene1; //0x4-0xC (Other Scenes)
		LinkSoxNode<Scene> LinkScene2; //0x10-0x18 (May linked to Head Somewhere, to iterrate )
		REF_TYPE(Sonicteam::Prop::SceneData)* ScenePropData; // Sonicteam::Prop::SceneData: //0x1C
		unsigned int ScenePropFile; // Pointer to .set file in memory  (right after BBINA padded 0x10) //0x20
		REF_TYPE(Sonicteam::Prop::AllocatedData) ScenePropAllocatedData; // Sonicteam::Prop::AllocatedData //0x24
		std::vector<REF_TYPE(Sonicteam::Prop::Instance)> ScenePropInstance; // Sonicteam::Prop::Instance //0x28
		std::vector<Sonicteam::Prop::Group*> ScenePropGroup;  // Sonicteam::Prop::Group //0x38

		//seems, ObjName to ID ?
		std::map<std::string,int> ScenePlacament; // ?? // 82619550, either std::map or std::set :no idea //0x48, second unknown for now (825BCBF8) (yes it int or 4 byte value)
		std::map<std::string,int> ScenePlacamentGroup; // ?? // 82619550, either std::map or std::set :no idea //0x54 

		//0x60

		std::vector<std::string> SceneRegObjectTypeName;  //0x60 
		std::vector<SceneActor> SceneObject; // 0x70  depends On Render, means some req
		std::vector<unsigned int> unk0x80; // Pre-Alloc,   ScenePropFile  + 0x34 -> some_count ? groups?
		unsigned int unk0x90;
		unsigned int unk0x94;
		unsigned int unk0x98;
		unsigned int unk0x9C;

		unsigned int unk0xA0; //RefCountObject Already




		//0xA4 - Last
	


	};

}}

#endif