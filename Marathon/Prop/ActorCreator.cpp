#include "ActorCreator.h"


void Sonicteam::Prop::ActorCreator::DestroyObject(unsigned int flag)
{
	
}

Sonicteam::Actor* Sonicteam::Prop::ActorCreator::CreateActor(Sonicteam::Actor* NamedActor,boost::weak_ptr<Sonicteam::GameImp>* GameImp,void* ObjectCreationData)
{
	return 0;
}


Sonicteam::Prop::ActorCreatorCreationData::ActorCreatorCreationData(REF_TYPE(Sonicteam::Prop::Instance) CreationInstance, REF_TYPE(Sonicteam::Prop::EntityHandle) CreationEntityHandle,unsigned int CreationFlag, std::string CreationName):
CreationInstance(CreationInstance),
CreationEntityHandle(CreationEntityHandle),
CreationFlag(CreationFlag),
CreationName(CreationName)
{

}


Sonicteam::Prop::ActorCreatorCreationData::~ActorCreatorCreationData()
{

}
