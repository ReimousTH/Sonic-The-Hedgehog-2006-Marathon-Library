#include "SphereShapeHavok.h"


using namespace Sonicteam::SoX::Physics::Havok;




//TODO
Sonicteam::SoX::Physics::Havok::SphereShapeHavok::SphereShapeHavok(double radius):Sonicteam::SoX::Physics::SphereShape(radius)
{



}

Sonicteam::SoX::Physics::Havok::SphereShapeHavok::~SphereShapeHavok(void)
{

}

DESTRUCTION_CPP(SphereShapeHavok);

void Sonicteam::SoX::Physics::Havok::SphereShapeHavok::ShapeProceedUnk01(__out XMFLOAT4* u1,__out XMFLOAT4* u2)
{
	
}

void Sonicteam::SoX::Physics::Havok::SphereShapeHavok::ShapeInitVolume()
{
	return;
}
