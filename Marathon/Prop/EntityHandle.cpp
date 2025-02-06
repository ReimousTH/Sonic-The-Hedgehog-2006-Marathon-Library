#include "EntityHandle.h"

using namespace Sonicteam::Prop;



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

Sonicteam::Prop::EntityHandle::~EntityHandle()
{

}

DESTRUCTION_CPP(EntityHandle);