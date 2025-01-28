#pragma once
#include <vector>
#include <Sox/Engine/Doc.h>
#include <Sox/Graphics/FrameSynchronizer.h>
#include <Sox/Engine/View.h>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>


namespace Sonicteam{



	struct DocMarathonImpVecFlags{
		unsigned int Flag0;
		unsigned int Flag1;
		unsigned int Flag2;
		unsigned int Flag3;

	};
	//not full
	struct DocMarathonPlayerInput{
		unsigned int Index;
		unsigned int PInput;
	};


	//not complete :(

	class DocMarathonImp:public Sonicteam::SoX::Engine::Doc
		{
		public:

			DocMarathonImp(unsigned int); //ptr SonicTeamEngineApplication
			~DocMarathonImp(void);
		


			virtual void EngineDocOnUpdate(float);
			virtual void EngineDocDomeSome();
			virtual unsigned int DocGetMyGraphicDevice();
			virtual Sonicteam::SoX::Graphics::FrameSynchronizer* DocGetFrameSynchronizer();
			virtual boost::shared_ptr<unsigned int> DocDoUnkAction01(unsigned int,unsigned int); //8204ACD8
			virtual boost::shared_ptr<unsigned int> DocDoculistAction01(unsigned int); //8204ACDC Doculist
			virtual std::vector<unsigned int>* DocGetDoculist(); //8204ACE0 Doculist
			virtual unsigned int DocDoUnkAction02(unsigned int); //8204ACD8 (Get Boot)
			virtual unsigned int DocDoUnkModules(); //8204ACD8 (Get Boot)
			virtual unsigned int GetPlayerInput(unsigned int); //need complete struct ,index
			virtual DocMarathonImpVecFlags* GetDocImpFlag(); //need complete struct ,index
			virtual unsigned int GSDocFrameSynchronizer(unsigned int); //need complete struct ,index
			virtual DocMarathonPlayerInput DocGetPlayerInputCopy(unsigned int); //need complete struct ,index
			virtual unsigned int DocGetCurrentCase(); //need complete struct ,index
			virtual unsigned int DocGetPreviousCase(); //need complete struct ,index
			virtual unsigned int DocGetSFXAgent(); //need complete struct ,index
			virtual unsigned int DocGetImageFilterCollection(); //need complete struct ,index
			virtual unsigned int DocGetPostprocessController(); //need complete struct ,index
			virtual unsigned int DocGetCurrentMessage(); //need complete struct ,index
			virtual boost::shared_ptr<unsigned int> DocGetAudioPlayerImp(); //need complete struct ,index
			virtual unsigned int DocSetCurrentMode(unsigned int); //need complete struct ,index
			virtual unsigned int DocGetDebug3DFont(); //need complete struct ,index
			virtual unsigned int DocGetSceneParamManager(); //need complete struct ,index
			virtual unsigned int DocGetUnkManagers(); //need complete struct ,index
			virtual unsigned int DocGetUnkGameResources(); //need complete struct ,index
			virtual void DocNull01() {};
			virtual void DocNull02() {};
			virtual unsigned int DocGetUnkFloatParam01(); //need complete struct ,index
			virtual unsigned int DocResetUnkLoadingFlag01(); //need complete struct ,index
			virtual unsigned int DocGetUnkLoadingFlag02(); //need complete struct ,index
			virtual unsigned int DocResetUnkLoadingFlag02(); //need complete struct ,index
			virtual unsigned int DocGetUnkLoadingFlag01(); //need complete struct ,index
			virtual void DocNull03() {};
			virtual void DocNull04() {};
			virtual void DocNull05() {};
			virtual unsigned int DocResetUnkFlag01(); //need complete struct ,index
			virtual unsigned int DocPauseGame(unsigned char); //need complete struct ,index
			virtual unsigned int DocLoadScene(const char*); //need complete struct ,index
			virtual unsigned int DocGetuintgap0x114(); //need complete struct ,index
			virtual unsigned int DocGetuintgap0x234(); //need complete struct ,index
			virtual unsigned int DocChangeGameSpeed(unsigned char,double); //need complete struct ,index
			virtual unsigned int DocIsVFrameEnabled(); //need complete struct ,index
			virtual unsigned int DocChangeVFrameState(unsigned char,const char*); //need complete struct ,index
			virtual unsigned int DocCopy0x360(unsigned int); // copy element ptr
			virtual unsigned int DocGetGameRuleContext(); //need complete struct ,index
			virtual unsigned int DocSetGameRuleContext(unsigned int); //need complete struct ,index
			virtual unsigned int DocGetNamedTasks(unsigned int); //need complete struct ,index
			virtual unsigned int DoGetcuint0xFC(); //need complete struct ,index
			virtual unsigned int DoGetcuint0xF8(); //need complete struct ,index
			virtual unsigned int DocChangeSpeedState(unsigned char); //need complete struct ,index
			virtual unsigned int DocResetUnkFlag02(); //need complete struct ,index
			virtual unsigned int DocGetUnkFlag02(); //need complete struct ,index
			virtual unsigned int DocResetOnUnkFlag02(); //need complete struct ,index
			virtual void DocNull06() {};
			virtual void DocNull07() {};
			virtual void DocNull08() {};
			virtual void DocNull09() {};
			virtual void DocNull10() {};
			virtual void DocNull11() {};
			virtual unsigned int DocGetUnkStaticFlag01(); //need complete struct ,index
			virtual unsigned int DocSetStringFlags01(std::string*); //need complete struct ,index
			virtual unsigned int DocSetStringFlags02(std::string*); //need complete struct ,index
			virtual void DocNull12() {};
			virtual unsigned int DocGetUnkStaticFlag02(); //need complete struct ,index
			virtual unsigned int DocGetUnkStaticFlag02_1(); //need complete struct ,index
			virtual unsigned int DocProcessSubtitleFlag(char*,unsigned int); //compare to
			virtual unsigned int DocProcessCheckSubtitleFlag(char*); //compare to
			virtual const char* DocGetLanguage(); //need complete struct ,index
			virtual unsigned int DocGetuint0x3BC(); //need complete struct ,index
			virtual unsigned int DocGetuint0x3BC_1(); //need complete struct ,index
			virtual unsigned int DocGetuint0x2AFCC(); //need complete struct ,index
			virtual unsigned int DocGetuint0x2AFCC_1(); //need complete struct ,index
			virtual unsigned int DocGetuint0x55BDC(); //need complete struct ,index
			virtual unsigned int DocGetuint0x55BDC_1(); //need complete struct ,index
			virtual unsigned int DocGetuint0x55C24(); //need complete struct ,index
			virtual unsigned int DocGetuint0x55C24_1(); //need complete struct ,index
			virtual unsigned int SetP1RealControllerID(unsigned int); //need complete struct ,index
			virtual unsigned int GetP1RealControllerID(); //need complete struct ,index
			virtual unsigned int SetRealControllerID(unsigned int,unsigned int); //need complete struct ,index
			virtual unsigned int GetRealControllerID(unsigned int); //need complete struct ,index

