#pragma once
#include <Sox/MessageReceiver.h>
#include <Sox/RefCountObject.h>

#include <Sox/Misc/List.h>
#include <xtl.h>

namespace Sonicteam{
	namespace SoX{
		namespace Physics{






			class Entity:Sonicteam::SoX::MessageReceiver,Sonicteam::SoX::RefCountObject
			{
			public:
				//size0x60
				Entity(unsigned int Flag1,unsigned int Flag2);
				~Entity	(void);


				unsigned int Flag1; //0xC


				

				Sonicteam::SoX::LinkedNodeListB<Sonicteam::SoX::RNodeF<Entity>> ULLC0x10;


				unsigned int UEuint0x18;
				unsigned int UEuint0x1C;

				unsigned int Flag2;	//0x20 ACTOR , PropFixture
				unsigned int UEuint0x24;


				virtual int OnMessageRecieved(Sonicteam::SoX::Message*) override;
				virtual void DestroyObject(unsigned int flag) override;


		


			};
		};
	}
}
