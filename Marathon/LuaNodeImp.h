#ifndef SONICTEAM__LUANODEIMP
#define SONICTEAM__LUANODEIMP
#include "Defs.h"

#include <string>
#include "LuaNode.h"


#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

namespace Sonicteam{
 
	//Do implementation later :)
	class LuaNodeImp:public LuaNode // : LuaNode + (again hided in destructors omg)
	{
	public:
		LuaNodeImp(lua_State*,char*);	
		~LuaNodeImp(void);

		virtual void DestroyObject(unsigned int Flag) override;




		//fields



	//	lua_State* Lua_State;
	//	std::string TablePath;  //Registry/DemoCamera =  Registry.DemoCamera in short


	};

}
#endif