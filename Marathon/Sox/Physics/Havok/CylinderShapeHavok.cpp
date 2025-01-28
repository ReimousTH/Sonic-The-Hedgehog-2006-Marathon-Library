#include "CylinderShapeHavok.h"


using namespace Sonicteam::SoX::Physics::Havok;




//TODO
Sonicteam::SoX::Physics::Havok::CylinderShapeHavok::CylinderShapeHavok(double radius,double height):Sonicteam::SoX::Physics::CylinderShape(radius,height)
{
	this->MhkBaseObject = 0;


	int off_82D5328C = *(int*)0x82D5328C;
	int hkxobj = (*(int (__fastcall **)(int, int, int))(*(int *)off_82D5328C + 0x10))(off_82D5328C, 0x60, 0x24);
	*(short *)(hkxobj + 4) = 0x60;


	 XMVECTOR CylinderShapeH1 = {
		 0.0,
		 0.0,
		 0.0,
		 0.0
	 };
	 XMVECTOR CylinderShapeH2 = {
		 0.0,
		 0.0,
		 0.0,
		 0.0
	 };
	 CylinderShapeH1.z = (this->Height * 0.0099999998)*-1;
	 CylinderShapeH2.z = this->Height * 0.0099999998;
	



	int hkxObjF = ((int (__fastcall *)(...))0x82861960)(hkxobj,0.050000001,&CylinderShapeH1,&CylinderShapeH2);
	((int (__fastcall *)(...))0x828A7EF8)(&(this->MhkBaseObject),hkxObjF); //execute


}

Sonicteam::SoX::Physics::Havok::CylinderShapeHavok::~CylinderShapeHavok(void)
{

}

void Sonicteam::SoX::Physics::Havok::CylinderShapeHavok::DestroyObject(unsigned int flag)
{

}

void Sonicteam::SoX::Physics::Havok::CylinderShapeHavok::ShapeProceedUnk01(__out XMFLOAT4*& u1,__out XMFLOAT4*& u2)
{
	
}

int Sonicteam::SoX::Physics::Havok::CylinderShapeHavok::ShapeProceedUnk02()
{
return 0;	
}
