#pragma once				
#include <SoX/Memory/IDestructible.h>

#define REF_TYPE(Type) Sonicteam::SoX::RefCountObjContainer<Type>

namespace Sonicteam{
	namespace SoX{


		

		typedef class RefCountObject;

		template <typename T>
		struct RefCountObjContainer {
			T* param;

			// Default constructor
			RefCountObjContainer() : param(NULL) {}

			// Constructor taking a raw pointer
			RefCountObjContainer(T* other) : param(other) {
				if (param) {
					param->AddReference(); // Increment reference count
				}
			}

			// Destructor
			~RefCountObjContainer() {
				if (param) {
					param->Release(); // Decrement reference count
				}
			}

			// Conversion operator to allow implicit conversion to T*
			operator T*() const { 
				return param; 
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
			// Overloading operator->
			T* operator->() const {
				return param; 
			}

		};

		class RefCountObject {
		public:
			RefCountObject() : referenceCount(0) {}

			~RefCountObject() {}

			void AddReference();
			void Release();
			virtual void DestroyObject(unsigned int flag);

		

			//not sure, my custom for easier 
			template <typename T>
			T* GetObject();


		private:
			RefCountObject(const RefCountObject&);


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
