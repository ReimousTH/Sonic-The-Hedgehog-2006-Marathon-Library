#include "GenerateArea.h"

Sonicteam::Prop::GenerateArea::GenerateArea()
{

}

Sonicteam::Prop::GenerateArea::~GenerateArea()
{

}

void Sonicteam::Prop::GenerateArea::DestroyObject(unsigned int flag)
{
	Sonicteam::Prop::GenerateArea::~GenerateArea();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);

}
