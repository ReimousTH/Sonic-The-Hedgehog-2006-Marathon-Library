#include "SpanSBMB.h"
using namespace Sonicteam::Spanverse;





Sonicteam::Spanverse::SpanSBMB::SpanSBMB():ISpan()
{
	this->HEADER = SONICTEAM__SPANVERSE_HEADER__SPANSBMB;
	this->link_data =0;
	this->SpanFlag =0;
	
}

Sonicteam::Spanverse::SpanSBMB::~SpanSBMB()
{
	SBMBLinkNode* Next = link_data->Next;
	while (Next){
		SBMBLinkNode* Cur = Next;
		Next = Next->Next;
		spanafree(Next);
	}
}


DESTRUCTION_CPP(SpanSBMB,SSINGLETON_INSTANCE(Sonicteam::SpanverseMemory)->HeapFree);
