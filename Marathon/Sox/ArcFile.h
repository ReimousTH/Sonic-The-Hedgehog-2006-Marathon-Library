#ifndef SONICTEAM__SOX__ARCFILE
#define SONICTEAM__SOX__ARCFILE

#include <xtl.h>
#include <Sox/Defs.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/IResource.h>
#include <Sox/Misc/LinkSoxNode.h>



namespace Sonicteam{
	namespace SoX{

		struct ArcFileChunk;
		struct ArcFileChunkF;
	
		alignas_4 struct ArcFileChunkF{
		public:
			void* Offset; //offset-in-arc 0
			size_t CompressedSize; //4
			char IsDirectory; // ?guess
			size_t DecompressedSize;// 8

			ArcFileChunkF();
			ArcFileChunkF(ArcFileChunk&);

			
		};

		alignas_4 struct ArcFileChunk{
		public:
			enum _ChunkInfo_Type:byte{
				File,
				Directory
			};
			typedef union _ChunkInfo{
				_ChunkInfo_Type Type; //(first 16 bit)
				size_t NameOffset:16; //other
			} Info;
			void* Offset; //4
			size_t CompressedSize; //8
			size_t DecompressedSize;// C
		};

	

	
		class ArcFile{
		public:
			ArcFile();
			~ArcFile();
			DESTRUCTION_H;

			void* ArcHeader; //4 (this only to destroy)
			ArcFileChunk* ArcChunk; //8 (array)
			size_t ArcChunkCount; //C
			void* ArcStringData; //10
			unsigned int unk0x14; //14

			
		};
	};
};



#endif