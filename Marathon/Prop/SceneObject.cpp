#include "SceneObject.h"


Sonicteam::Prop::SceneObject::SceneObject()
{

}

Sonicteam::Prop::SceneObject::~SceneObject()
{

}

void Sonicteam::Prop::SceneObject::DestroyObject(unsigned int flag)
{
	Sonicteam::Prop::SceneObject::~SceneObject();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}
