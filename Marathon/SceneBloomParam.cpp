#include "SceneBloomParam.h"
using namespace Sonicteam;




SceneBloomParam::SceneBloomParam()
{
	this->LinkArray.InitLink();
}

SceneBloomParam::~SceneBloomParam()
{

}
const char* SceneBloomParam::GetParamName()
{
	return "Bloom";
}

DESTRUCTION_CPP(SceneBloomParam);
