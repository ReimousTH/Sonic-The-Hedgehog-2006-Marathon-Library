#ifndef SONICTEAM__PLAYER__ENTITIESCONTAINER
#define SONICTEAM__PLAYER__ENTITIESCONTAINER

#include "Defs.h"


#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/Physics/Entity.h>
#include <Sox/IEntityContainer.h>





//in work still

struct EntityContainer:public IEntityContainer<EntityContainer,Sonicteam::SoX::Physics::Entity>{

public:
	EntityContainer();
	~EntityContainer();
	EntityContainer(EntityContainer& other);

};







#endif



