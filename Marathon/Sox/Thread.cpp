#include "Thread.h"



using namespace Sonicteam::SoX;



DWORD WINAPI SonicTeamSOXThreadProcFunc( LPVOID lpParameter )
{
	
	if (lpParameter)
		((Sonicteam::SoX::Thread*)lpParameter)->ThreadExecutor();

	return 0;

}

Sonicteam::SoX::Thread::Thread(const char* ThreadName,int Procc,int EventFlag):
LinkNode(this)
{

//	this->m_Field1 = 0;
//	this->m_Field2 = 0;
//	this->instance = this;


	this->IsExecutable = 1;
	this->ThreadFlag5 = 1;
	this->UseEvent = EventFlag;

	this->m_Field4 = 0;
	this->TPerfScale = 0;
	this->StepElapsedTime  = 0;
	this->m_ThreadName = ThreadName;
	this->StartEvent = CreateEvent(0,0,0,0);
	this->EndEvent = CreateEvent(0,0,0,0);
	

	
	this->m_ThreadHandle = CreateThread(0,0,SonicTeamSOXThreadProcFunc,this,CREATE_SUSPENDED,(LPDWORD)&this->m_ThreadID);
	XSetThreadProcessor(this->m_ThreadHandle,Procc);



}


DESTRUCTION_CPP(Thread);

void Sonicteam::SoX::Thread::ThreadPerfomance()
{

	unsigned __int64 T1 =  Sonicteam::SoX::PerformanceFrequency::getInstance().GetTimeBase();
	WaitForSingleObject(this->EndEvent,-1);
	unsigned __int64 T2 =  Sonicteam::SoX::PerformanceFrequency::getInstance().GetTimeBase();
	unsigned __int64 T3 = T2-T1;
	unsigned __int64 Delta =   T3/Sonicteam::SoX::PerformanceFrequency::getInstance().GetPerformanceFrequency().LowPart;
	this->ThreadFrame = Delta;

}

void Sonicteam::SoX::Thread::ThreadExecutor()
{
	while ( this->IsExecutable)
	{
		if ( this->UseEvent)
		{
			WaitForSingleObject(this->StartEvent, 0xFFFFFFFF);
			//sub_82586A08((int)a1); //need replicate them


			unsigned __int64 T1 =  Sonicteam::SoX::PerformanceFrequency::getInstance().GetTimeBase();
			this->ThreadStep(this->ThreadDelta);
			unsigned __int64 T2 =  Sonicteam::SoX::PerformanceFrequency::getInstance().GetTimeBase();
			unsigned __int64 T3 = T2-T1;
			unsigned __int64 Delta =   T3/Sonicteam::SoX::PerformanceFrequency::getInstance().GetPerformanceFrequency().LowPart;
			this->StepElapsedTime  = Delta;
			this->TPerfScale++;



			SetEvent(this->EndEvent);
		}
		else
		{
			unsigned __int64 T1 =  Sonicteam::SoX::PerformanceFrequency::getInstance().GetTimeBase();
			this->ThreadStep(this->ThreadDelta);
			unsigned __int64 T2 =  Sonicteam::SoX::PerformanceFrequency::getInstance().GetTimeBase();
			unsigned __int64 T3 = T2-T1;
			unsigned __int64 Delta =   T3/Sonicteam::SoX::PerformanceFrequency::getInstance().GetPerformanceFrequency().LowPart;
			this->StepElapsedTime  = Delta;
			this->TPerfScale++;

		}
	}


}

void Sonicteam::SoX::Thread::ThreadStep(double delta)
{

	
}

//Wait
void Sonicteam::SoX::Thread::Join()
{
	if (this->IsExecutable >> 24){
		this->IsExecutable &= ~0xFF000000;
		if (this->ThreadFlag2 >> 24){
			this->ThreadFlag2 &= ~0xFF000000;
			ResumeThread(this->m_ThreadHandle);
		}
		SetEvent(this->StartEvent);
		WaitForSingleObject(this->m_ThreadHandle,-1);
		CloseHandle(this->m_ThreadHandle);
		this->m_ThreadHandle = INVALID_HANDLE_VALUE;

	}
}



void Sonicteam::SoX::Thread::Resume()
{
	ResumeThread(m_ThreadHandle);
	
}

Sonicteam::SoX::Thread::~Thread()
{
	//Part1
	Join();
	//Part2
	CloseHandle(this->StartEvent);
	CloseHandle(this->EndEvent);

	//cntlzw seems inverse 
	if (this->m_Field4 && this->LinkNode.Next != 0) {
		this->LinkNode.Disconnect();
	}

	this->LinkNode.SafeDisconnect();
	

}



