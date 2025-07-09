#include "EntityHavok.h"


using namespace Sonicteam::SoX::Physics::Havok;



Sonicteam::SoX::Physics::Havok::EntityHavok::EntityHavok()
{

}

Sonicteam::SoX::Physics::Havok::EntityHavok::~EntityHavok()
{

}

void Sonicteam::SoX::Physics::Havok::EntityHavok::EntityHavokVFT01(double)
{

}

void Sonicteam::SoX::Physics::Havok::EntityHavok::EntityHavokVFT02()
{

}

int Sonicteam::SoX::Physics::Havok::EntityHavok::EntityHavokVFT03(void*,void*)
{
	return 0;
}

XMVECTOR Sonicteam::SoX::Physics::Havok::EntityHavok::GetRotation()
{
	return this->Rotation;
}

XMVECTOR Sonicteam::SoX::Physics::Havok::EntityHavok::GetPosition()
{
	 return this->Translation;
}
