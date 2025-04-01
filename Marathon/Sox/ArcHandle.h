#ifndef SONICTEAM__SOX__ARCHANDLE
#define SONICTEAM__SOX__ARCHANDLE

#include <xtl.h>
#include <Sox/Defs.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/IResource2.h>
#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/ArcFile.h>
#include <Sox/ArcHandleMgr.h>



namespace Sonicteam{
	namespace SoX{



		class ArcHandle:IResource2HR(Sonicteam::SoX::ArcHandle,Sonicteam::SoX::ArcHandleMgr){

		public:
			ArcHandle();
			~ArcHandle();
			DESTRUCTION_H;
			LinkSoxNode<ArcHandle> LinkArcHandle; //0x64,0x68,0x6C
			Sonicteam::SoX::ArcFile _ArcFile; //0x70 
			void* HandleBuffer; //loaded-data (0x88) (from start)
			size_t unk0x8C;
			char IsFixedArchive; 
			char IsDownloadContent;
			char unk0x92; //padding
			char unk0x93; //padding
			std::string ArcFilePath; // game:\common\Resources_scripts_4P.arc 0x94  (+)
			HANDLE ArcFileHandle; //0xB0(need close btw)
		};
	};
};

#endif