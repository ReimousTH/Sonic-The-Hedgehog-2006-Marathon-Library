#include "Task.h"


using namespace Sonicteam::SoX::Engine;

static void ClearTaskFunc(Task* task){
	*(int*)task = 0;
};

Task::Task(Sonicteam::SoX::Engine::Doc* doc):Component(0)
{
	this->Parent = 0;
	this->Child = this;
	this->DependencyIn = 0;
	this->DependencyOut = 0;
	this->TaskEngineDoc = doc;
	this->TaskList.InitLink();
}


Sonicteam::SoX::Engine::Task::Task(Sonicteam::SoX::Engine::Task* task) :Component(task)
{
	this->Flag = 0;
	this->custom = 0;
		
	this->DependencyIn = task; 
	this->DependencyOut = 0;
	this->TaskList.InitLink();

	this->InitDependencyIn();
	if (this->DependencyIn) this->TaskEngineDoc = task->TaskEngineDoc;


}


Task::~Task(void)
{
	this->CleanupOutgoingDependencies();
	this->HandleIncomingDependency();

	//TaskList, ForEach()
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

DESTRUCTION_CPP(Task);
