#pragma once

#ifndef __Sonicteam__SOX__OBJECT__
#define  __Sonicteam__SOX__OBJECT__




#include <string>
#include <list>
 
#include <deque>
#include "Sox/Misc/List.h"
#include <SoX/Memory/IDestructible.h>


namespace Sonicteam{
	namespace SoX{
		typedef class Object;
		typedef class IObject;
		



		//[Removed]//
		//Inteface Object Object
		struct IOObject{	
			Sonicteam::SoX::RNodeF<Sonicteam::SoX::Object> RNodeF; //0x4,0x8,0xC
			unsigned int IOFlag;  //0x10
			//0x14...
		};


		

		
		/************************************************************************/
		/*         Inherit with IOObject or custom struct  */
		/************************************************************************/
		//class Component:public Object,public IOComponent//
		class Object
		{
		public:
			//size0x60
			Object(void);
			~Object(void);
			virtual char* GetObjectType(); 
			virtual void DestroyObject(unsigned int flag);
			

	
		};

		class ObjectRework{

		public:
			//size0x60
			ObjectRework(void);
			virtual char* GetObjectType(); 
			virtual ~ObjectRework(void);
	

		
		
	

		};
	}
}
#endif