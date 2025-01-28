#include "HUDOption.h"


using namespace Sonicteam;

Sonicteam::SoX::Engine::Doc* Sonicteam::HUDOption::GetCurrentDoc()
{


	return 	this->TaskEngineDoc;
}



Sonicteam::HUDOption::HUDOption(Sonicteam::SoX::Engine::Doc* doc):SoX::Engine::Task(doc)
{

}

void Sonicteam::HUDOption::OnTaskUpdate(float)
{

}

int Sonicteam::HUDOption::OnMessageRecieved(Sonicteam::SoX::Message*)
{

	return 0;
}



Sonicteam::HUDOption::~HUDOption()
{
	
}


