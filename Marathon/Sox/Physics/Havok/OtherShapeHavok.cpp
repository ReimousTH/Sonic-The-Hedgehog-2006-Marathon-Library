#include "OtherShapeHavok.h"


using namespace Sonicteam::SoX::Physics::Havok;








Sonicteam::SoX::Physics::Havok::OtherShapeHavok::OtherShapeHavok(HAVOK_SHAPE_TYPE* shape)
{
	this->HavokShape = shape;
}

Sonicteam::SoX::Physics::Havok::OtherShapeHavok::~OtherShapeHavok()
{

}
DESTRUCTION_CPP(OtherShapeHavok);