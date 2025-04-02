#ifndef SONICTEAM__SOX__FILEHANDLEARC
#define SONICTEAM__SOX__FILEHANDLEARC

#include <Sox/Defs.h>
#include <Sox/IFileHandle.h>
#include <Sox/Misc/Aligment.hpp>
#include <Sox/ArcHandleMgr.h>

#include <iostream>
#include <string>

namespace Sonicteam{
	namespace SoX{

	

		//this is the best that i can think
		alignas_4 class FileHandleARC:public Sonicteam::SoX::IFileHandle
		{

		public:	
			FileHandleARC();
			FileHandleARC(std::string&,IFileHandle_BFUNCTION_TYPE);
			~FileHandleARC();
			DESTRUCTION_H;
			virtual bool LoadHandle();
			virtual unsigned __int64 GetHandleSize();
			virtual void* GetHandleBuffer();
			void LoadFileFromArc(Sonicteam::SoX::ArcHandleSearchResource& res);
			bool SearchChunk(Sonicteam::SoX::ArcHandleMgr* mgr,std::string& search_path,Sonicteam::SoX::ArcHandleSearchResource& search_chunk);
			size_t FileHandleARC::SearchChunkEntry(
				Sonicteam::SoX::ArcHandle* handle,
				Sonicteam::SoX::ArcFileChunk* Chunk,
				size_t ChunkCount,
				size_t index,
				std::string& search_path,
				std::string current_path,
				size_t& find_index);
			std::string filepath; //8 (game:\xenon\registry.lub)
			char IsLoaded; //0x24
			char IsProcess; //0x25
			unsigned __int64 size; //0x28-0x2C
			void* HBuffer;  //0x30
			IFileHandle_BFUNCTION_TYPE func0x34; //0x34-0x38-0x3C
		};

	};
};
#endif