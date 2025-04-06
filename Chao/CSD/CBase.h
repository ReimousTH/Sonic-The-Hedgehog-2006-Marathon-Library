#ifndef CHAO__CSD__CBASE
#define CHAO__CSD__CBASE


#include <Chao/Misc/API_DEFS.h>
#include <Chao/CSD/Defs.h>
#include <Chao/CSD/CMemoryAlloc.h>




namespace Chao{
	namespace CSD{


		//Empty-Class
		class CBase
		{
		public:
			CBase(void);
			~CBase(void);


			CMAAllocationNEWHPP;
			CMAAllocationDELETEHPP;



		};
	};
};
#endif