#ifndef SONICTEAM__SOX__IRESOURCEMGR
#define SONICTEAM__SOX__IRESOURCEMGR




#include <Sox/Memory/Destruction.h>
#include <Sox/IResource.h>

namespace Sonicteam{
	namespace SoX{


		struct IResourceMgrParam{
			unsigned int unk0x0;
			bool SaveResource;
			//padding ->4 (more more data?)

			IResourceMgrParam(){};
			IResourceMgrParam(unsigned int param1, bool SaveResource):unk0x0(param1),SaveResource(SaveResource){};
		};


		class IResourceMgr
		{
		public:
			IResourceMgr(void);
			~IResourceMgr(void);

			DESTRUCTION_H;
			//despite IResource (RefCountObj i should use REF_TYPE(), but there is none of code so )
			virtual Sonicteam::SoX::IResource* GetMgrResource(Sonicteam::SoX::IResourceMgrParam& param);
			virtual std::string GetMgrResourceName(std::string resouce);

		};
	}
}



#endif

