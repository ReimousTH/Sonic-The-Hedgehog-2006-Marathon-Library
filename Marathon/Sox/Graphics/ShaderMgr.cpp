#include "ShaderMgr.h"
using namespace Sonicteam::SoX::Graphics;


DESTRUCTION_CPP(ShaderMgr);

Sonicteam::SoX::IResource* ShaderMgr::GetMgrResource(Sonicteam::SoX::IResourceMgrParam* param)
{
	return 0; // Req XenonFactory
}

std::string ShaderMgr::GetMgrResourceName(std::string resouce)
{
	return resouce;
}

void ShaderMgr::IResourceMgr03impl()
{
	
}

void ShaderMgr::IResourceMgr04impl()
{
	
}

