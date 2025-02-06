#include "StepableThread.h"


using namespace Sonicteam::SoX;

//incorrect boost version or some
Sonicteam::SoX::StepableThread::StepableThread(const char* ThreadName,boost::function<void*(double)>& fnc1,boost::function<void*(void)>& fnc2,int Priority):Thread(ThreadName,Priority,1)
{
	this->func1 = fnc1;
	this->func2 = fnc2;
	this->StepableThreadFlag = 0;
}

Sonicteam::SoX::StepableThread::~StepableThread()
{

}

void Sonicteam::SoX::StepableThread::ThreadStep(double delta)
{
	this->func1(delta); //MB
}

void Sonicteam::SoX::StepableThread::ThreadPerfomance()
{

	if ( *(byte *)&this->StepableThreadFlag )
	{
		Sonicteam::SoX::Thread::ThreadPerfomance();
		this->func2();

	}
}

DESTRUCTION_CPP(StepableThread);