#ifndef SONICTEAM__SOX__ARCHANDLEMGR
#define SONICTEAM__SOX__ARCHANDLEMGR

#include <xtl.h>


#include <Sox/Defs.h>
#include <sox/IResourceMgr.h>
#include <System/Singleton.h>
#include <System/CreateStatic.h>
#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/ArcHandle.h>



namespace Sonicteam{
	namespace SoX{


	
		class ArcHandleMgr:Sonicteam::SoX::IResourceMgr,SSINGLETON(ArcHandleMgr){
		public:
			ArcHandleMgr();
			~ArcHandleMgr();
			DESTRUCTION_H;
			LinkSoxNode<Sonicteam::SoX::ArcHandle> LinkArcHandle; //0x10,0x14,0x18
			std::string RootPath; //game:\ (0x1C)

		};
	};
};



#endif