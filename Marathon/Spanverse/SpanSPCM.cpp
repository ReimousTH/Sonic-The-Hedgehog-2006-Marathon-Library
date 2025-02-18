#include "SpanSPCM.h"
using namespace Sonicteam::Spanverse;







Sonicteam::Spanverse::SpanSPCM::SpanSPCM():Sonicteam::Spanverse::ISpan()
{
	this->HEADER = SONICTEAM__SPANVERSE_HEADER__SPANSPCM;
	this->SpanFlag = 0;
	this->Transform = XMMATRIX();
	this->Vector1 = XMFLOAT3(0,0,200);
	this->Vector1 = XMFLOAT3(0,0,0);
	this->Vector1 = XMFLOAT3(0,1,0);
	this->unk0x80 = 0;
	this->unk0x88 = 1.0;
	this->unk0x8C = 10000.0;;
	this->unk0x94 = 0x1FFE;
	this->unk0x98 = 1;

}

Sonicteam::Spanverse::SpanSPCM::~SpanSPCM()
{

}

DESTRUCTION_CPP(SpanSPCM,SSINGLETON_INSTANCE(Sonicteam::SpanverseMemory)->HeapFree);

