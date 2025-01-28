#include "Object.h"


using namespace Sonicteam::SoX;

//have not any of this
Object::~Object(void)
{
	
}

char* Object::GetObjectType()
{

	return "Object";
}

Object::Object(void)
{


	
}

void Sonicteam::SoX::Object::DestroyObject(unsigned int flag)
{

	Sonicteam::SoX::Object::~Object();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}

Sonicteam::SoX::ObjectRework::ObjectRework(void)
{

}

char* Sonicteam::SoX::ObjectRework::GetObjectType()
{
return "";
}

Sonicteam::SoX::ObjectRework::~ObjectRework(void)
{

}
