#ifndef SONICTEAM__SPANVERSEHEAP
#define SONICTEAM__SPANVERSEHEAP

#include <Sox/Memory/Destruction.h>
#include <Heap.h>

namespace Sonicteam{
	class SpanverseHeap:public Sonicteam::Heap{
			public:
			SpanverseHeap();
			~SpanverseHeap();



			void Initialize(void*);


			static SpanverseHeap* SpanInstance;
			static bool Initialized;
			DESTRUCTION_H;
			
	};
		
		//nothing new
	
};


#endif