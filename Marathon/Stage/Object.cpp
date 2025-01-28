#include "Object.h"


using namespace Sonicteam;



int Sonicteam::Stage::Object::OnMessageRecieved(Sonicteam::SoX::Message* a2)
{
	int result; // r3

	switch ( a2->MessageInfo )
	{
	case 0x11004:
		a2->MessageInfo2 = 5;
		break;
	case 0x11006:
		a2->MessageInfo2 |= 0x01000000;
		break;
	case 0x1805A:
		break;
	default:
		return 0;
	}
	return 1;
}

char* Sonicteam::Stage::Object::GetObjectType()
{
	return "Stage::Object";
}

Sonicteam::Stage::Object::~Object()
{

}

Sonicteam::Stage::Object::Object()
{

}

void Sonicteam::Stage::Object::DestroyObject(unsigned int flag)
{
	Sonicteam::Stage::Object::~Object();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}
