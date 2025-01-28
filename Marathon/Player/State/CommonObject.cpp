#include "CommonObject.h"

using namespace Sonicteam::Player::State;

CommonObject::~CommonObject(void)
{

}

void Object2ForceHelper(CommonContext* a1){

	/*
	if ( a1->field_130 && sub_82615D60 )
	{
		v2 = ((double (*)(void))a1->TableForce->field_14)();
		if ( -(float)((float)v2
			- (float)((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)a1->field_130 + 8))(a1->field_130)) >= a1->float1DC )
			a1->FreeUnknownFlagsDC |= 1u;
	}
	*/
}

void CommonObject::Object2PreUpdateCmn(float)
{
	Sonicteam::Player::State::CommonContext *v1; // r11
	unsigned __int64 v2; // r10

	v1 = this->CObjContext;
	v2 = v1->UnknownFlags0xC8;
	if ( (v2 & 4) != 0 )
		v1->IsInvulnerable2 = 1;
	if ( (v2 & 8) != 0 )
		this->CObjContext->InvicibilityTimerWEffect = this->CObjContext->c_invincible_item;
	if ( (v2 & 0x40000) != 0 )
		this->CObjContext->SpeedUpTime = this->CObjContext->c_speedup_time;

	this->CObjContext->UnkF3 = 0;
	this->CObjContext->UnkF1 = 0;




//	sub_8220CA50(this->CObjContext);

	//a1->StateBase.ContextBase->field_F3 = 0;
	//a1->StateBase.ContextBase->field_F1 = 0;
	// 
	// 
	Object2ForceHelper(this->CObjContext);
}

void CommonObject::Object2PostUpdateCmn(float)
{

}

//I have no idea what boost _ptr should be used
CommonObject::CommonObject(IMachine* a1):Object2(a1)
{

	
	boost::shared_ptr<IContext> t =  a1->GetMashineContext();
	this->ObjectMashine = a1;

	this->CObjContext =  dynamic_cast<CommonContext*>(t.get());// works now

	//this->CObjContext = (CommonContext*)(t.get()); // also should by dynamic cast but since i cant match typeid it useles


//not sure because i cant MAKE BOOST NOT USE STUPUID LWARX



}

void CommonObject::Object2Start()
{

}



void CommonObject::Object2End()
{

}

unsigned int Sonicteam::Player::State::CommonObject::Object2Update(float)
{
	return 0;
}

void Sonicteam::Player::State::CommonObject::DestroyObject(unsigned int flag)
{
	Sonicteam::Player::State::CommonObject::~CommonObject();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}

