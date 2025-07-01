#include "IResourceMgr.h"
#include <Sox/ResourceManager.h>
#include <typeinfo>

using namespace Sonicteam::SoX;

Sonicteam::SoX::IResourceMgr::IResourceMgr(void)
{

}

Sonicteam::SoX::IResourceMgr::~IResourceMgr(void)
{

}



extern "C" void IResourceMgrF01(Sonicteam::SoX::IResourceMgr* mgr){
	mgr->IResourceMgr03impl();
}

extern "C" void IResourceMgrF02(Sonicteam::SoX::IResourceMgr* mgr){
	mgr->IResourceMgr04impl();
}

REF_TYPE(Sonicteam::SoX::IResource) IResourceMgr::LoadFromArc(std::string file_name,std::string file_name_2,int directory,bool show_errors)
{


	Sonicteam::SoX::ResourceManager* mgr =  &Sonicteam::SoX::ResourceManager::getInstanceQuick();

	//sub_82581F78
	if (!Flag1){

		std::type_info* info  = (std::type_info*)&typeid(this);
		const char* className = info->name();

		int newIndex = mgr->ManagerRegistryIndex.size(); // Next index = current size
		mgr->ManagerRegistryIndex[className] =  newIndex;
		this->MgrType = newIndex;

		HoldMGR hold_mgr;
		hold_mgr.Unk0 = &IResourceMgrF01;
		hold_mgr.Unk4 = &IResourceMgrF02;
		hold_mgr.Flag01 = 1;
		hold_mgr.Flag02 = newIndex;
		mgr->ManagerResouceMgr[newIndex] =hold_mgr;
	}

	unsigned int* return_index = &this->MgrType;


	return 0;
}

void IResourceMgr::IResourceMgr03impl()
{

}

void IResourceMgr::IResourceMgr04impl()
{

}

std::string IResourceMgr::GetMgrResourceName(std::string resouce)
{
	return resouce;
}

DESTRUCTION_CPP(IResourceMgr);

