#include "DocMarathonImp.h"


#include <Sox/Input/Manager.h>
#include <Sox/Input/Listener.h>

using namespace Sonicteam;

Sonicteam::DocMarathonImp::DocMarathonImp(unsigned int)
{

}

Sonicteam::DocMarathonImp::~DocMarathonImp(void)
{

}

void Sonicteam::DocMarathonImp::EngineDocOnUpdate(float)
{

}

void Sonicteam::DocMarathonImp::EngineDocDomeSome()
{

}

unsigned int Sonicteam::DocMarathonImp::DocGetMyGraphicDevice()
{

	return 0;
}

Sonicteam::SoX::Graphics::FrameSynchronizer* Sonicteam::DocMarathonImp::DocGetFrameSynchronizer()
{
return 0;
}

boost::shared_ptr<void*> Sonicteam::DocMarathonImp::DocDoUnkAction01(unsigned int,unsigned int)
{
return DocAudioPlayerImp;
}

boost::shared_ptr<Sonicteam::SoX::Scenery::World> Sonicteam::DocMarathonImp::DocGetWorld(unsigned int index)
{ 
	return 	(*WorldCollection)[index].lock();
}

std::vector<unsigned int>* Sonicteam::DocMarathonImp::DocGetDoculist()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocDoUnkAction02(unsigned int)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocDoUnkModules()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::GetPlayerInput(unsigned int)
{
return 0;
}

DocMarathonImpVecFlags* Sonicteam::DocMarathonImp::GetDocImpFlag()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::GSDocFrameSynchronizer(unsigned int)
{
return 0;
}

//Updated 27.06.2025
void Sonicteam::DocMarathonImp::QueueControllerInputByIndex(Sonicteam::SoX::Input::Listener* listener,size_t index)
{

	Sonicteam::SoX::Input::Manager* mgr = this->DMPlayerInputManager[index].get();
	mgr->Listener.Connect(&listener->LinkInput);

}

unsigned int Sonicteam::DocMarathonImp::DocGetCurrentCase()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetPreviousCase()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetSFXAgent()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetImageFilterCollection()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetPostprocessController()
{
return 0;
}



unsigned int Sonicteam::DocMarathonImp::DocGetCurrentMessage()
{

	return 0;
}

boost::shared_ptr<void*> Sonicteam::DocMarathonImp::DocGetAudioPlayerImp()
{
	return this->DocAudioPlayerImp;
}

unsigned int Sonicteam::DocMarathonImp::DocSetCurrentMode(unsigned int)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetDebug3DFont()
{
return 0;
}

Sonicteam::SceneParamManager* Sonicteam::DocMarathonImp::DocGetSceneParamManager()
{
	return this->DocSceneParamManager;
}

unsigned int Sonicteam::DocMarathonImp::DocGetUnkManagers()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetUnkGameResources()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetUnkFloatParam01()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocResetUnkLoadingFlag01()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetUnkLoadingFlag02()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocResetUnkLoadingFlag02()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetUnkLoadingFlag01()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocResetUnkFlag01()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocPauseGame(unsigned char)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocLoadScene(const char*)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetuintgap0x114()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetuintgap0x234()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocChangeGameSpeed(unsigned char,double)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocIsVFrameEnabled()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocChangeVFrameState(unsigned char,const char*)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocCopy0x360(unsigned int)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetGameRuleContext()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocSetGameRuleContext(unsigned int)
{
return 0;
}

Sonicteam::SoX::Engine::Task* Sonicteam::DocMarathonImp::DocGetTask(size_t index)
{
	return this->DocTask[index]; 
}

unsigned int Sonicteam::DocMarathonImp::DoGetcuint0xFC()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DoGetcuint0xF8()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocChangeSpeedState(unsigned char)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocResetUnkFlag02()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetUnkFlag02()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocResetOnUnkFlag02()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetUnkStaticFlag01()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocSetStringFlags01(std::string*)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocSetStringFlags02(std::string*)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetUnkStaticFlag02()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetUnkStaticFlag02_1()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocProcessCheckSubtitleFlag(char*)
{
return 0;
}

const char* Sonicteam::DocMarathonImp::DocGetLanguage()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetuint0x3BC()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetuint0x3BC_1()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetuint0x2AFCC()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetuint0x2AFCC_1()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetuint0x55BDC()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetuint0x55BDC_1()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetuint0x55C24()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGetuint0x55C24_1()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::SetP1RealControllerID(unsigned int)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::GetP1RealControllerID()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::SetRealControllerID(unsigned int,unsigned int)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::GetRealControllerID(unsigned int)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocProcessSubtitleFlag(char*,unsigned int)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGet0x55C54()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocSet0x55C54(int value)
{

	return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocSet0x55C58(char flag)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocGet0x5C5C()
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocSet0x5C5C(int v)
{
return 0;
}

unsigned int Sonicteam::DocMarathonImp::DocProcessShaderMode(int mode)
{
return 0;
}
