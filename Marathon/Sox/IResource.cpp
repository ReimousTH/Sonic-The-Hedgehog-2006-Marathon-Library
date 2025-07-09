#include "IResource.h"


using namespace Sonicteam::SoX;

IResource::IResource(void)
{

}

IResource::~IResource(void)
{
	//remove-resource
	if (IsInResourceManager){
		Sonicteam::SoX::ResourceManager* mgr =  &Sonicteam::SoX::ResourceManager::getInstance();
		mgr->ResourceRegistryHandle[MgrRegistryIndex].erase(mgr->ResourceRegistryHandle[MgrRegistryIndex].find(this->ResourceMgrName));
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


bool IResource::ResourceLoadFinal(void* File,unsigned __int64 size)
{
	
	return this->ResourceLoad(File,size);
}

void IResource::SetResourceManagerMeta(unsigned int* i,std::string& m,std::string& r)
{ 

	this->ResourceMgrName = m;
	this->ResourceName = r;
	this->MgrRegistryIndex = *i;
	this->IsInResourceManager = 1;
}

