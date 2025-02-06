#include "CsdLink.h"

using namespace Sonicteam;
Sonicteam::CsdLink::CsdLink(void)
{
	this->FCsdLink0x4 = 0;
	this->FCsdLink0x8 = 0;
	this->FCsdLink0xC = 10.0;
	this->FCsdLink0x10 = 0;
	this->FCsdLink0x14 = 0xFFFFFFFF;
}

Sonicteam::CsdLink::~CsdLink(void)
{

}

DESTRUCTION_CPP(CsdLink);

