#include "TextureXenon.h"


using namespace Sonicteam::SoX::Graphics::Xenon;




TextureXenon::TextureXenon()
{

}

TextureXenon::~TextureXenon()
{

}

unsigned int TextureXenon::GetTXFlag1()
{
	return this->TFlag1;
}

unsigned int TextureXenon::GetTXFlag2()
{
	return this->TFlag2;
}

REF_TYPE(Sonicteam::SoX::Graphics::Xenon::SurfaceXenon) TextureXenon::GetSurface(unsigned int index)
{
	return this->Surface[index];
}

bool TextureXenon::GetSurfaceRoot(void* out1,void* out2)
{
	return true; //finish later
}

void TextureXenon::ProcessSurfaceRoot(unsigned int flag)
{

}

REF_TYPE(Sonicteam::SoX::Graphics::Xenon::TextureXenon) TextureXenon::LoadTexture(std::string& textype)
{
	return 0;
}
DESTRUCTION_CPP(TextureXenon);
