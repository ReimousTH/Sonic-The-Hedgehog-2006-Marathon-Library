
#ifndef CHAOS__CSD__CRESOURCEBASE
#define CHAOS__CSD__CRESOURCEBASE


#include <Chao/CSD/Defs.h>
#include <Chao/CSD/RCObject.h>
#include <Sox/Memory/Destruction.h>




namespace Chao{
	namespace CSD{



		//No INFO so empty
		template <typename T>
		class CResourceBase	
		{
		public:
			CResourceBase(void);
			~CResourceBase(void);

			DESTRUCTION_HPP;
			virtual void CResourceBase0x4(void*) = 0;

			//https://github.com/blueskythlikesclouds/BlueBlur/blob/master/CSD/Manager/csdmResourceBase.h
		//protected:
			//i guess IT <T> at least should be
			Chao::CSD::RCObject<unsigned char>* RCObject; //  Chao::CSD::RCObject<unsigned char>
			unsigned int FCRB0x8; //Scene Data

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
