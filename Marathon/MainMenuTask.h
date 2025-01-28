#pragma once
#include <Sox/Engine/Task.h>
#include <MenuListener.h>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <HUDMainMenu.h>
#include <HUDOption.h>



namespace Sonicteam{




	namespace{

		//at first point there messagereciver but sub_824FCFD0(r4 accept Task as argument means original Task was lost)
		class Entry2PListener:Sonicteam::MenuListener,Sonicteam::SoX::MessageReceiver{
		public:
			unsigned int E2Puint0x38;
			unsigned int E2Puint0x3C;


		};

	}


	class MainMenuTask:Sonicteam::SoX::Engine::Task
		{
		public:

			MainMenuTask(void);

			virtual char* GetObjectType();
			~MainMenuTask(void);

			virtual void OnTaskUpdate(float);
			virtual int OnMessageRecieved(Sonicteam::SoX::Message*); //Input Messages

			unsigned int MMCurrentCase; // MMCurrentCase;
			unsigned int MMTuint0x50;
			unsigned int MMTuint0x54;

			MMT_MST_Resources MMText; //Mst Text

			Sonicteam::HudMainMenu* MMHudMainMenu; //HudMainMenu 82037BB8
			Sonicteam::HUDOption* MMHudOption ; //HudOption (HudMainMenu untill i make hudoption)
			unsigned int MMTuint0x7C;
			unsigned int MMTuint0x80;
			unsigned int CSD_tag_character;
			unsigned int MMTuint0x88;
			unsigned int MMTuint0x8C;
			unsigned int MMTuint0x90;
			unsigned int MMTuint0x94;
			unsigned int MMTuint0x98;
			unsigned int MMTuint0x9C;
			unsigned int MMTuint0xA0; //Current MainMenuSelectedIndex
			unsigned int MMTuint0xA4; //Curent SinglePlayerSelectedIndex
			unsigned int MMTuint0xA8; //Curent MultiPlayerSelectedIndex
			unsigned int MMTuint0xAC; // Left over ??????
			unsigned int MMTuint0xB0; //CurrentExtrasSelectedIndex
			unsigned int MMTuint0xB4; //CurrentEpisodeSelectedIndex
			unsigned int MMTuint0xB8; ////CurrentEpisodeSelectedIndex
			unsigned int MMTuint0xBC; //CurrentTrialSelectedIndex
			unsigned int MMTuint0xC0;
			unsigned int MMTuint0xC4; //CurrentSelectedActTrialTownTrialCharacterEpisodeIndex
			unsigned int MMTuint0xC8; //CurrentActTrailSelectedLevelIndex
			unsigned int MMTuint0xCC; //
			unsigned int MMTuint0xD0; //CurrentSelectedLeveldifficultyIndex;
			unsigned int MMP1SelectedIndex;
			unsigned int P2SelectedChr;
			unsigned int MMTuint0xDC;
			unsigned int MMTuint0xE0;
			unsigned int MMTuint0xE4;
			unsigned float EngineSoundVolume1;
			unsigned float EngineSoundVolume2;
			unsigned int MMTuint0xF0;
			unsigned int MMTuint0xF4;
			unsigned int MMTuint0xF8;
			unsigned int MMTuint0xFC;
			unsigned float MMTfloat0x100;
			unsigned float MMTfloat0x104;
			unsigned int MMTuint0x108;
			unsigned int MMTuint0x10C;
			unsigned int MMTuint0x110;
			unsigned int MMTuint0x114;
			unsigned int MMTuint0x118;
			unsigned int MMTuint0x11C; //unkptr
			unsigned int MMTuint0x120; 
			unsigned int MMTuint0x124;
			unsigned int MMTuint0x128; //unkptr
			boost::shared_ptr<unsigned int> MMAudioPlayerImp; //PTR 0x825860CC (0x12c)
			unsigned int MMTSoundFlags; // 0x134
			unsigned int MMMyAudioADXCue; //0x138

