#include "ArcFile.h"
using namespace Sonicteam::SoX;


ArcFile::ArcFile()
{

}

ArcFile::~ArcFile()
{
	free(RawChunk);

}
DESTRUCTION_CPP(ArcFile);


ArcFileChunkF::ArcFileChunkF()
{

}

ArcFileChunkF::ArcFileChunkF(ArcFileChunk& chunk)
{
	this->Offset = chunk.Offset;
	this->DecompressedSize = chunk.DecompressedSize;
	this->CompressedSize = chunk.CompressedSize;
	this->IsCompressed = (bool)chunk.DecompressedSize; // (_cntlzw(chunk->DecompressedSize) & 0x20) == 0; correct
}
