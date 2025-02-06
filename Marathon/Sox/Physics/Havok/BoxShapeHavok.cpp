#include "BoxShapeHavok.h"


using namespace Sonicteam::SoX::Physics::Havok;

void Sonicteam::SoX::Physics::Havok::BoxShapeHavok::ShapeProceedUnk01(__out XMFLOAT4*& u1,__out XMFLOAT4*& u2)
{
	
}

void Sonicteam::SoX::Physics::Havok::BoxShapeHavok::ShapeInitVolume()
{
	return;
}

//TODO
Sonicteam::SoX::Physics::Havok::BoxShapeHavok::BoxShapeHavok(double width,double height,double length):Sonicteam::SoX::Physics::BoxShape(width,height,length)
{
	this->HavokShape = HAVOK_SHAPE_BOX_CREATEDYNAMIC(width,height,length,1.0);
}

Sonicteam::SoX::Physics::Havok::BoxShapeHavok::~BoxShapeHavok(void)
{

}

DESTRUCTION_CPP(BoxShapeHavok);