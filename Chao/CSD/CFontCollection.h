#ifndef CHAOS__CSD__CFONTCOLLECTION
#define CHAOS__CSD__CFONTCOLLECTION


#include <Chao/CSD/Defs.h>
#include <Chao/CSD/CResourceBase.h>





namespace Chao{


	namespace CSD{


	

		//Chao::CSD::Font 
		class CFontCollection:public Chao::CSD::CResourceBase<Chao::CSD::Node>,public Chao::CSD::CBase
		{
		public:
			CFontCollection(void);
			~CFontCollection(void);
		public:
			CMADestuctionHPP(CFontCollection);

		};
	};
};
#endif
