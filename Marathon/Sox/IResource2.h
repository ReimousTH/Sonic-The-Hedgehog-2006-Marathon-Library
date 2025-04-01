#ifndef SONICTEAM__SOX__IRESOURCE2
#define SONICTEAM__SOX__IRESOURCE2


#include "IResource.h"
#include <System/Singleton.h>
#include <System/CreateStatic.h>



#define IResource2HR(HANDLE,MGR) Sonicteam::SoX::IResource2<HANDLE,MGR>

namespace Sonicteam{
	namespace SoX{
		template<typename Resouce,typename Manager>
		class IResource2:public IResource
		{
		public:	
	
			IResource2();
			~IResource2();

			Manager* GetManager();

		};

		template<typename Resouce,typename Manager>
		Sonicteam::SoX::IResource2<Resouce, Manager>::~IResource2()
		{

		}

		template<typename Resouce,typename Manager>
		Sonicteam::SoX::IResource2<Resouce, Manager>::IResource2()
		{

		}

		template<typename Resouce,typename Manager>
		Manager* Sonicteam::SoX::IResource2<Resouce, Manager>::GetManager()
		{
			return SSINGLETON_INSTANCE(Manager);

		}
		

	}
}
#endif
