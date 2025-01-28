#include "StepableThread.h"


using namespace Sonicteam::SoX;

//incorrect boost version or some
Sonicteam::SoX::StepableThread::StepableThread(const char* ThreadName,boost::function<void*()> fnc1,boost::function<void*(double)> fnc2,int Priority):Thread(ThreadName,Priority,1)
{
	this->func1 = fnc1;
	this->func2 = fnc2;
	this->StepableThreadFlag = 0;
}

void Sonicteam::SoX::StepableThread::ThreadStep(double delta)
{
	this->func2(delta); //MB
}

void Sonicteam::SoX::StepableThread::ThreadPerfomance()
{

	if ( *(byte *)&this->StepableThreadFlag )
	{
		*(byte*)&this->StepableThreadFlag = 0;
	//	sub_82586AC0((Sonicteam::SoX::Thread *)result); BASE
		this->func1();
	}
}
