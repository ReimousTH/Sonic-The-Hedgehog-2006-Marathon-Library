#include "SpanSPSB.h"
using namespace Sonicteam::Spanverse;





Sonicteam::Spanverse::SpanSPSB::SpanSPSB(size_t count1,size_t count2):Sonicteam::Spanverse::ISpan()
{
	this->HEADER = SONICTEAM__SPANVERSE_HEADER__SPANSPSB;
	this->SpanFlag = 0;
	this->SpanSPMS = spanalloc(Sonicteam::Spanverse::SpanSPMS,count1);
	this->SpanSPCM = spanalloc2(Sonicteam::Spanverse::SpanSPCM);
	
}

Sonicteam::Spanverse::SpanSPSB::~SpanSPSB()
{

}

DESTRUCTION_CPP(SpanSPSB,SSINGLETON_INSTANCE(Sonicteam::SpanverseMemory)->HeapFree);

