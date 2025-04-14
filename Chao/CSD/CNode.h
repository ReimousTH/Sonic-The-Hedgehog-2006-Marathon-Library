#ifndef CHAOS__CSD__CNODE
#define CHAOS__CSD__CNODE


#include <Chao/CSD/Defs.h>
#include <Chao/CSD/Node.h>
#include <Chao/CSD/CNodeObserver.h>
#include <Chao/CSD/CBase.h>
#include <Chao/CSD/CResourceBase.h>
#include <Chao/CSD/SubjectBase.h>
#include <Chao/CSD/CFontCollection.h>
#include <map>



namespace Chao{



	namespace CSD{


	
		//CSceneObserver->CNodeObserver
		class CNode:public Chao::CSD::CResourceBase<Chao::CSD::Node>,public Chao::CSD::SubjectBase<Chao::CSD::CNodeObserver,Chao::CSD::CNode>,public Chao::CSD::CBase
		{
		public:
			CNode(void);
			~CNode(void);

		public:
			CMADestuctionHPP(CNode);

			std::list<RCOBJREF(unsigned char)> unk0x20; // 0x20-0x24-0x28
			void* unk0x2C; //sub_825D0388 constructor (figure type later) (type used to controll node, pattern ...
			Chao::CSD::CFontCollection* FontCollection; //sub_825CA1D8 constructor (figure type later) (should be released but with flag 0) (req container type :| mb) (FontCollection) 0x30
			const char* CNodeName; //custom_gem ? //0x34
			Chao::CSD::CScene* PTScene; //Parent
			void* unk0x3C; //unk_type, but released same as 0x30
			RCOBJREF(char) Text; //0x40
			std::map<size_t,RCOBJREF(unsigned char)> unk0x44; //0x44-0x48-0x4C
			void* unk0x50; //sub_825D0388(not constructor but close :))  (released at easy, directly from deallocator ) (yep seems 0x2C,0x30.. have container type :C sucks)


		};
	};
};
#endif
