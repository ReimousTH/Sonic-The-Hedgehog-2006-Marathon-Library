#include "SurfaceXenon.h"


using namespace Sonicteam::SoX::Graphics::Xenon;


SurfaceXenon::SurfaceXenon()
{

}

SurfaceXenon::~SurfaceXenon()
{

}


unsigned int SurfaceXenon::GetSFlag1()
{
	return this->SFlag1;
}


unsigned int SurfaceXenon::GetSFlag2()
{
	return this->SFlag2;
}

bool SurfaceXenon::IsSurfaceRoot()
{
	return this->SurfaceRoot != 0;
}
DESTRUCTION_CPP(SurfaceXenon);