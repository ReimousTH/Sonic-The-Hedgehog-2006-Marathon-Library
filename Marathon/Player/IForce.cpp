#include "IForce.h"

using namespace Sonicteam::Player;





IForce::IForce():IPlugIn("gravity")
{

}

IForce::~IForce()
{

}





void IForce::SetFlag01(DWORD flag_value)
{
		this->Flag2  =flag_value;
}

void IForce::SetFlag02(DWORD flag_value)
{
		this->Flag1  =flag_value;
}

void IForce::SetFlag08(DWORD flag_value)
{
	this->Flag3  =flag_value;
}
DESTRUCTION_CPP(IForce);
