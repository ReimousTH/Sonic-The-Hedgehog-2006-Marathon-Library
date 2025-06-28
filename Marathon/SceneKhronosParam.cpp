#include "SceneKhronosParam.h"
using namespace Sonicteam;




SceneKhronosParam::SceneKhronosParam()
{
	this->LinkArray.InitLink();
}

SceneKhronosParam::~SceneKhronosParam()
{

}
const char* SceneKhronosParam::GetParamName()
{
	return "Khronos";
}

DESTRUCTION_CPP(SceneKhronosParam);
