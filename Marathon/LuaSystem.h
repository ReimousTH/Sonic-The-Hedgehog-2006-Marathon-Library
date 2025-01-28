#pragma once

#include <string>
#include "SoX/IResource2.h"
#include "LuaSystemManager.h"
#include "LuaNodeImp.h"

#include <Sox/Object.h>


#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

namespace Sonicteam{

	
 
		//TODO (STATIC CLASS)
	   class LuaSystem:public LuaNodeImp,public Sonicteam::SoX::IResource2<LuaSystem,LuaSystemManager> // : LuaNode + (again hided in destructors omg)
		{
		public:
			LuaSystem(void);
			~LuaSystem(void);


			float GetFloatValue(std::string*);
			float GetFloatValue(std::string&);

			void LuaProceedArgFunction(void* arg,std::string& fncn);


			static LuaSystem* LoadInitResource(LuaSystem*&,std::string& path);
		
			
		};

}
