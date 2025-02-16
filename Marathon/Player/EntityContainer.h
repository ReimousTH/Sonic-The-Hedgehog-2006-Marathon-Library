#ifndef SONICTEAM__PLAYER__ENTITIESCONTAINER
#define SONICTEAM__PLAYER__ENTITIESCONTAINER

#include "Defs.h"
#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/RefCountObject.h>
#include <Sox/Physics/Entity.h>


struct EntityContainer{
	REF_TYPE(Sonicteam::SoX::Physics::Entity) Entity;
	LinkSoxNode<Sonicteam::SoX::Physics::Entity> LinkEntities;
};




#endif



