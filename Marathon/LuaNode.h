#pragma once

#include <string>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

namespace Sonicteam{

		typedef class LuaNodeImp;
 
		class LuaNode // : LuaNode + (again hided in destructors omg)
		{
		public:
		//	LuaNodeImp(lua_State*,char*);	
			virtual ~LuaNode(void);
		//	
			//vft (all Extern "C" )
			virtual boost::shared_ptr<LuaNodeImp> LuaNodeGetFixedCopy() = 0;
			//or weak_ptr ????//
			virtual boost::shared_ptr<LuaNodeImp> LuaNodeUnknown0x01(char*) = 0; //table_name
			virtual boost::shared_ptr<LuaNodeImp> LuaNodeUnknown0x02(char*)  = 0; //table_name
			virtual boost::shared_ptr<LuaNodeImp> LuaNodeUnknown0x03() = 0; 
			virtual boost::shared_ptr<LuaNodeImp> LuaNodeResetNode(lua_State* L)  = 0; // ResetNode
			virtual bool LuaNodeUnknown0x05(int) = 0;  //IsCanbeConvertedToImpulse
			virtual bool LuaNodeUnknown0x06(int) = 0;  //IsCanbeConvertedToImpulse
			virtual void	ClearTablePath() = 0;//8204E4DC
			virtual bool	LuaNodeUnknown0x07(char*,int,char*) = 0 ;//8204E4E0
			virtual int		LuaNodeUnknown0x08(char*,int,char*) = 0;//8204E4E4 ( lua_pushnumber sends back to .lua)
			virtual int		LuaNodeUnknown0x09(const char*,int) = 0;//8204E4E8
			virtual int		IsTableExist(char*) = 0;//8204E4EC
			virtual int		GetTableInt(char*) = 0;//8204E4F0  (return lua_tonumber)
			virtual int		LuaNodeUnknown0x0C(char*,int) = 0;//8204E4F4
			virtual float	GetTableFloat(char*) = 0;//8204E4F8, get float value from lua file
			virtual int		LuaNodeUnknown0x0E(char*,float) = 0;//8204E4FC
			virtual char*	LuaNodeUnknown0x0F(char*) = 0;//8204E500
			virtual int		LuaNodeUnknown0x10(char*,char*) = 0;//8204E504
			virtual int		LuaNodeUnknown0x11(char*) = 0;//8204E508
			virtual int		LuaNodeUnknown0x12(char*) = 0;//8204E50C (returns boolean and then converted to int from lua)
			virtual int		LuaNodeUnknown0x13(char*,int) = 0;//8204E510 (int- need more lua functions to discover)
			virtual int		LuaNodeUnknown0x14(char*) = 0;//8204E514 
			virtual int		LuaNodeUnknown0x15(char*,int) = 0;//8204E518 
			
			//<LuaTableAccessImp>
			virtual boost::shared_ptr<int> LuaNodeUnknown0x16(char*) = 0;//8204E51C 

			//fields

			lua_State* Lua_State;
			std::string TablePath;  //Registry/DemoCamera =  Registry.DemoCamera in short

			
		};

}
