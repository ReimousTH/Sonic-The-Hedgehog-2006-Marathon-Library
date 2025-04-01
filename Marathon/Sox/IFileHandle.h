#ifndef SONICTEAM__SOX__IFILEHANDLE
#define SONICTEAM__SOX__IFILEHANDLE

#include <Sox/Defs.h>
#include <Sox/IResource.h>
#include <Sox/RefCountObject.h>
#include <boost/function.hpp>	




namespace Sonicteam{
	namespace SoX{
		

		
		//this is the best that i can think
		class IFileHandle:Sonicteam::SoX::RefCountObject
		{

		public:	
			IFileHandle();
			~IFileHandle();
			DESTRUCTION_H;
			virtual bool LoadHandle() = 0;
			virtual unsigned __int64 GetHandleSize() = 0; //same goes
			virtual void* GetHandleBuffer() = 0; // not .arc but others .lua, .plt ...->
		
	
		};

	};
};
#endif