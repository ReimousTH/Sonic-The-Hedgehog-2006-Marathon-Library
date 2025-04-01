#ifndef SONICTEAM__SOX__ARCFILE
#define SONICTEAM__SOX__ARCFILE

#include <xtl.h>
#include <Sox/Defs.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/IResource.h>
#include <Sox/Misc/LinkSoxNode.h>



namespace Sonicteam{
	namespace SoX{

	
		class ArcFile{
		public:
			ArcFile();
			~ArcFile();
			DESTRUCTION_H;

			void* ArcHeaderData1; //4
			void* ArcHeaderData2; //8
			size_t Count1; //C
			void* ArcStringData; //10
			unsigned int unk0x14; //14

			
		};
	};
};



#endif