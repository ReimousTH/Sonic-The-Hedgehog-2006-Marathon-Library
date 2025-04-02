#ifndef SONICTEAM__SOX__ARCHANDLEMGR
#define SONICTEAM__SOX__ARCHANDLEMGR

#include <xtl.h>


#include <Sox/Defs.h>
#include <sox/IResourceMgr.h>
#include <System/Singleton.h>
#include <System/CreateStatic.h>
#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/ArcHandle.h>
#include <Sox/Misc/Aligment.hpp>


namespace Sonicteam{
	namespace SoX{



	

		alignas_4 struct ArcHandleSearchResource{
			const char* arc_path; //0
			void* arc_buffer; //4
			void* ResourceOffset; //8
			size_t ResourceCompressedSize; //0xC;
			size_t ResourceDecompressedSize; //0x10;
			char IsCompressed;// i guess 0x14
			char IsDownloadContent; //0x15
			Sonicteam::SoX::ArcHandle* Handle; //0x18
		};
	
		class ArcHandleMgr:Sonicteam::SoX::IResourceMgr,public SSINGLETON(ArcHandleMgr){
		public:
			ArcHandleMgr();
			~ArcHandleMgr();
			DESTRUCTION_H;
			LinkSoxNode<Sonicteam::SoX::ArcHandle> LinkArcHandle; //0x10,0x14,0x18
			std::string RootPath; //game:\ (0x1C)


			virtual Sonicteam::SoX::IResource* GetMgrResource(Sonicteam::SoX::IResourceMgrParam& param);
			virtual std::string GetMgrResourceName(std::string resouce);
			virtual void IResourceMgr03impl();
			virtual void IResourceMgr04impl();

		};
	};
};



#endif