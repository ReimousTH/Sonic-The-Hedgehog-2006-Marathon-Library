#ifndef Sonicteam_Prop_ActorCreator
#define Sonicteam_Prop_ActorCreator


#include "PropClass.h"
#include "IActorCreator.h"
#include "Instance.h"
#include "EntityHandle.h"




namespace Sonicteam { namespace Prop {


	
	//0x28
	struct ActorCreatorCreationData{
		ActorCreatorCreationData(REF_TYPE(Sonicteam::Prop::Instance) CreationInstance, REF_TYPE(Sonicteam::Prop::EntityHandle) CreationEntityHandle,unsigned int CreationFlag, std::string CreationName);
		~ActorCreatorCreationData();

		std::string CreationName;
		REF_TYPE(Sonicteam::Prop::Instance) CreationInstance;
		REF_TYPE(Sonicteam::Prop::EntityHandle) CreationEntityHandle;
		unsigned int CreationFlag;
	};



	class ActorCreator:Sonicteam::Prop::IActorCreator{

	public:
		ActorCreator();
		~ActorCreator();

		DESTRUCTION_H override;
		virtual Sonicteam::Actor* CreateActor(Sonicteam::Actor* NamedActor,boost::weak_ptr<Sonicteam::GameImp>* GameImp,void* ObjectCreationData) override;

	};


}};

#endif

