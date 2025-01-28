#include "ICommonContext.h"

using namespace Sonicteam::Player::State;

ICommonContext::ICommonContext(void):IContext("state context")
{
}

ICommonContext::~ICommonContext(void)
{
}

void ICommonContext::ICCIF_01(float x,float z,float hold)
{
	this->LastVelocityX = x; //Forward 
	this->LastVelocityZ = z; //Y 
	this->LastLockInputTime = hold;

}

void ICommonContext::ICCIF_02(float a1,float a2,float a3,float a4)
{
	this->field_74 = a1;
	this->field_78 = a2;
	this->field_7C = a3;
	this->field_80 = a4;
}

float ICommonContext::GetTotalSpeedY()
{
	return this->base_speed_y + this->gimmick_speed_y;
}

float ICommonContext::GetTotalSpeedZ()
{
	return this->base_speed_z + this->gimmick_speed_z;
}

void ICommonContext::ImportAnimationStateFlag(DWORD flag_value)
{
	this->AnimationState = flag_value;
}

//something different in code but should be same i guess
void ICommonContext::ICOnInputTick(float a2)
{
	this->Input = 0; //Reset Input Value
	this->CurrentStickBorder  = 0.0; // Have no idea what is it

		if (this->LockInputTime > 0.0){
			if (this->LockInputTime  - a2 >= 0.0){
				this->LockInputTime = this->LockInputTime -a2;
			}
			else this->LockInputTime = 0.0;
			
		}

}

void Sonicteam::Player::State::ICommonContext::DestroyObject(unsigned int flag)
{
	ICommonContext::~ICommonContext();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}
