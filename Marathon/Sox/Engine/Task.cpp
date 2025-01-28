#include "Task.h"


using namespace Sonicteam::SoX::Engine;

static void ClearTaskFunc(Task* task){
	*(int*)task = 0;
};

Task::Task(Sonicteam::SoX::Engine::Doc* doc):Component(0),SimpleLinkNode<Task>()
{

	this->Tuint0x24 = 0;
	this->Tuint0x28 = 0;
	this->Prev = this;	
	this->TaskEngineDoc = doc;
	this->TaskList = Sonicteam::SoX::LinkNodeList<Task>(0);
}


Sonicteam::SoX::Engine::Task::Task(Sonicteam::SoX::Engine::Task* task) :Component(task),IO_TASK(),SimpleLinkNode<Task>()
{

	this->Parent = task;	
	this->TaskEngineDoc = 0;
	this->TaskList = Sonicteam::SoX::LinkNodeList<Task>(0);
	Sonicteam::SoX::Engine::Task* v4 = this->Parent;
	if ( v4 )
	{
		Sonicteam::SoX::Engine::Task* ActiveTask = v4->Active;
		if ( ActiveTask )
		{
			Sonicteam::SoX::Engine::Task* v6 = ActiveTask->Prev;
			this->Next = 0;
			this->Prev = v6;
			ActiveTask->Prev->Next = this;
			ActiveTask->Prev = this;
		}
		else
		{
			this->Prev = this;
			v4->Active = this;
			this->Next = 0;
		}
		this->TaskEngineDoc = task->TaskEngineDoc;
	}
	else
	{
		this->Prev = this;
		this->Next = 0;
	}
}


Task::~Task(void)
{
	this->Empty(this);
	this->EmptyParent(this);
	this->TaskList.ForEach(ClearTaskFunc);
	this->TaskList.Empty();
}

int Task::OnMessageRecieved(Sonicteam::SoX::Message*)
{
	return 0;
}

char* Sonicteam::SoX::Engine::Task::GetObjectType()
{
	return "Task";
}

void Sonicteam::SoX::Engine::Task::OnTaskUpdate(float)
{

}

void Sonicteam::SoX::Engine::Task::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Engine::Task::~Task();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}

Sonicteam::SoX::Engine::IO_TASK::IO_TASK()
{
	this->Tuint0x24 = 0;
}
