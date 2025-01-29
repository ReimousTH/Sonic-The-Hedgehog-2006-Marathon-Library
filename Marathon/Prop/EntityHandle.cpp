#include "EntityHandle.h"

void Sonicteam::Prop::EntityHandle::DestroyObject(unsigned int flag)
{
	
}

Sonicteam::Prop::EntityHandle::EntityHandle(Sonicteam::Prop::Scene* PropScene,unsigned int ID):
PropScene(PropScene),
ID(ID),
unk0x10(0),
unk0x14(0)
{

}

Sonicteam::Prop::EntityHandle::EntityHandle()
{

}
