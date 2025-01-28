#include "CPlatformMarathon.h"

using namespace Sonicteam;

void Sonicteam::CPlatformMarathon::DebugMessageA(LPCSTR lpOutputString)
{
	OutputDebugStringA(lpOutputString);
}

int Sonicteam::CPlatformMarathon::GetCPlatform0x8()
{
	return 1;
}

void Sonicteam::CPlatformMarathon::CPDrawPrimiteCache0xC(unsigned int)
{
	// TODO: Implement CPDrawPrimiteCache0xC
}

void Sonicteam::CPlatformMarathon::CPSSetDrawPrimiteFlag0x10(unsigned int flag)
{
	this->FCPlatformFlag0x8 = flag;
}

void Sonicteam::CPlatformMarathon::CPlatform0x14(unsigned int, unsigned int)
{
	// TODO: Implement CPlatform0x14
}

void Sonicteam::CPlatformMarathon::CPlatform0x18()
{
	return;
}

void Sonicteam::CPlatformMarathon::CPSSetDrawPrimiteFlagA0x1C(unsigned int flag)
{
	return CPSSetDrawPrimiteFlag0x10(flag);
}

void Sonicteam::CPlatformMarathon::CPlatform0x20(unsigned int, unsigned int)
{
	// TODO: Implement CPlatform0x20
}

void Sonicteam::CPlatformMarathon::CPlatform0x24()
{
	CPlatform0x18();
}

void Sonicteam::CPlatformMarathon::CPDrawPrimiteCache0x28()
{
	// TODO: Implement CPDrawPrimiteCache0x28
}

void Sonicteam::CPlatformMarathon::CPDrawPrimiteCache0x2C()
{
	// TODO: Implement CPDrawPrimiteCache0x2C
}

Sonicteam::CPlatformMarathon::CPlatformMarathon(void)
{

}

Sonicteam::CPlatformMarathon::~CPlatformMarathon(void)
{

}
