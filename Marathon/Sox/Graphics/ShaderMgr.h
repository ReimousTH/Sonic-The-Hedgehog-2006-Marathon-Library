#ifndef Sonicteam__SOX__Graphics__SHADERMGR
#define Sonicteam__SOX__Graphics__SHADERMGR

#include "Defs.h"
#include <Sox/IResourceMgr.h>
#include <System/Singleton.h>
#include <System/CreateStatic.h>




namespace Sonicteam{
	namespace SoX{
		namespace Graphics{
			class ShaderMgr:public Sonicteam::SoX::IResourceMgr,public SSINGLETON(ShaderMgr)
			{

				DESTRUCTION_H;

			public:
				virtual Sonicteam::SoX::IResource* GetMgrResource(Sonicteam::SoX::IResourceMgrParam* param);
				virtual std::string GetMgrResourceName(std::string resouce);
				virtual void IResourceMgr03impl();
				virtual void IResourceMgr04impl();


			};
		};
	};
};


#endif
