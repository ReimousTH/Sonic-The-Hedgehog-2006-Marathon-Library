#pragma once
#include "IResource.h"
#include <string>

namespace Sonicteam{
	namespace SoX{
		template<typename T,typename Y>
		class IResource2:public IResource
		{
		public:	
			//size0x60
			IResource2(void);
		//	virtual ~IResource2(void);

	
			///not sure but why not (need test btw :( ) 
			T* Resource;
			Y* ResouceManager;

		};


	


		template<typename T,typename Y>
		Sonicteam::SoX::IResource2<T, Y>::IResource2(void)
		{

		}
		

	}
}
