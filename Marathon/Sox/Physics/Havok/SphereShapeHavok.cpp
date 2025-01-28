#include "SphereShapeHavok.h"


using namespace Sonicteam::SoX::Physics::Havok;




//TODO
Sonicteam::SoX::Physics::Havok::SphereShapeHavok::SphereShapeHavok(double radius):Sonicteam::SoX::Physics::SphereShape(radius)
{
	this->MhkBaseObject = 0;


	int off_82D5328C = *(int*)0x82D5328C;
	 *(short *)((*(int (__fastcall **)(int, int, int))(*(int *)off_82D5328C + 0x10))(off_82D5328C, 0x10, 0x24) + 4) = 0x10;


	int hkxObj = ((int (__fastcall *)(...))0x82866EC0)(radius* 0.0099999998);
	((int (__fastcall *)(...))0x828A7EF8)(&(this->MhkBaseObject),hkxObj);


}

Sonicteam::SoX::Physics::Havok::SphereShapeHavok::~SphereShapeHavok(void)
{

}

void Sonicteam::SoX::Physics::Havok::SphereShapeHavok::DestroyObject(unsigned int flag)
{

}

void Sonicteam::SoX::Physics::Havok::SphereShapeHavok::ShapeProceedUnk01(__out XMFLOAT4*& u1,__out XMFLOAT4*& u2)
{
	
}

int Sonicteam::SoX::Physics::Havok::SphereShapeHavok::ShapeProceedUnk02()
{
	return 0;
}
