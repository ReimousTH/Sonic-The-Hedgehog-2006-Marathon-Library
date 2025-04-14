#ifndef CHAOS__CSD__CNODEOBSERVER
#define CHAOS__CSD__CNODEOBSERVER


#include <Chao/CSD/Defs.h>
#include <Chao/CSD/CObserverBase.h>



namespace Chao{
	namespace CSD{

	

		// not in IDA (hypethetical class, sad)
		class CNodeObserver:Chao::CSD::CObserverBase<Chao::CSD::CNode>
		{
		public:
			CNodeObserver();
			~CNodeObserver();
			CMADestuctionHPP(CNodeObserver);

		};
	};
};
#endif
