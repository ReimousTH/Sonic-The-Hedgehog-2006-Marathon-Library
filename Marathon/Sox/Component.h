#pragma once

#include "Object.h"
#include "Sox/Misc/List.h"

namespace Sonicteam{
	namespace SoX{
	
	


		
	
		typedef class Component;

		struct IOComponent{
		public:
		
		
			
			
		};


		class Component:public Object
		{
		public:
			Component(Component*);
			~Component(void);

			Component* LastComponent; //0x4
			Sonicteam::SoX::LinkNode<Component> LinkedComponent; //0x8,0xC,0x10
			Sonicteam::SoX::LinkNodeList<Component> LComponentList; //0x14,0x18,0x1C

		
			//0x20...


			virtual char* GetObjectType() override; 
			virtual void DestroyObject(unsigned int flag) override;

		
			


			
		};
	}
}
