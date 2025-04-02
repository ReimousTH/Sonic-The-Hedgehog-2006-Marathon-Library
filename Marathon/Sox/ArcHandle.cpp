#include "ArcHandle.h"
using namespace Sonicteam::SoX;


DESTRUCTION_CPP(ArcHandle);

ArcHandle::ArcHandle()
{

}

ArcHandle::~ArcHandle()
{
	if (this->FileHandle != INVALID_HANDLE_VALUE) CloseHandle(this->FileHandle);
	delete this->HandleBuffer;
	this->LinkHandle.SafeDisconnect();
}
