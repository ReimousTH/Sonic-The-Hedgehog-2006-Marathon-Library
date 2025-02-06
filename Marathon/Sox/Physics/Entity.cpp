#include "Entity.h"


using namespace Sonicteam::SoX::Physics;


int Sonicteam::SoX::Physics::Entity::OnMessageRecieved(Sonicteam::SoX::Message*)
{
return 0;	
}

DESTRUCTION_CPP(Entity);

Sonicteam::SoX::Physics::Entity::Entity(unsigned int Flag1,unsigned int Flag2)
{

}

Sonicteam::SoX::Physics::Entity::~Entity(void)
{

}
