#include "ApplicationXenon.h"


using namespace Sonicteam::SoX;


char* Sonicteam::SoX::ApplicationXenon::GetObjectType()
{
	return "Object";
}

void Sonicteam::SoX::ApplicationXenon::ApplicationXenonM1(void)
{

}

void Sonicteam::SoX::ApplicationXenon::ApplicationConsoleMessages(unsigned int,unsigned int,unsigned int)
{

}

void Sonicteam::SoX::ApplicationXenon::ApplicationXenonD3DDevice_SetShaderGPRAllocation(void)
{

}

void Sonicteam::SoX::ApplicationXenon::ApplicationXenonD3DDevice_SetShaderGPRAllocation_KickOFF(void)
{

}

unsigned int Sonicteam::SoX::ApplicationXenon::ApplicationXenonM5(void)
{

	return 0;
}

unsigned int Sonicteam::SoX::ApplicationXenon::ApplicationXenonM6(void)
{
return 0;
}

unsigned int Sonicteam::SoX::ApplicationXenon::ApplicationXenonGetFixedGameRegion(void)
{
return 0;
}

unsigned int Sonicteam::SoX::ApplicationXenon::ApplicationXenonGetFixedGameRegion2(void)
{
 return 0;
}

unsigned int Sonicteam::SoX::ApplicationXenon::ApplicationXenonProcessSaveGameFile(const char* SaveFileName,byte* EndFileSaveBuffer,unsigned int EndFileSaveBufferSize)
{
 return 0;
}

unsigned int Sonicteam::SoX::ApplicationXenon::ApplicationXenonProcessLoadGameFile(const char* SaveFileName,byte* LoadFileSaveBuffer,unsigned int EndFileSaveBufferSize)
{
return 0;
}

unsigned int Sonicteam::SoX::ApplicationXenon::ApplicationXenonProcessIsXamContentCreate(const char* SaveFileName)
{
return 0;
}

unsigned int Sonicteam::SoX::ApplicationXenon::ApplicationXenonProcessDLC(unsigned int)
{
return 0;
}

ApplicationXenon*& Sonicteam::SoX::ApplicationXenon::ApplicationXenonMarathon = *(ApplicationXenon**)0x82D3B6E8;

