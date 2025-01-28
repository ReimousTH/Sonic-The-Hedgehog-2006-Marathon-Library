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






	//not full
	class HUDOption:public Sonicteam::SoX::RefCountObject,Sonicteam::SoX::Engine::Task
		{
		public:

			HUDOption(Sonicteam::SoX::Engine::Doc*);
			~HUDOption();
			//virtual ObjectDestroy(unsigned int flag);

			virtual void OnTaskUpdate(float);
			virtual int OnMessageRecieved(Sonicteam::SoX::Message*); //824E9850

	

			Sonicteam::SoX::RefCountObject* CSDSpriteOption; //sprite_option //0x54
			Sonicteam::SoX::RefCountObject* TextBook_msg_options; //0x58
			Sonicteam::SoX::RefCountObject* TextBook_msg_audioroom; //0x5C
			unsigned int HMMOuint0x60;
			unsigned int HMMOuint0x64;
			unsigned int HMMOuint0x68;
			unsigned int HMMOuint0x6C;
			unsigned int HMMOuint0x70;
			unsigned int HMMOuint0x74;
			unsigned int HMMOuint0x78;
			unsigned int HMMOuint0x7C;
			unsigned int HMMOuint0x80;
			unsigned int HMMOuint0x84;
			unsigned int HMMOuint0x88;
			unsigned int HMMOuint0x8C;
			unsigned int HMMOuint0x90;
			unsigned int HMMOuint0x94;
			unsigned int HMMOuint0x98;
			unsigned int HMMOuint0x9C;
			unsigned int HMMOuint0xA0;
			unsigned int HMMOuint0xA4;
			unsigned int HMMOuint0xA8;
			unsigned int HMMOuint0xAC;
			unsigned int HMMOuint0xB0;
			unsigned int HMMOuint0xB4;
			unsigned int HMMOuint0xB8;
			unsigned int HMMOuint0xBC;

			unsigned int HMMOuint0xC0;
			unsigned int HMMOuint0xC4;
			unsigned int HMMOuint0xC8;
			unsigned int HMMOuint0xCC;

			unsigned int HMMOuint0xD0;
			unsigned int HMMOuint0xD4;
			unsigned int HMMOuint0xD8;
			unsigned int HMMOuint0xDC;

			unsigned int HMMOuint0xE0;
			unsigned int HMMOuint0xE4;
			unsigned int HMMOuint0xE8;
			unsigned int HMMOuint0xEC;
			unsigned int HMMOuint0xF0;

			boost::shared_ptr<unsigned int> TextCard_msg_audio; //or weak F4
			boost::shared_ptr<unsigned int> TextCard_msg_subtitle; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_vibe; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_voice; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_moniter; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_load; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_bgm; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_se; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_japanese; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_english; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_on; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_off; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_britness; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_ganma; //or weak
			boost::shared_ptr<unsigned int> TextCard_msg_fileselect; //0x164
			unsigned int HMMOuint0x16C;
			unsigned int HMMOuint0x170;
			unsigned int HMMOuint0x174;
			unsigned int HMMOuint0x178;
			unsigned int HMMOuint0x17C;
			unsigned int HMMOuint0x180;
			unsigned int HMMOuint0x184;
			unsigned int HMMOuint0x188;
			unsigned int HMMOuint0x18C;
			unsigned int HMMOuint0x190;
			unsigned int HMMOuint0x194;
			unsigned int HMMOuint0x198;
			unsigned int HMMOuint0x19C;
			unsigned int HMMOuint0x1A0;
			unsigned int HMMOuint0x1A4;
			unsigned int HMMOuint0x1A8;
			unsigned int HMMOuint0x1AC;
			unsigned int HMMOuint0x1B0;
			unsigned int HMMOuint0x1B4;
			unsigned int HMMOuint0x1B8;
			unsigned int HMMOuint0x1BC;
			unsigned int HMMOuint0x1C0;
			unsigned int HMMOuint0x1C4;
			unsigned int HMMOuint0x1C8;
			unsigned int HMMOuint0x1CC;
			unsigned int HMMOuint0x1D0;
			unsigned int HMMOuint0x1D4;
			unsigned int HMMOuint0x1D8;
			unsigned int HMMOuint0x1DC;
			unsigned int HMMOuint0x1E0;
			unsigned int HMMOuint0x1E4;
			unsigned int HMMOuint0x1E8;
			unsigned int HMMOuint0x1EC;
			unsigned int HMMOuint0x1F0;
			unsigned int HMMOuint0x1F4;
			unsigned int HMMOuint0x1F8;
			unsigned int HMMOuint0x1FC;
	



	public:
		Sonicteam::SoX::Engine::Doc* GetCurrentDoc();

//		virtual void DestroyObject(unsigned int flag) override;



			
			


			

		


	};
};