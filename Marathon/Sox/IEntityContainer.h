#ifndef SONICTEAM__PLAYER__IENTITIESCONTAINER
#define SONICTEAM__PLAYER__IENTITIESCONTAINER

#include "Defs.h"
#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/RefCountObject.h>





//Since I Have other class BodyHavok,EntityHavok 
template <typename Container,typename Class>
struct IEntityContainer{

	typedef Class IEntityClass;
	typedef Container IEntityContainerType; 


	IEntityContainer();	
	~IEntityContainer();


	void Reset();
	Class* Entity; //0x0 
	LinkSoxNode<Container> LinkEntities; //0x4

};

template <typename Container,typename Class>
void IEntityContainer<Container, Class>::Reset()
{

}

template <typename Container,typename Class>
IEntityContainer<Container, Class>::~IEntityContainer()
{

}

template <typename Container,typename Class>
IEntityContainer<Container, Class>::IEntityContainer()
{

}



#endif
