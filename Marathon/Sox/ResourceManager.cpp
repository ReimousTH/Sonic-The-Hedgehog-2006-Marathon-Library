#include "ResourceManager.h"

#include <typeinfo>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <Sox/FileSystemARC.h>
#include <Sox/FileLoaderARC.h>
#include <Sox/FileHandleARC.h>

#include <../2006DLL_REWORK/Core/Debug.h>

using namespace Sonicteam::SoX;
DESTRUCTION_CPP(ResourceManager);

Sonicteam::SoX::ResourceManager::ResourceManager()
{

}

Sonicteam::SoX::ResourceManager::~ResourceManager()
{

}



void ResourceManager::RemoveResource(unsigned int* index ,std::string resource)
{ 

	std::map<unsigned int,std::map<std::string, Sonicteam::SoX::IResource*>>::iterator& it = this->ResourceRegistryHandle.find(*index);
	if ( it != this->ResourceRegistryHandle.end()){
		it->second.erase(resource);
		if (!it->second.size()){
			it->second.clear(); //probably
			Sonicteam::SoX::HoldMGR* hmgr =  &this->ManagerResouceMgr[*index];
			if (hmgr->Flag01){
				hmgr->Unk4(hmgr->Mgr);
				hmgr->Flag01= 0;
			}
		}

	}
}

//Sonicteam::SoX::IResourceMgrParam -> empty struct, defined for each MGR later on like , ArcHandleMgrParam:IResourceMgrParam{.....} etc
REF_TYPE(Sonicteam::SoX::IResource) ResourceManager::LoadResourceFromArc(Sonicteam::SoX::IResourceMgr* mgr,std::string file,std::string file_in_arc,Sonicteam::SoX::IResourceMgrParam* params,bool CheckInFileSystem)
{
	
	//PushBreakPoint(__FILE__,__LINE__," ResourceManager::LoadResourceFromArc,params : %x : %x : %x ",params,lr,lr1);

	bool loaded = false;
	REF_TYPE(Sonicteam::SoX::IResource) resource = 
		Sonicteam::SoX::ResourceManager::LoadResource(mgr, file, &loaded, params);

	if (!resource.get() || !loaded) 
		return 0;

	Sonicteam::SoX::IResource* res = resource.get();
	res->ResourceStr3 = file_in_arc;

	// Resource handling
	if (res->ResourceType()) 
	{
		std::string res_path = res->GetResourceName(file_in_arc);

		if (CheckInFileSystem && 
			!Sonicteam::SoX::FileSystemArc::getInstance().FSPathExist(res_path)) 
		{
			return 0;
		}

		// Create callback manually
			IFileLoader_BFUNCTION_TYPE callback = boost::bind(&Sonicteam::SoX::IResource::ResourceLoadFinal, res, _1, _2);

		REF_TYPE(Sonicteam::SoX::IFileHandle) file_handle = 
			Sonicteam::SoX::FileLoaderARC::getInstance().LoadFile(res_path, callback);

		Sonicteam::SoX::FileHandleARC* arc_handle = 
			static_cast<Sonicteam::SoX::FileHandleARC*>(file_handle.get());

		if (!arc_handle || !arc_handle->LoadHandle()) 
			return 0;

		return resource;
	}
	// Archive handling
	else 
	{
		return res->ResourceLoad(0, 0) ? resource : 0;
	}


}

// not 1:1 but close
extern "C" REF_TYPE(Sonicteam::SoX::IResource) ResourceManager::LoadResource(Sonicteam::SoX::IResourceMgr* mgr,std::string file,bool* result ,Sonicteam::SoX::IResourceMgrParam* params)
{
	unsigned int* index = ResourceManager::getInstance().InitializeManagerIndex(mgr);
	std::string resource_f_name = mgr->GetMgrResourceName(file);


	std::map<std::string, Sonicteam::SoX::IResource*>::iterator resource = 
		ResourceManager::getInstance().FindResource(index, resource_f_name);



	AddMessage("ResourceManager::LoadResource : %s : %s,",resource_f_name.c_str(),file.c_str());




	*result = false;

	// 1:1 with PPC assembly (matches lbz instruction at 82582434)
	if (true)
	{
		*result = true;
		if (resource->second == NULL) {
			Sonicteam::SoX::IResource* new_res = mgr->GetMgrResource(params);
			if (new_res) {
				new_res->SetResourceManagerMeta(index,resource_f_name,file);
				resource->second = new_res;
				return resource->second;
			}
			else {
				ResourceManager::getInstance().RemoveResource(index, resource_f_name);
				return NULL;
			}
		}

		// Matches AddReference call (825824E4)
		if (resource->second) {
			*result = true;
			return resource->second;
		}
	}

	// Failure path (matches loc_82582508)
	ResourceManager::getInstance().RemoveResource(index, resource_f_name);
	return NULL;

}

//Probably Should do same as original no idea about original code
extern "C" std::map<std::string, Sonicteam::SoX::IResource*>::iterator ResourceManager::FindResource(unsigned int* index,std::string str)
{
	std::map<std::string, Sonicteam::SoX::IResource*> handles =  this->ResourceRegistryHandle[*index];
	if (handles.empty()){
		Sonicteam::SoX::HoldMGR* mgr =  &this->ManagerResouceMgr[*index];
		if (!mgr->Flag01){
			mgr->Unk0(mgr->Mgr);
			mgr->Flag01 = 1;
		}
	}

	if (this->ResourceRegistryHandle[*index].find(str) == this->ResourceRegistryHandle[*index].end()){
		this->ResourceRegistryHandle[*index][str] = NULL;
	}

	//PushBreakPoint(__FILE__,__LINE__,"ResourceManager::FindResource : %s",str.c_str());
	return this->ResourceRegistryHandle[*index].find(str);
}


extern "C" void IResourceMgrF01(Sonicteam::SoX::IResourceMgr* mgr){
	mgr->IResourceMgr03impl();
}

extern "C" void IResourceMgrF02(Sonicteam::SoX::IResourceMgr* mgr){
	mgr->IResourceMgr04impl();
}


//work as 1:1 for 06 
unsigned int* ResourceManager::InitializeManagerIndex(Sonicteam::SoX::IResourceMgr* mgr)
{

	//PushBreakPoint(__FILE__,__LINE__,"InitializeManagerIndex : %x",mgr);

	if (!mgr->Flag1){
		Sonicteam::SoX::ResourceManager* r =  &Sonicteam::SoX::ResourceManager::getInstance();
		const char* mgr_type = typeid(*mgr).name();
		mgr->Flag1 = 1;
		mgr->MgrType = r->ManagerRegistryIndex.size();
		r->ManagerRegistryIndex[mgr_type] = mgr->MgrType;

		//PushBreakPoint(__FILE__,__LINE__,"InitializeManagerIndex : %s",mgr_type);

		HoldMGR hold_mgr;
		hold_mgr.Unk0 = &IResourceMgrF01;
		hold_mgr.Unk4 = &IResourceMgrF02;
		hold_mgr.Flag01 = 0;
		hold_mgr.Flag02 = 0;
		hold_mgr.Mgr = mgr;
		r->ManagerResouceMgr[mgr->MgrType] =hold_mgr;
	}
	//PushBreakPoint(__FILE__,__LINE__,"ResourceManager::InitializeManagerIndex : %d for mgr %x",mgr->MgrType,mgr);
	return &mgr->MgrType;
}	

