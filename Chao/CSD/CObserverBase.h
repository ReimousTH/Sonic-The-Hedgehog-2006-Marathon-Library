
#ifndef CHAOS__CSD__COBSERVERBASE
#define CHAOS__CSD__COBSERVERBASE


#include <Chao/CSD/Defs.h>
#include <Chao/CSD/CMemoryAlloc.h>
#include <list>




namespace Chao{
	namespace CSD{



		//No INFO so empty
		template <typename T>
		class CObserverBase	
		{
		public:
			CObserverBase(void);
			~CObserverBase(void);	
			CDESTRUCTION_H = 0;

			//NO IDEA ABOUT STRUCTURE MAYBE CUSTOM OR VERY WEIRD AT LEAST O_O , std::list maybe close no idea
			std::list<T*> CObservableObjects; //4,8,C
		
		};

		template <typename T>
		Chao::CSD::CObserverBase<T>::~CObserverBase(void)
		{

		}

		template <typename T>
		Chao::CSD::CObserverBase<T>::CObserverBase(void)
		{

		}



	
	};
};
#endif
