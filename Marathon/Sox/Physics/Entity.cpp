#include "Entity.h"


using namespace Sonicteam::SoX::Physics;


int Sonicteam::SoX::Physics::Entity::OnMessageRecieved(SoXMessageType)
{
	return 0;	
}




Sonicteam::SoX::Physics::Entity::Entity(unsigned int EntityFlag,Sonicteam::SoX::MessageReceiver* EntityReceiver):
EntityFlag(EntityFlag),
EntityReceiver(EntityReceiver)
{

}

Sonicteam::SoX::Physics::Entity::~Entity(void)
{

}
DESTRUCTION_CPP(Entity);