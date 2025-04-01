#ifndef CHAO__CSD_RCOBJECT
#define CHAO__CSD_RCOBJECT


#include <Chao/Misc/API_DEFS.h>
#include <Chao/CSD/Defs.h>
#include <Chao/CSD/CBase.h>
#include <Chao/CSD/CMemoryAlloc.h>
#include <Chao/CSD/CPlatform.h>

#define CCRCObjectDeallocUSE_CSD 0
#define CCRCObjectDeallocUSE_STD 1
#define CCRCObjectDeallocUSE_FUNC 3

namespace Chao{
	namespace CSD{



		//Replicate same as RefCountObjectContainer :)
		template <typename CType>
		class RCObject:Chao::CSD::CBase
		{
			public:

			CMADestuctionHPP(RCObject);


			RCObject() : CObject(NULL) {};


			RCObject(CType* other) : CObject(other) {};
			~RCObject() {
				RefCount--;
				if (!RefCount){

					//Probably static Method<T> +- 
					if (CObject){
						switch (DeallocatorFlag){
							case 0:
								CMFree(CObject);
								break;
							case 1:
								::operator delete(CObject);
								break;
							case 2:
								break;
							case 3:
								Deallocator(CObject);	
								break;
							default:
								//More here supposed to be
								CPDebugMessageA("Not inititalized m_eDealloctor");
								break;
							break;
						
						}
					}
					Deallocator = 0;
				}
			};



			// copy lock
			RCObject(const RCObject&);
			RCObject& operator=(const RCObject&);
			RCObject(RCObject** other) {
				*other = this;
				this->RefCount++;
			};




			CType* operator->() const {
				return CObject; 
			};
			CType* get() const {
				return CObject;
			};

			CType& operator*() const {
				return *CObject;
			};




		protected:
			CType* CObject; // + 4   
			size_t RefCount; // + ( 8
			void(*Deallocator)(void* ptr); //c
			size_t DeallocatorFlag; // 0x10



		};



	};
};

#endif
