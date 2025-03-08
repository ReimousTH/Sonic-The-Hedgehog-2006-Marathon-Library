#ifndef SONICTEAM__SPANVERSE__SPANSPMS
#define SONICTEAM__SPANVERSE__SPANSPMS

#include <Sox/Memory/Destruction.h>
#include <Spanverse/ISpan.h>


#define SONICTEAM__SPANVERSE_HEADER__SPANSBMB 0x53424D42

struct SBMBLinkNode;

struct SBMBLinkNode{
	SBMBLinkNode* Prev; //i think
	SBMBLinkNode* Next; // sure 
};





namespace Sonicteam{
	namespace Spanverse{
		class SpanSBMB:Sonicteam::Spanverse::ISpan{
			public:
			SpanSBMB();
			~SpanSBMB();

			SBMBLinkNode* link_data;
			unsigned int unk0x14;
	



			DESTRUCTION_H;
			
		};
	};
};



#endif