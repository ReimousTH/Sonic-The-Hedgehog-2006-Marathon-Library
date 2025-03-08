#ifndef SONICTEAM__SPANVERSEMEMORY
#define SONICTEAM__SPANVERSEMEMORY

#include <Sox/Memory/Destruction.h>
#include <SpanverseHeap.h>

#include <System/CreateStatic.h>
#include <System/Singleton.h>





namespace Sonicteam{

	class SpanverseMemory:public SpanverseHeap{
	public:
		SpanverseMemory();
		~SpanverseMemory();
		DESTRUCTION_H;
	};

};


#define spanafree(CLASS) SSINGLETON_INSTANCE(Sonicteam::SpanverseMemory)->HeapFree(CLASS)
#define spanadelete(CLASS) \
CLASS::~CLASS(); \
SSINGLETON_INSTANCE(Sonicteam::SpanverseMemory)->HeapFree(CLASS);\


#define spanalloc(CLASS,...) new(SSINGLETON_INSTANCE(Sonicteam::SpanverseMemory)->HeapAlloc(sizeof(CLASS),0))CLASS(__VA_ARGS__)
#define spanalloc2(CLASS) new(SSINGLETON_INSTANCE(Sonicteam::SpanverseMemory)->HeapAlloc(sizeof(CLASS),0))CLASS(__VA_ARGS__)






#endif