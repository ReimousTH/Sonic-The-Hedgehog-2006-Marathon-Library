#ifndef SONICTEAM__LUASYSTEMMANAGER
#define SONICTEAM__LUASYSTEMMANAGER
#include <Defs.h>
#include <Sox/IResourceMgr.h>
#include <System/Singleton.h>
#include <System/CreateStatic.h>


namespace Sonicteam{

	
 
		//TODO (STATIC CLASS)
		class LuaSystemManager:Sonicteam::SoX::IResourceMgr,SSINGLETON(LuaSystemManager) // : IResourceMGR + 
		{
		public:
			LuaSystemManager(void);
			~LuaSystemManager(void);

		};

}
#endif