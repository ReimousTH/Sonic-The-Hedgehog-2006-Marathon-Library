#include "CapsuleShape.h"


using namespace Sonicteam::SoX::Physics;

Sonicteam::SoX::Physics::CapsuleShape::CapsuleShape(double radius,double height)
{
	
	this->Radius = radius;
	this->Height = height * 0.5;

	this->SFlag = 2;
	this->SVolume =  (((((radius * 1.3333334) + height) * M_PI) * radius) * radius) * 0.00000099999988;
}

Sonicteam::SoX::Physics::CapsuleShape::~CapsuleShape(void)
{

}

void Sonicteam::SoX::Physics::CapsuleShape::DestroyObject(unsigned int flag)
{
	
}

 int  Sonicteam::SoX::Physics::CapsuleShape::ShapeProceedUnk02()
{
	return 0;
}
