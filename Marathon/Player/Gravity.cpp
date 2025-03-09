#include "Gravity.h"
using namespace Sonicteam::Player;

Gravity::Gravity()
{
	this->Flag1 =0;
	this->Flag2 = 0;
	this->Flag3 = 0;
	this->ForceUP = false;
	this->gravity = 0;
	this->c_pass_fluid = 0;
	this->GravityDownForce = 0;
	this->GravityDirection = XMFLOAT3(0,-1,0);

}

Gravity::~Gravity()
{

}





void Gravity::OnVarible(IVARIABLETYPE var)
{
	this->gravity =  (*var)->GetFloatValue(std::string("gravity")) ;
	this->c_pass_fluid =  (*var)->GetFloatValue(std::string("c_pass_fluid")) ;
}

void Gravity::OnStepable(float delta)
{
	this->GravityDownForce += gravity * delta;
	if (ForceUP){
		this->GravityDownForce = 0;
		this->ForceUP = false;
	}
	unsigned int Flag1 = this->Flag1;
	if (  (Flag1 & 1) != 0  ) this->GravityDownForce = 0;
	if (  (Flag1 & 0x400) != 0 && (this->Flag3 & 8) != 0   ) this->GravityDownForce = 0;

	unsigned int Flag2 = this->Flag2;
	if (  (Flag2 & 0x20) != 0  ) this->GravityDownForce = 0;
	if (  (Flag2 & 0x200000) != 0  ) this->GravityDownForce = 0;
	if (  (Flag1 & 0x800) != 0  ) this->c_pass_fluid;
	this->Flag1 = 0;
	this->Flag2 = 0; // weird they skipped Flag3 reset hmm

}



XMFLOAT3* Gravity::GetGravityDirection()
{
	return &this->GravityDirection;
}

double Gravity::GetGravityDownForce()
{
	return this->GravityDownForce;
}
DESTRUCTION_CPP(Gravity);