#include "CylinderShape.h"


using namespace Sonicteam::SoX::Physics;

Sonicteam::SoX::Physics::CylinderShape::CylinderShape(double radius,double height)
{

	this->Radius = radius;
	this->Height = height * 0.5;
	this->SFlag = 3;
	this->SVolume =  M_PI * radius * radius * height * 0.00000099999988;
}

Sonicteam::SoX::Physics::CylinderShape::~CylinderShape(void)
{

}

DESTRUCTION_CPP(CylinderShape);

void Sonicteam::SoX::Physics::CylinderShape::ShapeInitVolume()
{
}
