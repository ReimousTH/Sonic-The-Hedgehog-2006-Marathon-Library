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


DESTRUCTION_CPP(Object);


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
