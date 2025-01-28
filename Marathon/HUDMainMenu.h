#pragma once
#include <Sox/Engine/Task.h>
#include <MenuListener.h>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <sox/RefCountObject.h>



//FirstParam
#define HudMainMenuMsgOthers 0x1B053;


//


namespace Sonicteam{


	//TODO Construuctor and complete many things :((((((
	struct MMT_MST_Resources{
		unsigned int EngineDoc;
		unsigned int msg_mainmenu; //mst
		unsigned int msg_system; //mst
		unsigned int msg_town_mission_sonic;
		unsigned int msg_town_mission_shadow;
		unsigned int msg_town_mission_silver;
		unsigned int msg_gold_results;

	};


	//temp only



	//not full
	class HudMainMenu:Sonicteam::SoX::RefCountObject,Sonicteam::SoX::Engine::Task
		{
		public:

			HudMainMenu(SoX::Engine::Doc*);
			 ~HudMainMenu();
			//virtual void DestroyObject(unsigned int flag);

			virtual void OnTaskUpdate(float);
			virtual int OnMessageRecieved(Sonicteam::SoX::Message*); //824E9850
			MMT_MST_Resources MMText; //0x54
			unsigned int HMMCSDSpriteMainMenu; // float 20 //0x70
			unsigned int HMMCSDSpriteMainMenu2; // DifferentInitParam .float 30 why //0x74
			unsigned int HMMCSDSpriteMainMenu3; // DifferentInitParam .float 10 why //0x78 //Hud option
			unsigned int HMMmsg_mainmenu_mst;  //7c
			unsigned int HMMmsg_system_mst; //0x80
			unsigned int HMMuint0x84;
			//0x98 0x82035A54 ,ButtonWindowTask
			//0x9C 0x:82039B9C ,MainMenuExpositionTask
			unsigned int HMMubytegap[218]; //0x88
			unsigned int HMMuint0x2A0;
			unsigned int HMMuint0x2A4;
			boost::shared_ptr<unsigned int> HMMmsg_singleplayerText; //2A8
			boost::shared_ptr<unsigned int> HMMmsg_multiplayerText; //2B0
			boost::shared_ptr<unsigned int> HMMmsg_xboxliveText; //2B8
			boost::shared_ptr<unsigned int> HMMmsg_extrasText; //2C0
			boost::shared_ptr<unsigned int> HMMmsg_optionsText; //2C8
			boost::shared_ptr<unsigned int> HMMmsg_epiodeselectText; //2D0
			boost::shared_ptr<unsigned int> HMMmsg_trialselectText; //2D8
			boost::shared_ptr<unsigned int> HMMmsg_goldmedalresultsText; //2E0
			boost::shared_ptr<unsigned int> HMMmsg_actselectText; //2E8
			boost::shared_ptr<unsigned int> HMMmsg_towntrialText; //2F0
			boost::shared_ptr<unsigned int> HMMmsg_tagText; //2F8
			boost::shared_ptr<unsigned int> HMMmsg_battleText; //300
			boost::shared_ptr<unsigned int> HMMmsg_tagstoryText; //308
			boost::shared_ptr<unsigned int> HMMmsg_tagtrialText; //310
			boost::shared_ptr<unsigned int> HMMmsg_msgrankingText; //318
			boost::shared_ptr<unsigned int> HMMmsg_downloadText; //320
			boost::shared_ptr<unsigned int> HMMmsg_audioroomText; //328
			boost::shared_ptr<unsigned int> HMMmsg_theaterroomText; //330
			boost::shared_ptr<unsigned int> HMMmsg_mainmenuText; //338
			boost::shared_ptr<unsigned int> HMMmsg_episodeselectText; //340
			boost::shared_ptr<unsigned int> HMMmsg_actselectText2; //348
			boost::shared_ptr<unsigned int> HMMmsg_towntrialText2; //350
			boost::shared_ptr<unsigned int> HMMmsg_optionsText2; //358
			boost::shared_ptr<unsigned int> HMMmsg_goldmedalresultsText2; //360
			boost::shared_ptr<unsigned int> HMMmsg_audioroomText2; //368
			boost::shared_ptr<unsigned int> HMMmsg_theaterroomText2; //370
			boost::shared_ptr<unsigned int> HMMmsg_downloadText2; //378
			boost::shared_ptr<unsigned int> HMMmsg_msg_rankingText; //380
			boost::shared_ptr<unsigned int> HMMmsg_msg_tagText2; //388
			boost::shared_ptr<unsigned int> HMMmsg_msg_tagtrialText; //390
			boost::shared_ptr<unsigned int> HMMmsg_battleText2; //398
			unsigned int HMMuint0x3A0;
			unsigned int HMMuint0x3A4;
			unsigned int HMMuint0x3AC;
			unsigned int HMMuint0x3B0;







			
			


			

		


	};
};