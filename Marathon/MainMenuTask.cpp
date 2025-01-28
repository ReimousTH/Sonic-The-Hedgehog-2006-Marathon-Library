#include "MainMenuTask.h"


using namespace Sonicteam;

int MainMenuTask::OnMessageRecieved(Sonicteam::SoX::Message*)
{
	return 0;
}


char* MainMenuTask::GetObjectType()
{
	return "Task";
}

void MainMenuTask::OnTaskUpdate(float)
{
	
}

Sonicteam::DocMarathonImp* Sonicteam::MainMenuTask::GetCurrentDoc()
{
	return (DocMarathonImp*)this->TaskEngineDoc;
}

