


#ifndef Sonicteam_Prop_SceneData
#define Sonicteam_Prop_SceneData



#include <Sox/IResource.h>
#include <Sox/Misc/LinkSoxNode.h>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include "ClassRegistry.h"
#include "AllocatedData.h"





namespace Sonicteam { namespace Prop {



	class SceneData:Sonicteam::SoX::IResource{


	public:
		SceneData();
		~SceneData();

		void* File; // (right after BBINA) 0x64
		Sonicteam::Prop::AllocatedData* AllocatedData; //0x68
		LinkSoxNode<Sonicteam::Prop::Scene> LinkScene; //0x6C - 0x74
		boost::weak_ptr<Sonicteam::Prop::ClassRegistry> ClassRegistry; //0x78 - 0x7C
		//0x80

		virtual void DestroyObject(unsigned int flag) override;

	};

}}

#endif

