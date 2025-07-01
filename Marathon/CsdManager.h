#ifndef SONICTEAM__CSDMANAGER
#define SONICTEAM__CSDMANAGER

#include "Defs.h"
#include <Sox/IResourceMgr.h>
#include <boost/shared_ptr.hpp>


//NO IDEA ABOUT SIZE ???? probably  (MAX_PATH for now)
#define SCDMR_INFO_SIZE MAX_PATH 

namespace Sonicteam{



	//Or SonicTeamSoxComponent
	class CsdManager:IResourceMgrHRS(CsdManager) 
		{
		public:
			CsdManager(void);
			~CsdManager(void);

			DESTRUCTION_H;
			
			Sonicteam::CsdObject* CsdObject; //0x10
			Sonicteam::CsdLink* CsdLink;  //0x14
			size_t CsdID; //??? 0x18
			size_t unk0x1C; //?? 0x1C (flag)
			boost::shared_ptr<Sonicteam::CPlatformMarathon> CPlatform;  // Sonicteam::CPlatformMarathon 0x20 -0x24
			CRITICAL_SECTION CSDSync; //0x28-0x1C
			char _csd_info_[SCDMR_INFO_SIZE]; //44

			
		






			virtual Sonicteam::SoX::IResource* GetMgrResource(Sonicteam::SoX::IResourceMgrParam* param);
			virtual std::string GetMgrResourceName(std::string resouce);

	};

};

#endif