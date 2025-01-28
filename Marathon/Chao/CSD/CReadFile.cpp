#include "CReadFile.h"


using namespace Chao::CSD;


Chao::CSD::CReadFile::CReadFile(void)
{

}

Chao::CSD::CReadFile::~CReadFile(void)
{

}

void Chao::CSD::CReadFile::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}
