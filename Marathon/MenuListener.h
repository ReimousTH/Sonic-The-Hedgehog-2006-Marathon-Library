#pragma once
#include <DocMarathonImp.h>
#include <Sox/Engine/Task.h>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>


namespace Sonicteam{


	 
	//Or SonicTeamSoxComponent
	class MenuListener:Sonicteam::SoX::Object,Sonicteam::SoX::IOObject
		{
		public:

			MenuListener(unsigned int,Sonicteam::DocMarathonImp*);

			virtual char* GetObjectType();
			~MenuListener(void);

			virtual void MLOnUpdate(unsigned int,float); //UnkInputStructure(GetPlayerInputCopy),delta i guess
			virtual void MLOnAction(unsigned int,unsigned int,float); // 2nk and delta


			unsigned int MLuint0x10;
			unsigned int MLuint0x14;
			Sonicteam::SoX::MessageReceiver* MLCurrentMessageReciever; //AlertWindowTask, MainMenuTask and other 0x18
			Sonicteam::DocMarathonImp* MLDocMarathon; //0x1C
			unsigned int MLuint0x20; //==9 
			unsigned int MLuint0x24; //==2
			unsigned int MLOutputInput; //==0
			unsigned float MLStickHoldFixTime; // 0.34999999; ,0.35 - delta -> untill 0 then it allow to change select in menu
			unsigned float MLuint0x30; // 0.050000001;



	};
};