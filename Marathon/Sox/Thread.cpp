#include "Thread.h"


using namespace Sonicteam::SoX;



DWORD WINAPI SonicTeamSOXThreadProcFunc( LPVOID lpParameter )
{
	if (lpParameter)
		((Sonicteam::SoX::Thread*)lpParameter)->ThreadExecutor();

	return 0;

}

Sonicteam::SoX::Thread::Thread(const char* ThreadName,int Priority,int Flag):Link(this)
{
//	this->m_Field1 = 0;
//	this->m_Field2 = 0;
//	this->instance = this;

	this->ThreadFlag1 = 0x01000000;
	this->ThreadFlag2 = 0x01000000 | (Flag << 16);
	this->m_Field4 = 0;
	this->m_Field5 = 0;
	this->m_Field6 = 0;
	this->m_ThreadName = ThreadName;
	this->m_Event1 = CreateEvent(0,0,0,0);
	this->m_Event2 = CreateEvent(0,0,0,0);
	

	this->m_ThreadHandle = CreateThread(0,0,SonicTeamSOXThreadProcFunc,this,4u,(LPDWORD)&this->m_ThreadID);
	XSetThreadProcessor(this->m_ThreadHandle,Priority);





}

void Sonicteam::SoX::Thread::DestroyObject(unsigned int Flag)
{
	if (Flag){
		Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,Flag);
	}

}

void Sonicteam::SoX::Thread::ThreadPerfomance()
{

	unsigned __int64 T1 =  Sonicteam::SoX::PerformanceFrequency::getInstance().GetTimeBase();
	unsigned __int64 T2 =  Sonicteam::SoX::PerformanceFrequency::getInstance().GetTimeBase();

}

void Sonicteam::SoX::Thread::ThreadExecutor()
{
	while ( this->ThreadFlag1 & ~0xFF000000 )
	{
		if ( this->ThreadFlag2 & ~0x00FF0000)
		{
			WaitForSingleObject(this->m_Event1, 0xFFFFFFFF);
			//sub_82586A08((int)a1); //need replicate them
			SetEvent(this->m_Event2);
		}
		else
		{
			//sub_82586A08((int)a1);
		}
	}


}

void Sonicteam::SoX::Thread::ThreadStep(double delta)
{

	
}

Sonicteam::SoX::Thread::~Thread()
{
	//Part1
	if (this->ThreadFlag1 >> 24){
		this->ThreadFlag1 &= ~0xFF000000;
		if (this->ThreadFlag2 >> 24){
			this->ThreadFlag2 &= ~0xFF000000;
			ResumeThread(this->m_ThreadHandle);
		}
		SetEvent(this->m_Event1);
		WaitForSingleObject(this->m_ThreadHandle,-1);
		CloseHandle(this->m_ThreadHandle);
		this->m_ThreadHandle = INVALID_HANDLE_VALUE;

	}
	//Part2
	CloseHandle(this->m_Event1);
	CloseHandle(this->m_Event2);

	//cntlzw seems inverse 
	if (this->m_Field4 && this->Link.NThread != 0) {
		this->Link.RemoveLink();
	}
	//Next should natural destructor do thing

}



