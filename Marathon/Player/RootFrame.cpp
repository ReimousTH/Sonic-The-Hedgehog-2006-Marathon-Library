#include "RootFrame.h"

using namespace Sonicteam::Player;


void Sonicteam::Player::RootFrame::DestroyObject(unsigned int flag)
{
	Sonicteam::Player::RootFrame::~RootFrame();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}


//Have no idea why 06 Compiled this with Vector function but maybe optimization flag or some
XMMATRIX Sonicteam::Player::RootFrame::FrameGetTransformMatrix1()
{
	return  RFTransformMatrix0xB0;

}

XMMATRIX Sonicteam::Player::RootFrame::FrameGetTransformMatrix2()
{
	return RFTransformMatrix0x70;
}

void Sonicteam::Player::RootFrame::FrameSetTransformMatrix2(XMMATRIX& value)
{
	this->RFTransformMatrix0x70 = value;
}

void Sonicteam::Player::RootFrame::FrameUnk06(XMMATRIX&)
{

}

void Sonicteam::Player::RootFrame::FrameUnk07()
{
	
}

Sonicteam::Player::RootFrame::RootFrame(void):Sonicteam::Player::IPlugIn("frame")
{
}

Sonicteam::Player::RootFrame::~RootFrame(void)
{

}

unsigned long long Sonicteam::Player::RootFrame::ExportExternalFlag(void)
{
	return this->ExternalFlag;
}
