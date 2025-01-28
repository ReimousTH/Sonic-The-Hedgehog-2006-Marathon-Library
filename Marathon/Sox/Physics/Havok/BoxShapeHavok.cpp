#include "BoxShapeHavok.h"


using namespace Sonicteam::SoX::Physics::Havok;

void Sonicteam::SoX::Physics::Havok::BoxShapeHavok::ShapeProceedUnk01(__out XMFLOAT4*& u1,__out XMFLOAT4*& u2)
{
	
}

int Sonicteam::SoX::Physics::Havok::BoxShapeHavok::ShapeProceedUnk02()
{
	return 0;
}

//TODO
Sonicteam::SoX::Physics::Havok::BoxShapeHavok::BoxShapeHavok(double width,double height,double length):Sonicteam::SoX::Physics::BoxShape(width,height,length)
{
	this->MhkBaseObject = 0;
	XMVECTOR BoxParams = {this->Width *0.0099999998 ,this->Height * 0.0099999998,this->Length * 0.0099999998,0};

	int off_82D5328C = *(int*)0x82D5328C;
	int v5 = (*(int (__fastcall **)(int, int, int))(*(int *)off_82D5328C + 0x10))(off_82D5328C, 0x20, 0x24);


	int hkxObj = ((int (__fastcall *)(...))0x82862258)(v5,&BoxParams,0.0);
	((int (__fastcall *)(...))0x828A7EF8)(&(this->MhkBaseObject),hkxObj);


}

Sonicteam::SoX::Physics::Havok::BoxShapeHavok::~BoxShapeHavok(void)
{

}

void Sonicteam::SoX::Physics::Havok::BoxShapeHavok::DestroyObject(unsigned int flag)
{

}
