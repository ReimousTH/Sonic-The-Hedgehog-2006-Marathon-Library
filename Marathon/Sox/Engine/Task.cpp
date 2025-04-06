#include "Task.h"


using namespace Sonicteam::SoX::Engine;

static void ClearTaskFunc(Task* task){
	*(int*)task = 0;
};

Task::Task(Sonicteam::SoX::Engine::Doc* doc):Component(0)
{

	//Later


	this->TaskEngineDoc = doc;
	this->TaskList.InitLink();
}


Sonicteam::SoX::Engine::Task::Task(Sonicteam::SoX::Engine::Task* task) :Component(task)
{

	this->TaskList.InitLink();
	this->add_dependency(task);
	this->TaskEngineDoc = task->TaskEngineDoc;
}


Task::Task():Component(0)
{

}

Task::~Task(void)
{
	this->CleanupOutgoingDependencies();
	this->HandleIncomingDependency();

	//TaskList, ForEach()
	this->TaskList.Empty();
}

int Task::OnMessageRecieved(SoXMessageType)
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

DESTRUCTION_CPP(Task);
