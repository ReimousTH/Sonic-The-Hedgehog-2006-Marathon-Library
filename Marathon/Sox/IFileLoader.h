#ifndef SONICTEAM__SOX__IFILELOADER
#define SONICTEAM__SOX__IFILELOADER

#include <Sox/Defs.h>
#include <Sox/IResource.h>
#include <Sox/RefCountObject.h>
#include <boost/function.hpp>	



namespace Sonicteam{
	namespace SoX{
		

		
		//this is the best that i can think
		class IFileLoader:Sonicteam::SoX::RefCountObject
		{

		public:	
			IFileLoader();
			~IFileLoader();
			DESTRUCTION_H;
			virtual REF_TYPE(Sonicteam::SoX::IFileHandle) LoadFile(std::string& filepath,IFileLoader_BFUNCTION_TYPE& function) = 0;
		
	
		};

	};
};
#endif