#include "EntityContainer.h"

EntityContainer::EntityContainer()
{

}

EntityContainer::EntityContainer(EntityContainer& other)
{
	/*
	IEntityClass* entity = 0;
	if (other.Entity)  // & =1 Method that missing
		entity = this->Entity;
	this->LinkEntities.Clear();
	this->LinkEntities._this = this;
	if (entity){
		this->LinkEntities.Connect(reinterpret_cast<LinkSoxNode<EntityContainer>::iterator*>(&this->Entity->LinkEntity));
	}
	*/
	
 }



EntityContainer::~EntityContainer()
{
	//this->LinkEntities.SafeDisconnect();
	//this->LinkEntities.Clear();
	//if (Entity) Entity->LinkEntity.SafeDisconnect();
}
