#include "SceneData.h"


Sonicteam::Prop::SceneData::SceneData()
{

}

Sonicteam::Prop::SceneData::~SceneData()
{

}

void Sonicteam::Prop::SceneData::DestroyObject(unsigned int flag)
{
	Sonicteam::Prop::SceneData::~SceneData();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}