			unsigned int TBmsg_mainmenu; //8204AF48 0x140
			unsigned int TBmsg_system; //8204AF48 0x140
			unsigned int TBmsg_gold_results; //8204AF48 0x144
			unsigned int TBmsg_options; //8204AF48 (0x148)

			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_singleplayer_c; //0x14c
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_singleplayer_c_2; //0x154
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_extra_c; //0x15C
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_options_c; //0x164
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_episodeselect_c; //0x16c
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_trial_c; //0x174
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_msg_goldmedalresults_c; //0x17C
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_episodesonic_c; //0x184
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_episodeshadow_c; //0x18c
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_episodesilver_c; //0x194
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_lastepisode_c; //0x19c
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_acttrial_c; //0x1A4
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_twntrial_c; //0x1AC
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_trial_sonic; //0x1B4
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_trial_shadow; //0x1BC
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_trial_silver; //0x1C4
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_trial_last; //0x1CC
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_trial_dlcharacter; //0x1D4
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_trial_msg_stageselect_c; //0x1DC
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_selectmission_c; //0x1E4
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_sonic_c; //0x1EC
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_shadow_c; //0x1F4
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_silver_c; //0x1FC
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_last_c; //0x204
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_tag_c; //0x20C
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_battle_c; //0x214
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_characterselect_c; //0x21c
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_ranking_c; //0x224
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_download_c; //0x22c
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_audioroom_c; //0x234
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_theaterroom_c; //0x23c
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_audio_c; //0x244
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_subtitile_c; //0x24c
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_msg_vibe_c; //0x254
			boost::shared_ptr<Sonicteam::SoX::RefCountObject> MMTextCard_EmptyMenuCard; //0x25C
			unsigned int MMTuint0x264;
			unsigned int MMTuint0x268;
			unsigned int MMTuint0x26C;
			unsigned int MMTuint0x270;
			boost::shared_ptr<unsigned int> MMMenuListener; //0x274
			unsigned int MMP1Input; //0x27c
			unsigned int MMP2Case; //0x280
			boost::shared_ptr<unsigned int> MMEntry2PListener; //0x284
			unsigned int MMP2ControllerID;	//0x28c
			unsigned int MMP2Input;	//0x290
			unsigned int MMTuintflag0x294;	//0x294
			unsigned int MMActor; //821602F0 0x298 ,82160440 
			unsigned int MMObjectPlayer1; //0x29C 0x82003564
			unsigned int MMObjectPlayer2; //0x2A0 0x82003564
			unsigned int MMObjectPlayer3; //0x2A4 0x82003564
			unsigned int MMObjectPlayer4; //0x2A8 0x82003564

			unsigned int MMObjectPlayer5;
			unsigned int MMObjectPlayer6;
			unsigned int MMObjectPlayer7;
			unsigned int MMObjectPlayer8;
			unsigned int MMObjectPlayer9;

			unsigned int MMuint0x2C0; //unkptr
			unsigned int MMObjectPlayerBuffer; //Contains Each Character Loaded PTR ,0x2C4
			unsigned int MMObjectPlayerBufferEnd; //End if this buffer or pointer to other PTR ,0x2c8
			unsigned int MMuint0x2CC; //Since it points to same as 0x2C8 means this ptr and previouss END ho ,0x2cc
			Sonicteam::SoX::Engine::Task* MMuint0x2D0; //SonicTeamSox Engine Task 
			unsigned int MMuint0x2D4;
			unsigned int MMuint0x2D8;
			unsigned int MMuint0x2DC;

			unsigned int MMuint0x2E0; //unkptr
			unsigned int MMMainMode; //MainMode ,824A6304
			unsigned int MMuint0x2E8; //unkptr
			unsigned int MMuint0x2EC; //unkptr (same as prev)
			unsigned int MMuint0x2F0; //MainMode** (same as prev almost, idek what is that)
			unsigned int MMuint0x2F4; //unkint


			public:
				Sonicteam::DocMarathonImp* GetCurrentDoc();
	
			


			

		


	};
};