			virtual unsigned int DocGet0x55C54();
			virtual unsigned int DocSet0x55C54(int value);
			virtual unsigned int DocSet0x55C58(char flag);
			virtual unsigned int DocGet0x5C5C();
			virtual unsigned int DocSet0x5C5C(int v);
			virtual unsigned int DocProcessShaderMode(int mode);



			//field
			Sonicteam::SoX::Engine::Task* DocCurrentDocMode; //MainMode (0x5C) But ... StateGamemode ..... (DocMode)
			unsigned int DocMyGraphicDevice; //0x60
			unsigned int DocSceneParamManager; //0x64
			std::vector<unsigned int>* Doculist; //0x68;
			unsigned int DocSceneCollection; //0x6c;
			unsigned int Docuint0x70;
			unsigned int Docuint0x74;
			unsigned int Docuint0x78;
			unsigned int Docuint0x7C;
			//and soo onnn later
			Sonicteam::SoX::Graphics::FrameSynchronizer DocFrameSynchronizer;

			boost::shared_ptr<unsigned int>* DocMarathonPlayerInputBostArray; // maybe boost???!
			unsigned int Docuint0xA4;
			unsigned int Docuint0xA8;
			Sonicteam::SoX::Engine::View DocEngineView;
			DocMarathonImpVecFlags DocImpFlag; //0xB8
			boost::shared_ptr<unsigned int> DocAudioPlayerImp; //PTR
			unsigned char IsVFrameEnabled; //Frame skip
			unsigned char Docuint0xD1; //unknown param (Freeze game?????)
			unsigned char NotUseParticle; //Frame skip  D2
			unsigned char EnableGe1Particle; //Frame skip D3
			unsigned int CurrentCase; //maybe
			unsigned int PreviousCase; //naybe
			unsigned int DocSFXAgent; // (82635BC8 later)
			unsigned int DocImageFilterCollection; //82633088
			unsigned int DocPostprocessController; //8262A140 E4
			unsigned int Docuint0xE8;
			unsigned int DocUnkFlag01;
			unsigned int Docuint0xF0;
			unsigned int DocCurrentMessage; //maybe (F4)
			unsigned int Docuint0xF8; //unk ptr to some
			unsigned int Docuint0xFC;
			unsigned int Docuint0x100;
			unsigned int Docuint0x104;
			unsigned int DocDebug3DFont; //0x108
			boost::shared_ptr<unsigned int> MyGraphicsCommonFactory; //0x10C
			//0x114
			unsigned char Docuintgap0x114[0x120];
			unsigned char Docuintgap0x234[0x120];
			unsigned int DocGameRuleContext; //0x354
			unsigned int Docuint0x358;
			unsigned int Docuint0x35C;
			unsigned int Docuint0x360;
			unsigned int Docuint0x364;
			unsigned int Docuint0x368;
			unsigned int Docuint0x36C;
			unsigned int Docuint0x370;
			unsigned int Docuint0x374;
			unsigned int Docuint0x378;
			float Docuint0x37C; //UnkFloatParam01
			unsigned int DocUnkLoadingFlag; //mb
			unsigned int Docuint0x384;
			unsigned int DocUnkManagers; //?????? 0x388
			unsigned int DocUnkGameResources; //?????? 0x38C


