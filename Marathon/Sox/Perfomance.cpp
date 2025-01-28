#include "Perfomance.h"


using namespace Sonicteam::SoX;

Sonicteam::SoX::PerformanceFrequency::PerformanceFrequency()
{
	QueryPerformanceFrequency(&PerformanceFrequencyOutput);
}

LARGE_INTEGER Sonicteam::SoX::PerformanceFrequency::GetPerformanceFrequency()
{

	return	this->PerformanceFrequencyOutput;
}

 unsigned __int64 Sonicteam::SoX::PerformanceFrequency::GetTimeBase()
{
	return 	__mftb();
}
