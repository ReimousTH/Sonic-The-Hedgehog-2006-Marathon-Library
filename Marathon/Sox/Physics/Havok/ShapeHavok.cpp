#include "ShapeHavok.h"


using namespace Sonicteam::SoX::Physics;

Sonicteam::SoX::Physics::Havok::ShapeHavok::ShapeHavok(void)
{

}

//mb later
Sonicteam::SoX::Physics::Havok::ShapeHavok::~ShapeHavok(void)
{
	int v5;
	int v4 = (int)this->MhkBaseObject;
	if ( v4 )
	{
		if ( *(short *)(v4 + 4) )
		{
			v5 = (__int16)(*(short *)(v4 + 6) - 1);
			*(short *)(v4 + 6) = v5;
			if ( !v5 )
				(**(void (__fastcall ***)(int, int))v4)(v4, 1);
		}
	}

}

void Sonicteam::SoX::Physics::Havok::ShapeHavok::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Physics::Havok::ShapeHavok::~ShapeHavok();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);

}
