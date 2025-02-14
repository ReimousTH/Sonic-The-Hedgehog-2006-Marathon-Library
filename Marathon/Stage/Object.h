#pragma once

#include <Sox/IResource.h>
#include <Sox/RefCountObject.h>
#include <Sox/MessageReceiver.h>
#include <Sox/Memory/IDestructible.h>


namespace Sonicteam{

	namespace Stage{

		//not complete :(

		class Object:Sonicteam::SoX::RefCountObject,Sonicteam::SoX::MessageReceiver
		{
		public:
			~Object();
			Object();


		

			unsigned int unkFlags0xC; //first byte, usually, other mb padding
			Sonicteam::SoX::IResource* MyLandCollisionInfo; //class later
			Sonicteam::SoX::RefCountObject* MyLandCollision; // class later	
			unsigned int unk0x18; //pointer, to what?	

	


			DESTRUCTION_H;
			virtual char* GetObjectType(); 
			virtual int OnMessageRecieved(SoXMessageType);



		};
	};
};