#include "IForce.h"

using namespace Sonicteam::Player;





IForce::IForce():IPlugIn("gravity")
{

}

IForce::~IForce()
{

}





void IForce::ImportICommonContextIFFlag(DWORD flag_value)
{
		this->ICommonContextIFFlag  =flag_value;
}

void IForce::ImportIPosturePlugInFlag(DWORD flag_value)
{
		this->IPosturePlugInFlag  =flag_value;
}

void IForce::ImportPostureRequestFlag(DWORD flag_value)
{
	this->PostureRequestFlag  =flag_value;
}
DESTRUCTION_CPP(IForce);
