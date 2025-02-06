
#include "IGauge.h"


using namespace Sonicteam::Player;


IGauge::~IGauge(void)
{

}

IGauge::IGauge(char* plug):IPlugIn(plug),IVariable(),IStepable()
{

}

