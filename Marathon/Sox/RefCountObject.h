#ifndef SONICTEAM__SOX__REFCOUNTOBJECT
#define SONICTEAM__SOX__REFCOUNTOBJECT



#include "Defs.h"
#include <SoX/Memory/IDestructible.h>
#include <Sox/Memory/Destruction.h>

#define REF_TYPE(Type) Sonicteam::SoX::RefCountObjContainer<Type>
#define REF_TYPE_REF(Type) REF_TYPE(Type)& //use in fuction args, but not for RET_TYPE


//#define REF_TYPE(Type) Type* // Use To Compile FOR IDB IMport
#define REFCOUNTOBJCONTAINERUSEROPERATOR

namespace Sonicteam{
	namespace SoX{


		



		#pragma optimize("", off)
		template <typename T>
		struct RefCountObjContainer {
			T* param;


			RefCountObjContainer() : param(NULL) {}


			RefCountObjContainer(T* other) : param(other) {
				if (param) {
					param->AddReference(); // Increment reference count
				}
			}

		
			~RefCountObjContainer() {
				if (param) {
					param->Release(); // Decrement reference count
				}
			}


		

	
		
			// Copy constructor
			RefCountObjContainer(const RefCountObjContainer& other) : param(other.param) {
				if (param) {
					param->AddReference(); // Increment reference count for the new copy
				}
			}

			// Assignment operator
			RefCountObjContainer& operator=(const RefCountObjContainer& other) {
				if (this != &other) { // Prevent self-assignment
					if (param) {
						param->Release(); // Release current object
					}
					param = other.param;
					if (param) {
						param->AddReference(); // Increment reference count for the new object
					}
				}
				return *this;
			}
			bool operator==(const RefCountObjContainer& other){
				return other.param == this->param;
			}

			#ifdef REFCOUNTOBJCONTAINERUSEROPERATOR
			// Overloading operator->
			/*
			T* operator->() const {
				return param; 
			}
			*/
			T* get() const {
				return param;
			}
			/*
			T& operator*() const {
				return *param;
			}
			*/ //does not work properly

			#endif
		};
		#pragma optimize("", on)

		class RefCountObject {
		public:
			RefCountObject() : referenceCount(0) {}
			~RefCountObject() {}

			void AddReference();
			void Release();
			DESTRUCTION_H;

		
	
			// Assignment operator, do not copy reference count
			RefCountObject& operator=(const RefCountObject& other){
				referenceCount = 0;
				 return *this; 
			}
			RefCountObject(const RefCountObject& other){
				 referenceCount = 0; // No copying of reference count
			}



			unsigned int GetReferenceCount(){
				return referenceCount;
			}

			//not sure, my custom for easier 
			template <typename T>
			T* GetObject();



		
			


		protected:
			unsigned int referenceCount;
		};

		template <typename T>
		T* Sonicteam::SoX::RefCountObject::GetObject()
		{
			this->AddReference();
			return (T*)this;
		}

	

	}
}


#endif

