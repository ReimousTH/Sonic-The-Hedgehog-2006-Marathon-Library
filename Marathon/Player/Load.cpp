#include "Load.h"

using namespace Sonicteam::Player;




Sonicteam::Player::Load::Load(Sonicteam::SoX::Engine::Doc* doc):ILoad()
{


	//later




}


Sonicteam::Player::Load::~Load(void)
{

}


void Sonicteam::Player::Load::DestroyObject(unsigned int flag)
{
	throw std::logic_error("The method or operation is not implemented.");
}

Sonicteam::SoX::RefCountObject Sonicteam::Player::Load::LoadPackage(std::string* package_path)
{
	throw std::logic_error("The method or operation is not implemented.");
}

Sonicteam::DocMarathonPlayerInput* Sonicteam::Player::Load::GetInputFCopy(Sonicteam::DocMarathonPlayerInput* out_input,int index)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Sonicteam::Player::Load::ProcessFrame(Sonicteam::SoX::Graphics::Frame** PlayerFrame)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Sonicteam::Player::Load::ProcessClump01(Sonicteam::SoX::RefCountObject** obj)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Sonicteam::Player::Load::ProcessClump02(Sonicteam::SoX::RefCountObject** obj)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Sonicteam::Player::Load::ProcessClump02_01(Sonicteam::SoX::RefCountObject** obj)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Sonicteam::Player::Load::ProcessClump02_02(Sonicteam::SoX::RefCountObject** obj)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Sonicteam::Player::Load::ILoadUnknown()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Sonicteam::Player::Load::ProcessClump02_03(Sonicteam::SoX::RefCountObject** obj)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void* Sonicteam::Player::Load::GetDGraphicDevice()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void* Sonicteam::Player::Load::GetDUnkModules()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Sonicteam::Player::Load::DocProcessSFX(Sonicteam::SoX::RefCountObject**)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Sonicteam::Player::Load::DocProcessThread(Sonicteam::SoX::StepableThread*)
{
	throw std::logic_error("The method or operation is not implemented.");
}

Sonicteam::Player::PLoadBodyPackage::PLoadBodyPackage()
{

}

Sonicteam::Player::PLoadHeadPackage::PLoadHeadPackage()
{

}

Sonicteam::Player::PLoadHeadPackage::~PLoadHeadPackage()
{

}
