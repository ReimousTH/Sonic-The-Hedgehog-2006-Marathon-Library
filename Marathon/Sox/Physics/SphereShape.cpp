#include "SphereShape.h"


using namespace Sonicteam::SoX::Physics;

Sonicteam::SoX::Physics::SphereShape::SphereShape(double radius)
{

	this->Radius = radius;

	this->SFlag = 0;
	this->SVolume =  M_PI*radius*radius*radius * 0.0000013333332;
}

Sonicteam::SoX::Physics::SphereShape::~SphereShape(void)
{

}

DESTRUCTION_CPP(SphereShape);



void Sonicteam::SoX::Physics::SphereShape::ShapeProceedUnk01(__out XMFLOAT4*& u1,__out XMFLOAT4*& u2)
{
	
}

void Sonicteam::SoX::Physics::SphereShape::ShapeInitVolume()
{
	return;
}
