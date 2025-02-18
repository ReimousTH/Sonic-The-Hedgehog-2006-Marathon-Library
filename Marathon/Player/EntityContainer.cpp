#include "EntityContainer.h"

EntityContainer::EntityContainer():Entity(0),LinkEntities(0)
{

}

EntityContainer::~EntityContainer()
{
	this->LinkEntities.SafeDisconnect();
	this->LinkEntities.Clear();
}
