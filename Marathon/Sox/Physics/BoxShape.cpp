#include "BoxShape.h"


using namespace Sonicteam::SoX::Physics;

Sonicteam::SoX::Physics::BoxShape::BoxShape(double width,double height,double length)
{
	
	this->Width = width;
	this->Height = height;
	this->Length = length;
	this->SFlag = 1;
	this->SVolume = width*height*length * 0.00000099999988;
}

Sonicteam::SoX::Physics::BoxShape::~BoxShape(void)
{

}

DESTRUCTION_CPP(BoxShape);

void Sonicteam::SoX::Physics::BoxShape::ShapeInitVolume()
{
}

