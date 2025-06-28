#include "ISceneParam.h"
using namespace Sonicteam;




ISceneParam::ISceneParam()
{
	this->LinkArray.InitLink();
}

ISceneParam::~ISceneParam()
{
	this->LinkArray.empty();

}


void ISceneParam::InitializeSceneParam(void* for_now)
{

}

void ISceneParam::ISceneParam0xC()
{

}

void ISceneParam::ApplySceneParam(ISPApplyArg1)
{

}
DESTRUCTION_CPP(ISceneParam);
