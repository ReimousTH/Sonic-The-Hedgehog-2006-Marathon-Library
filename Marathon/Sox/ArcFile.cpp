#include "ArcFile.h"
using namespace Sonicteam::SoX;


ArcFile::ArcFile()
{

}

ArcFile::~ArcFile()
{

}
DESTRUCTION_CPP(ArcFile);


ArcFileChunkF::ArcFileChunkF()
{

}

ArcFileChunkF::ArcFileChunkF(ArcFileChunk& chunk)
{
	this->Offset = chunk.Offset;
	this->CompressedSize = chunk.CompressedSize;
	this->IsDirectory = chunk.DecompressedSize == 0;
	this->DecompressedSize = chunk.DecompressedSize;
	

}
