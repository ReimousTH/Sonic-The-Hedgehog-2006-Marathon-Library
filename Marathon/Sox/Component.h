#pragma once

#include "Object.h"
#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/Memory/Destruction.h>


namespace Sonicteam{
	namespace SoX{
	
	




		class Component:public Object
		{
		public:
			Component(Component*);
			~Component(void);
			Component* LastComponent; //0x4


			LinkSoxNode<Component> LinkComponent; //0x8,0xC,0x10
			LinkSoxNode<Component> ListComponent; //0x14,0x18,0x1C

		
			//0x20...


			virtual char* GetObjectType() override; 
			DESTRUCTION_H;


		
			


			
		};
	}
}
