#ifndef SONICTEAM__SOX__IRESOURCEMGR
#define SONICTEAM__SOX__IRESOURCEMGR


#include <Sox/Defs.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/IResource.h>


//:public Sonicteam::SoX::IResourceMgr,public SSINGLETON(ArcHandleMgr)
#define  IResourceMgrHRS(MGR) public Sonicteam::SoX::IResourceMgr,public SSINGLETON(MGR)




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

			unsigned int MgrType; // -index
			char Flag1; // 8
			char Flag2; //9
			char Flag3; //A
			char Flag4; //B
			unsigned int unk0xC; //0xC


	
			DESTRUCTION_H;
			//despite IResource (RefCountObj i should use REF_TYPE(), but there is none of code so )
			virtual Sonicteam::SoX::IResource* GetMgrResource(Sonicteam::SoX::IResourceMgrParam& param) = 0;
			virtual std::string GetMgrResourceName(std::string resouce);
			virtual void IResourceMgr03impl();
			virtual void IResourceMgr04impl();

		};
	}
}



#endif

