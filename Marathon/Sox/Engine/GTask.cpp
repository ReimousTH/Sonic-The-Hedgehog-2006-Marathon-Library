#include "GTask.h"


using namespace Sonicteam::SoX::Engine;

GTask::GTask(Sonicteam::SoX::Component* a1):Component(a1)
{

}

GTask::~GTask(void)
{

}


char* Sonicteam::SoX::Engine::GTask::GetObjectType()
{
	return "GTask";
}

