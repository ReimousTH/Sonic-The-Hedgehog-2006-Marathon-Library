#ifndef CHAOS__CSD__CTRANSFORM1
#define CHAOS__CSD__CTRANSFORM1


#include <Chao/CSD/Defs.h>
#include <Chao/CSD/CResourceBase.h>



namespace Chao{


	namespace CSD{


	

		//Chao::CSD::Font (target in .ida to CFontCollection because opmtization removed poor class)
		class CTransform_1:public Chao::CSD::CResourceBase<Chao::CSD::Node>,public Chao::CSD::CBase
		{
		public:
			CTransform_1(void);
			~CTransform_1(void);
		public:
			CMADestuctionHPP(CTransform_1);

		};
	};
};
#endif
