#ifndef SONICTEAM__LUASYSTEM
#define SONICTEAM__LUASYSTEM
#include "Defs.h"

#include <string>
#include <Sox/IResource2.h>
#include <LuaSystemManager.h>
#include <LuaNodeImp.h>
#include <Sox/Object.h>


#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

namespace Sonicteam{

	
 
		//TODO (STATIC CLASS)
	class LuaSystem:public LuaNodeImp,public IResource2HR(Sonicteam::LuaSystem,Sonicteam::LuaSystemManager) // : LuaNode + (again hided in destructors omg)
		{
		public:
			LuaSystem();
			~LuaSystem();


			float GetFloatValue(std::string*);
			float GetFloatValue(std::string&);

			void LuaProceedArgFunction(void* arg,std::string& fncn);


			static LuaSystem* LoadInitResource(LuaSystem*&,std::string& path);
		
			
		};

}
#endif