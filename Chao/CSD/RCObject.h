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


#define RCOBJREF(Type) Chao::CSD::RCObjectContainerEX<Type,Chao::CSD::RCObject<Type>* __ptr32>

#define RCOBJREF32(Type) Chao::CSD::RCObjectContainerEX<Type,Chao::CSD::RCObject<Type>* __ptr32>
#define RCOBJREF64(Type) Chao::CSD::RCObjectContainerEX<Type,Chao::CSD::RCObject<Type>* __ptr64>

namespace Chao{
	namespace CSD{



		//RC-should be PTR
		template <typename CType,typename RC>
		class RCObjectContainerEX{
			typedef RCObjectContainerEX<CType,RC> selfT;
			RC value;

		public:
			RCObjectContainerEX(RC* other){
				value = other;
				other->RCRef();
			}
			RC get(){
				return value;
			}


			RCObjectContainerEX(){
				value = 0;
			};
			~RCObjectContainerEX(){
				if (value) value->RCFree();
			};
		};







		
		template <typename CType>
		class RCObject:Chao::CSD::CBase
		{
		public:

			CMADestuctionHPP(RCObject);


			RCObject() : CObject(NULL) {};


			RCObject(CType* other) : CObject(other) {};
			~RCObject() {};





			size_t GetRefCount(){return RefCount;};

			void RCRef() { ++RefCount; };




			void RCFree(){

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
					DestroyObject(1); //will be here 

				}
			}



			// copy lock
			RCObject(const RCObject&);
			RCObject& operator=(const RCObject&);
	



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