			unsigned int Docuint0x390;
			unsigned int Docuint0x394;
			unsigned int Docuint0x398;
			unsigned int Docuint0x39c;
			unsigned int Docuint0x3A0;
			unsigned int Docuint0x3A4;
			unsigned int Docuint0x3A8;
			unsigned int Docuint0x3AC;
			unsigned int Docuint0x3B0;
			unsigned int Docuint0x3B4;
			unsigned int DocUnkFlag02;
			unsigned int Docuint0x3BC;


			/*GameIMP
			Sonicteam::SoX::Engine::Task* GameRootTask; // 0x1418	
			Sonicteam::SoX::Engine::Task* NamedActorDependGame; // 0x141C
			Sonicteam::SoX::Engine::Task* NamedActorEntities; // 0x1420
			Sonicteam::SoX::Engine::Task* NamedActorEnemyThread; // 0x1424
			Sonicteam::SoX::Engine::Task* NamedActorPlayers; // 0x1428
			Sonicteam::SoX::Engine::Task* NamedActorCameras; // 0x142C
			Sonicteam::SoX::Engine::Task* NamedActorSystemDependCameras; // 0x1430
			Sonicteam::SoX::Engine::Task* NamedActorDependCameras; // 0x1434
*/

			unsigned char Docuintgap0x3C0[0x2AC0C];
			unsigned int Docuint0x2AFCC;
			unsigned char Docuintgap0x2AFD0[0x2AC0C];
			unsigned int Docuint0x55BDC;
			unsigned char Docuintgap0x55BE0[0x44];
			unsigned int Docuint0x55C24;

			unsigned int DocPlayer1ControllerIndex2; //0x55C28
			unsigned int DocPlayer2ControllerIndex2; //0x55C2c
			unsigned int DocPlayer3ControllerIndex2; //0x55C30
			unsigned int DocPlayer4ControllerIndex2; //0x55C34	
	

			//not complete









			

		


	};
};