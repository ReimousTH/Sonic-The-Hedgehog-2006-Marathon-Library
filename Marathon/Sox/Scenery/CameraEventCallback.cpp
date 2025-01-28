#include "CameraEventCallback.h"


using namespace Sonicteam::SoX::Scenery;


Sonicteam::SoX::Scenery::CameraEventCallback::CameraEventCallback()
{

}

Sonicteam::SoX::Scenery::CameraEventCallback::~CameraEventCallback()
{

}

void Sonicteam::SoX::Scenery::CameraEventCallback::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}
