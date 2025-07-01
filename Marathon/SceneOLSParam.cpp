#include "SceneOLSParam.h"
using namespace Sonicteam;




SceneOLSParam::SceneOLSParam()
{
	this->LinkArray.InitLink();
}

SceneOLSParam::~SceneOLSParam()
{

}
const char* SceneOLSParam::GetParamName()
{
	return "OLS";
}

DESTRUCTION_CPP(SceneOLSParam);
