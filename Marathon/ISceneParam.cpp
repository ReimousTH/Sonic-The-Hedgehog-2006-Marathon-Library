#include "ISceneParam.h"
using namespace Sonicteam;




ISceneParam::ISceneParam()
{
	this->LinkArray.InitLink();
}

ISceneParam::~ISceneParam()
{
	this->LinkArray.Empty();

}


void ISceneParam::InitializeSceneParam(ISPApplySPArg1 for_now)
{

}

void ISceneParam::SceneParamUpdate(double delta)
{

}

void ISceneParam::ApplySceneParam(ISPApplyArg1)
{

}
DESTRUCTION_CPP(ISceneParam);
