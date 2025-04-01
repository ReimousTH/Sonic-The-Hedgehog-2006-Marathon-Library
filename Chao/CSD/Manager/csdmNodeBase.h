#ifndef CHAO__CSD__MANAGER__CSDMNODE
#define CHAO__CSD__MANAGER__CSDMNODE


#include <Chao/CSD/Manager/Defs.h>
#include <Chao/CSD/RCObject.h>
#include <Chao/CSD/CMemoryAlloc.h>



namespace Chao{
	namespace CSD{
		namespace Manager{


	

			class csdmNodeBase
			{
			public:
				csdmNodeBase();
				~csdmNodeBase();

				CDESTRUCTION_HPP(csdmNodeBase); // operator delete here
				virtual void SetRCObject(Chao::CSD::RCObject<unsigned char>* other,void* RawData) = 0; 
				Chao::CSD::RCObject<unsigned char>* RCObject;
				void* RCObjectRaw; 
				unsigned int unk0xC;


			};

		};
	};
};

#endif
