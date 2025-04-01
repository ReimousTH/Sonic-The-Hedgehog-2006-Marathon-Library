#ifndef CHAO__CSD__MANAGER__CSDMPROJECT
#define CHAO__CSD__MANAGER__CSDMPROJECT


#include <Chao/CSD/Manager/Defs.h>
#include <Chao/CSD/RCObject.h>
#include <Chao/CSD/CMemoryAlloc.h>
#include <Chao/CSD/Manager/csdmNodeBase.h>


namespace Chao{
	namespace CSD{
		namespace Manager{


	

			class csdmProject:Chao::CSD::Manager::csdmNodeBase
			{
			public:
				csdmProject();
				~csdmProject();
				CMADestuctionHPP(csdmProject); 
				virtual void SetRCObject(Chao::CSD::RCObject<unsigned char>* other,void* RawData);

			};

		};
	};
};

#endif
