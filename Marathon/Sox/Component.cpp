#include "Component.h"


using namespace Sonicteam::SoX;

void DestroyComponentList(Sonicteam::SoX::Component* component){

}

//FINALY SAME CONSTRUCTORS, until i change LINK NODE AGAIN :(
Component::Component(Component* component):LastComponent(component)
{
	this->LinkComponent.Clear();
	this->LinkComponent._this = this;


	this->ListComponent.InitLink();

	if (component){
		component->ListComponent.Attach(&this->LinkComponent);
	}
}


Sonicteam::SoX::Component::~Component(void)
{
	this->ListComponent.DestroyObject(0);
	this->ListComponent.Empty();
	this->LinkComponent.SafeDisconnect();
	
}



	

char* Sonicteam::SoX::Component::GetObjectType()
{
	return "Object";
}

DESTRUCTION_CPP(Component);