#include "ISpan.h"
using namespace Sonicteam::Spanverse;




DESTRUCTION_CPP(ISpan,SSINGLETON_INSTANCE(Sonicteam::SpanverseMemory)->HeapFree);

Sonicteam::Spanverse::ISpan::ISpan()
{
	this->HEADER = SONICTEAM__SPANVERSE_HEADER__ISPAN;
	this->unk0x8 = 0;
	this->SpanFlag = 0;
	this->SpanverseHeapInstance = Sonicteam::SpanverseHeap::SpanInstance;

}

Sonicteam::Spanverse::ISpan::~ISpan()
{

}
