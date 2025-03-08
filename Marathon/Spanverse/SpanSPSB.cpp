#include "SpanSPSB.h"
using namespace Sonicteam::Spanverse;





Sonicteam::Spanverse::SpanSPSB::SpanSPSB(size_t count1,size_t count2):Sonicteam::Spanverse::ISpan()
{
	this->HEADER = SONICTEAM__SPANVERSE_HEADER__SPANSPSB;
	this->SpanFlag = 0;
	this->SpanSPMS = spanalloc(Sonicteam::Spanverse::SpanSPMS,count1);
	this->SpanSPCM = spanalloc2(Sonicteam::Spanverse::SpanSPCM);
	this->count2 = count2;
	this->unk0x50 = 0x400;
	this->Vector0x30 = XMVectorSet(0,0,0,0);
	this->Vector0x40 = XMVectorSet(0,300,1000,0);
	this->unk0x54 = 0x300;

	this->array2 = malloc(0x50*count2);
	memset(this->array2,0,0x50*count2);
	this->Transform = XMMATRIX(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	if (!this->SpanSPCM || !this->SpanSPMS){
		SpanFlag |= 2;
	}




	
}


Sonicteam::Spanverse::SpanSPSB::~SpanSPSB()
{

	spanafree(this->SpanSPMS); //DestoryObjectCall
	spanafree(this->SpanSPCM); //DestroyJectClass
	free(this->array2);

}

DESTRUCTION_CPP(SpanSPSB,SSINGLETON_INSTANCE(Sonicteam::SpanverseMemory)->HeapFree);

