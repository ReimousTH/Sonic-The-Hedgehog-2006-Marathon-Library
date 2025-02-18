#include "SpanSPMS.h"
using namespace Sonicteam::Spanverse;





Sonicteam::Spanverse::SpanSPMS::SpanSPMS(size_t TransformAllocCount):ISpan()
{
	this->HEADER = SONICTEAM__SPANVERSE_HEADER__SPANSPMS;
	this->SpanFlag =  0;
	this->TransformFirst = new (Sonicteam::Spanverse::ISpan::SpanverseHeapInstance->HeapAlloc(TransformAllocCount * sizeof(XMMATRIX),0)) XMMATRIX();
	this->TransformCount = 0;
	this->TransformEnd = 0;
	this->TransformLast = 0;
	if (this->TransformFirst){
		this->TransformLast = this->TransformFirst;
		this->TransformEnd = this->TransformFirst;
	}
	else{
		this->SpanFlag |= 2;
	}
	
}

Sonicteam::Spanverse::SpanSPMS::~SpanSPMS()
{
	Sonicteam::Spanverse::ISpan::SpanverseHeapInstance->HeapFree(this->TransformFirst,0);

}


DESTRUCTION_CPP(SpanSPMS,SSINGLETON_INSTANCE(Sonicteam::SpanverseMemory)->HeapFree);
