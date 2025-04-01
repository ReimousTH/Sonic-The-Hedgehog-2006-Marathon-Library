
#ifndef CHAOS__CSD__CRESOURCEBASE
#define CHAOS__CSD__CRESOURCEBASE


#include <Chao/CSD/Defs.h>
#include <Chao/CSD/RCObject.h>




namespace Chao{
	namespace CSD{



		//No INFO so empty
		template <typename T>
		class CResourceBase	
		{
		public:
			CResourceBase(void);
			~CResourceBase(void);

			CMADestuctionHPP(CResourceBase);
			virtual void SetRCObject(Chao::CSD::RCObject<T>* other,T* RawData) = 0; 

			Chao::CSD::RCObject<unsigned char>* RCObject; // 
			T* CObjectRaw; // 
			//yes Raw Data seems have template instead of RCObject weird 

		};

		template <typename T>
		Chao::CSD::CResourceBase<T>::~CResourceBase(void)
		{

		}

		template <typename T>
		Chao::CSD::CResourceBase<T>::CResourceBase(void)
		{

		}

	
	};
};
#endif
