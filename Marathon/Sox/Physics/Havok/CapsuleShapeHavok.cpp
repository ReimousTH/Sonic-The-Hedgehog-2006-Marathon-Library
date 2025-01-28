#include "CapsuleShapeHavok.h"


using namespace Sonicteam::SoX::Physics::Havok;




//TODO
Sonicteam::SoX::Physics::Havok::CapsuleShapeHavok::CapsuleShapeHavok(double radius,double height):Sonicteam::SoX::Physics::CapsuleShape(radius,height)
{
	this->MhkBaseObject = 0;


	int off_82D5328C = *(int*)0x82D5328C;
	int hkxobj = (*(int (__fastcall **)(int, int, int))(*(int *)off_82D5328C + 0x10))(off_82D5328C, 0x30, 0x24);
	*(short *)(hkxobj + 4) = 0x30;


	 XMVECTOR CapsuleShapeH1 = {
		 0.0,
		 0.0,
		 0.0,
		 0.0
	 };
	 XMVECTOR CapsuleShapeH2 = {
		 0.0,
		 0.0,
		 0.0,
		 0.0
	 };
	 CapsuleShapeH1.z = this->Height * 0.0099999998 * -0.5;
	 CapsuleShapeH2.z = this->Height * 0.0099999998 * 0.5;
	 float fixed_radius = this->Radius * 0.0099999998;




	int hkxObjF = ((int (__fastcall *)(...))0x82866508)(hkxobj,fixed_radius,&CapsuleShapeH1,&CapsuleShapeH2);
	((int (__fastcall *)(...))0x828A7EF8)(&(this->MhkBaseObject),hkxObjF); //execute


}

Sonicteam::SoX::Physics::Havok::CapsuleShapeHavok::~CapsuleShapeHavok(void)
{

}

void Sonicteam::SoX::Physics::Havok::CapsuleShapeHavok::DestroyObject(unsigned int flag)
{

}

void Sonicteam::SoX::Physics::Havok::CapsuleShapeHavok::ShapeProceedUnk01(__out XMFLOAT4*& u1,__out XMFLOAT4*& u2)
{
	
}

int Sonicteam::SoX::Physics::Havok::CapsuleShapeHavok::ShapeProceedUnk02()
{
	return 0;
}
