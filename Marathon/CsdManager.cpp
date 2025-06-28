#include "CsdManager.h"
#include <CsdResource.h>

using namespace Sonicteam;

CsdManager::CsdManager(void)
{
	this->CsdObject = 0;
	this->CsdLink = 0;
	this->CsdID = 0;
	this->unk0x1C = 0;
	//this->CPlatform = 0;
	EnterCriticalSection(&this->CSDSync); //not FREED after why?

}

CsdManager::~CsdManager(void)
{

}

Sonicteam::SoX::IResource* CsdManager::GetMgrResource(Sonicteam::SoX::IResourceMgrParam& param)
{
	return new Sonicteam::CsdResource();
}

std::string CsdManager::GetMgrResourceName(std::string resouce)
{
	return resouce;
}

DESTRUCTION_CPP(CsdManager);
