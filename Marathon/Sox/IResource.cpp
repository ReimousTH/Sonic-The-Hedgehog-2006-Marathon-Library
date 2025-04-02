#include "IResource.h"


using namespace Sonicteam::SoX;

IResource::IResource(void)
{

}

IResource::~IResource(void)
{
	//remove-resource
	if ((this->IResouceUnk60 & 0x01000000) != 0){
		Sonicteam::SoX::ResourceManager* mgr =  &Sonicteam::SoX::ResourceManager::getInstance();
		mgr->ResourceRegistryHandle[MgrRegistryIndex].erase(mgr->ResourceRegistryHandle[MgrRegistryIndex].find(this->ResourceStr1));
	} 
}

int IResource::ResouceUnk02()
{

	return 0;
}

int IResource::ResourceType()
{
	return 1;
}

DESTRUCTION_CPP(IResource);