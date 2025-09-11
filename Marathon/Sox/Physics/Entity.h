#ifndef SONICTEAM__SOX__PHYSICS__ENTITY
#define SONICTEAM__SOX__PHYSICS__ENTITY

#include "Defs.h"

#include <Sox/Physics/EntityContainer.h>
#include <Sox/Misc/LinkSoxNode.h>
#include <Sox/MessageReceiver.h>
#include <Sox/RefCountObject.h>

#include <Actor.h>
#include <xtl.h>
#include <Sox/Physics/Shape.h>
#include <Sox/Physics/EntityContainer.h>


namespace Sonicteam{
	namespace SoX{
		namespace Physics{



			class Entity:Sonicteam::SoX::MessageReceiver,public Sonicteam::SoX::RefCountObject
			{
			public:
				//size0x60
				Entity(unsigned int EntityFlag,Sonicteam::SoX::MessageReceiver* EntityReceiver);
				~Entity	(void);


				unsigned int EntityFlag; //0xC
				LinkSoxNode<EntityContainer> LinkEntity; //0x10,0x14,0x18


				REF_TYPE(Sonicteam::SoX::RefCountObject) EntityRefObject; //0x1C
				Sonicteam::SoX::MessageReceiver* EntityReceiver; //0x20
				REF_TYPE(Sonicteam::SoX::Physics::Shape) EntityShape; //0x24


				virtual int OnMessageRecieved(SoXMessageType) override;

				//IMPLEMENT A LOT VIRTUAK METHODS :)


				DESTRUCTION_H override;


		


			};
		};
	}
}
#endif