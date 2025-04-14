#include "Application.h"


using namespace Sonicteam::SoX::Engine;





Application::Application(void)
{

}

Application::~Application(void)
{

}


char* Application::GetObjectType()
{
	return "Object";
}

bool Application::HandleMessage(size_t,size_t,size_t)
{
	return true;
}

bool Application::D3DSetShaderGPRAllocation()
{
	return 0;
}

void Application::D3DRenderFrameAndSwapBuffers()
{

}

char Application::IsPause()
{
	return 0;

}

char Application::IsReturnToTitle()
{
	return 0;

}

size_t Application::GetXLocal()
{
	return 1;

}

size_t Application::GetRegion()
{

	return 0;
}

bool Application::WriteSaveFile(const char* SaveFileName,void* SaveFileBuffer,size_t SaveFileSize)
{

	return false;
}

bool Application::ReadSaveFile(const char* SaveFileName,void* ReadFileBuffer,size_t ReadFileSize)
{
	return false;
}

bool Application::CreateContent(const char* ContentName)
{
	return false;
}

void Application::GetDownloadContent(std::vector<std::string>& content)
{
	
}

void Application::AppUnk0x38()
{

}

void Application::OnDocAfter()
{

}


DESTRUCTION_CPP(Application);
