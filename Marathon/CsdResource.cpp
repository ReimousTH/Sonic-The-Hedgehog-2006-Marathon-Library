#include "CsdResource.h"
#include <Sox/FileSystemARC.h>

using namespace Sonicteam;

DESTRUCTION_CPP(CsdResource);

Sonicteam::CsdResource::CsdResource(void)
{

}

Sonicteam::CsdResource::~CsdResource(void)
{
	delete _CSDFile;
}


std::string CsdResource::GetResourceName(std::string file_name)
{
	Sonicteam::SoX::FileSystemArc* sarc = &Sonicteam::SoX::FileSystemArc::getInstance();
	file_name.append(".xncp");
	return sarc->FSGetPath(file_name,Win32Folder);


}



int CsdResource::ResourceLoad(void* File,size_t size)
{
	Sonicteam::CsdManager* mgr  =  this->GetManager();
	const char* str3 =  this->ResourceStr3.c_str();
	memcpy(&mgr->_csd_info_,(void*)str3,strlen(str3)+1);
	this->_CSDFile = (CSDFile*)malloc(size + 0x20);
	this->_CSDSize = size;
	if (this->_CSDFile){
		memcpy((void*)this->_CSDFile,File,size);
		return 1;
	}

	return 0;
}

