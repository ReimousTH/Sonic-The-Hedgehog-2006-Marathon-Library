#ifndef SONICTEAM__SOX__ARCFILE
#define SONICTEAM__SOX__ARCFILE

#include <xtl.h>
#include <Sox/Defs.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/IResource.h>
#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/Misc/Aligment.hpp>


namespace Sonicteam{
	namespace SoX{

		struct ArcFileChunk;
		struct ArcFileChunkF;
	
		alignas_4 struct ArcFileChunkF{
		public:
			void* Offset; //offset-in-arc 0
			size_t CompressedSize; //4
			char IsCompressed; // 8
			size_t DecompressedSize;// C

			ArcFileChunkF();
			ArcFileChunkF(ArcFileChunk&);
		};




		struct size_t_24 {
			unsigned char bytes[3]; 
			size_t to_size_t() const {
				return (bytes[0] << 16) | (bytes[1] << 8) | bytes[2];
			}
			void from_size_t(size_t value) {
				bytes[0] = static_cast<char>((value >> 16) & 0xFF); 
				bytes[1] = static_cast<char>((value >> 8)  & 0xFF);
				bytes[2] = static_cast<char>(value & 0xFF);         
			}
			operator size_t() const { return to_size_t(); }
			size_t_24& operator=(size_t value) { from_size_t(value); return *this; }
		};

	
		 union _ChunkInfo {
			enum _ChunkInfo_Type:byte{
				File,
				Directory
			};
			struct {
				_ChunkInfo_Type Type;
				size_t_24 NameOffset;
			};
		};


		alignas_4 struct ArcFileChunk{
		public:
			_ChunkInfo Info;
			void* Offset; //4
			size_t CompressedSize; //8
			size_t DecompressedSize;// C
		};

	

		alignas_4 struct ArcFileHeader{
			typedef union SIGHEADER{
				char _char[4];
				unsigned __int32 _dword;
			} Signature; //0
			void* ChunkOffset; //4
			size_t ChunkLength; //8
			void* Data; //C
			char metadata[0x10]; //metatada(time, no idea how to extract ) int date,int time,int meta,int padding 0x10
		};


	
		class ArcFile{
		public:
			ArcFile();
			~ArcFile();
			DESTRUCTION_H;

			void* RawChunk; //4 (this only to destroy)
			ArcFileChunk* ChunkArray; //8 (array)
			size_t ChunkArraySize; //C (not count)
			void* ChunkStringOffset; //0x10
			unsigned int RootIndex; //14

			
		};
	};
};



#endif