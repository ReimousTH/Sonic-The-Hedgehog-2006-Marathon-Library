





#ifndef Sonicteam_GameImp
#define Sonicteam_GameImp



#include <vector>
#include <xmath.h>

#include <string>


#include <Stage/Object.h>
#include <Sox/Engine/Task.h>
#include <Sox/MessageReceiver.h>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <DocMarathonImp.h>
#include <CsdObject.h>
#include <Sox/IResource.h>
#include <ActorManager.h>
#include <Player/Load.h>
#include <ActorManager.h>



#include <Prop/PropClass.h>
#include <Prop/Manager.h>
#include <Prop/Scene.h>
#include <Prop/GenerateArea.h>
#include <Prop/Manager.h>
#include <Prop/IActorCreator.h>
#include <Prop/ActorCreators.h>
#include <Prop/Library.h>

#define  GAMEIMP_START_LEVEL 1
#define  GAMEIMP_START_CUTSCENE 2
#define  GAMEIMP_START_CGI_CUTSCENE 3
#define  GAMEIMP_STOP_LEVEL 4
#define  GAMEIMP_STOP_CUTSCENE 5
#define  GAMEIMP_DESTROY_ALL 9


namespace Sonicteam{

	struct SetType{
		enum ST_ENUM{
			Default,
			Design,
			Particle,
			Test,
			Area,
			PathObj
		};
	};


	struct UnkPointerStructGI{
		char buffer[0x3200];
	};

	struct UnkPlayerData0x30{
		std::string character_start_lua;
		unsigned char _padding_0x1C[0x4]; //for XMVECTOR
		XMVECTOR character_start_rotation;
		XMVECTOR character_start_position;
		unsigned int character_start_flags; // Usually First Byte
		std::string character_restart_lua; // choose this lua after restart?:/death
		XMVECTOR character_restart_rotation; //not working 
		XMVECTOR character_restart_position; //not working

		XMMATRIX character_old_matrix_1;
		unsigned int character_old_flags; //Usually First Byte
		XMFLOAT3 character_old_data_1;
		XMVECTOR character_old_data_2;
		XMVECTOR character_old_data_3;


	};
	//0x4C;
	struct UnkPlayerData0xE40{
		unsigned int ActorID; //0x0
		unsigned int RingCount; //0x4
		unsigned int unk0xC; //0x8
		unsigned int LifeCount; //0xC
		unsigned int ScoreCount; //0x10
		float AliveTime; // 0x14
		float Time; //0x18
		unsigned int unk0x1C; //0x1C
		float SectionSaveTime; //0x20
		float MaturityLevel; //0x24
		float LastGaugeValue; // probably //0x28
		float MaturityValue; //0x2C
		unsigned int unk0x30; // probably //0x30
		int unk0x34; //probably : //0x34
		int SelectedGem;  //0x38
		unsigned char _later_[0x10]; //0x3C
	};








	//not complete :(

	class GameImp:Sonicteam::SoX::MessageReceiver
	{
	public:
		~GameImp();
		GameImp();



		unsigned int				PrevState;
		unsigned int				CurState;
		//replace to State Later
		Sonicteam::DocMarathonImp*	DocMarathon;
		unsigned int				CurFlags;
		UnkPointerStructGI*			UnkPointerStruct;

		unsigned int				UnkFlag0x18;
		unsigned int				UnkFlag0x1C;
		unsigned int				Unk0x20;
		unsigned int				Unk0x24;
		unsigned int				UnkFlag0x28; //first byte ussualy
		unsigned int				Unk0x2C; //first byte ussualy


		UnkPlayerData0x30 PlayerStartData[0xF]; //0x30
		UnkPlayerData0xE40 PlayerGameplayerData[0x4]; //0xE40
		UnkPlayerData0xE40 PlayerGameplayerData_1[0x4]; //0xF70 // yes same O_O why?


		Sonicteam::SoX::LinkNodeA<Sonicteam::SoX::Engine::Task> TaskAdapter_TL_HeadUpDisplay; //0x10A0, eiter 0x0 separater OR  is part of it or just complilator :|
		Sonicteam::SoX::LinkNodeA<Sonicteam::SoX::Engine::Task> TaskAdapter_TL_NonStopTask; //0x10B0;
		unsigned int GameCameraActorID[4]; // 0x10C0, usually -1, or oxFFFFFFFF
		Sonicteam::SoX::Engine::Task* PauseAdapter; //0x10D0
		Sonicteam::SoX::Engine::Task* ImpactManager; //0x10D4
		std::string GameArea; //0x10D8  //wap/shadow/a


		//0x10F4
		struct{
			Sonicteam::CsdObject* CSDPausemenu;
			Sonicteam::CsdObject* CSDEnemyPowergauge;
			Sonicteam::CsdObject* CSDTalkwindow;

			Sonicteam::CsdObject* operator[](int index){
				if (index > 3) return 0;
				return (&CSDPausemenu)[index];
			}
		} GameBaseCSD;

		Sonicteam::CsdObject* CSDRadarmapcover; //0x1100
		Sonicteam::SoX::IResource* Graphictex_en_ocnoise; //0x1104
		Sonicteam::SoX::IResource* Graphictex_radarmap_mask; //0x1108

		boost::shared_ptr<GameImp> CurGameImpulse; //0x110C
		std::string LastGameScript; //mb, nothing when loaded :  0x1114
		unsigned char _no_idea_0x1130[3*0x1C];
		Sonicteam::SoX::MessageReceiver* GameScript; // GameScript //0x1184
		unsigned int ObjPlayersActorID[0xF]; //0x1188 // contain table of each player actor ID, amigo change included(like kdv silver) mb mor
		boost::shared_ptr<Sonicteam::ActorManager> GameActorManager; //0x11C4
		Sonicteam::SoX::IResource* TextBook_msg_system; //0x11CC
		unsigned int unk0x11D0;
		unsigned int unk0x11D4;
		unsigned int unk0x11D8;
		unsigned int unk0x11DC;
		unsigned int unk0x11E0;
		unsigned int unk0x11E4;
		std::vector<boost::shared_ptr<unsigned int>> GameImpSceneryWorlds;  //Sonicteam::SoX::Scenery::WorldImp, ...glare,particle ... unk0x11E8
		Sonicteam::Stage::Object StageObject; //0x11F8
		std::string GameTerrain; //stage/wvo/a/ //0x1214
		Sonicteam::SoX::LinkNodeA<Sonicteam::SoX::Engine::Task> GamePlayerDisplayTask[4]; // Sonicteam::MainDisplayTask 0x1230

		boost::shared_ptr<unsigned int> GamePropActivationMgr; //Sonicteam::Prop::ActivationMgr //0x1270
		boost::shared_ptr<Sonicteam::Prop::Manager> GamePropManager; //Sonicteam::Prop::Manager (without VFT) 0x82461E48 //0x1278


		struct GamePropLibaryVariant{
			enum{
				Camera,
				ObjCommon,     
				Kingdomvalley, 
				Crisiscity,  
				Whiteacropolis,
				Dustydesert, 
				Tropicaljungle,
				Radicaltrain, 
				Flamecore,   
				Town,      
				Waveocean,     
				Aquaticbase,   
				Endoftheworld
			};
			Sonicteam::Prop::Library* props[0xD];
			Sonicteam::Prop::Library* operator[](int index){
				return props[index];
			}
		} GamePropLibary; //0x1280


		struct GameSetVariant{
			enum{
				Default,
				Design,
				Particle,
				Test,
				Area,
				PathObj
			};
			std::string sets[6]; //0x12B4
			std::string* operator[](int index){
				return &sets[index];
			}
		} GameSet;

		//821826A8

		boost::shared_ptr<Sonicteam::Prop::Scene> GameProp[6]; 	//0x135C boost::shared_ptr<Sonicteam::Prop::Scene>[] // 							
		boost::shared_ptr<unsigned int> GameKynapseSystem; //Sonicteam::KynapseSystem 		//0x138C 
		Sonicteam::SoX::IResource* GameKyWorldDef; //Sonicteam::KyWorldDef //0x1394
		unsigned int unk0x1398;
		Sonicteam::SoX::RefCountObject* GameMyCueAdx; //8204D19C  //0x139C
		Sonicteam::SoX::IResource* GameMySoundBankSystem; //0x8204D120  //0x13A0
		Sonicteam::SoX::IResource* GameMySoundBankBGM; //0x8204D120  //0x13A4
		Sonicteam::SoX::IResource* GameMySoundBankObjCommon; //0x8204D120  //0x13A8
		Sonicteam::SoX::IResource* GameMySoundBankVoiceAll; //0x8204D120  //0x13AC
		Sonicteam::SoX::IResource* GameMySoundBankStage; //0x8204D120  //0x13B0 //sound/stage_twn
		Sonicteam::SoX::IResource* GameMySoundBankStageVoice; //0x8204D120  //0x13B4 //sound/voice_twn_e
		unsigned int unk0x13B8;
		unsigned int unk0x13BC;
		Sonicteam::SoX::RefCountObject* MyCueCriAu; //8204D0A0 //13C0
		unsigned int unk0x13C4;
		unsigned int unk0x13C8;	
		unsigned int unk0x13CC;
		unsigned int unk0x13D0; // ?	
		Sonicteam::SoX::LinkNodeA<Sonicteam::SoX::Engine::Task> GameEnemyLifeTask; //0x13D4
		unsigned int unk0x13E4; // ?	
		unsigned int unk0x13E8; // ?	
		unsigned int unk0x13EC; // ?	
		unsigned int unk0x13F0; // ?	
		unsigned int GameObjInfoMgr; // ?	 Sonicteam::ObjInfoMgr //0x13F4
		Sonicteam::SoX::RefCountObject* GameEnemyShotInfo; // ?	// Sonicteam::Enemy::ShotInfo 0x13F8
		Sonicteam::SoX::RefCountObject* GameExplosionInfo; // ?	 //0x13FC
		Sonicteam::SoX::RefCountObject* GameCommonObjectChaosDriveInfo; // Sonicteam::CommonObjectChaosDriveInfo // 0x1400
		Sonicteam::SoX::RefCountObject* GameRingObjInfo; //  Sonicteam::RingObjInfo // 0x1404
		std::vector<Sonicteam::SoX::RefCountObject*> GameCommonObjectInfo; // //Jump123ObjInfo, Spring.... //0x1408

		Sonicteam::SoX::Engine::Task* GameRootTask; //0x1418
		Sonicteam::SoX::Engine::Task* GameNamedActorDependGame; //0x141C
		Sonicteam::SoX::Engine::Task* GameNamedActorEntities; //0x1420
		Sonicteam::SoX::Engine::Task* GameNamedActorEnemyThread; //0x1424
		Sonicteam::SoX::Engine::Task* GameNamedActorPlayers; //0x1428
		Sonicteam::SoX::Engine::Task* GameNamedActorCameras; //0x142C
		Sonicteam::SoX::Engine::Task* GameNamedActorSystemDependCameras; //0x1430
		Sonicteam::SoX::Engine::Task* GameNamedActorDependCameras; //0x1434


		struct StagePathVariant{
			enum {
				Default,
				Grind,
				Guide,
				PathObj,
				PhysicsPath
			};
			std::string paths[5];  //0x1438
			std::string* operator[](int index) {
				return &paths[index];
			}
		} GameStagePath;

		struct StagePathSplineVariant{
			enum {
				Default,
				Grind,
				Guide,
				PathObj,
				PhysicsPath
			};
			Sonicteam::SoX::IResource* paths[5];  //0x14C4
			Sonicteam::SoX::IResource* operator[](int index) {
				return paths[index];
			}
		} GameSplinePath;


		struct GameKeyframedPathSceneVariant{
			enum {
				Default,
				Grind,
				Guide,
				PathObj,
				PhysicsPath
			};
			boost::shared_ptr<Sonicteam::SoX::RefCountObject*> keyframes[5];  //0x14D8
			boost::shared_ptr<Sonicteam::SoX::RefCountObject*>* operator[](int index) {
				return &keyframes[index];
			}
		} GameKeyframedPathScene;


		boost::shared_ptr<unsigned int> GameMeshPathScene[2]; //0x1500, Grind, Guide 
		boost::shared_ptr<unsigned int> GameMeshPathManager; //Sonicteam::MeshPathManage //0x1510
		boost::shared_ptr<unsigned int> GameKeyframedPathManager; //Sonicteam::KeyframedPathManager //0x1518

		boost::shared_ptr<Sonicteam::Player::Load> GamePlayerLoad; //0x1520

		//0x152C //_8216EDD8 _0x1DC (+-4)
		struct{
			//Base
			Sonicteam::SoX::Thread* HavokRunnerThread; //0x1528 // or comp do -4, or they do it O_O
			//
			std::string CameraParamLua; //placement/kdv/cameraparam_sonic_c.lua  //0x152C //0x0
			std::string RenderScript; //scripts/render/stage/render_kdv_c.lua //  0x1548 - 0x1C, 
			std::string SceneParamsLua; //scripts/stage/kdv/scene_kdv_c.lua , get empty after load i guess :) //0x1564 - 0x38
			std::string Light;  //  ,  //0x1580 - 0x54
			std::string EnvMap;  //  ,  //0x159C - 0x70
			std::string Terrain;  //  stage/kdv/c/ ,  //0x15B8 - 0x8C
			std::string Sky;  //  ,  //0x15D4 - 0xA8
			std::string AreaName;  //  ,  //0x15F0 - 0xC4
			std::string unk0xE0;  //  ,  //0x160C - 0xE0 //Old Default Path
			std::string Kynapse;  //  ,  //0x1628 - 0xFC
			std::string TownsManInfo; // , 	 //0x1644 - 0x118
			std::string Radarmap; // , 	 //0x1660 - 0x134
			std::string BGM; // , stg_kdv_c 	 //0x167C - 0x150  (BGM)
			std::string ObjectPhysics; // , 	 //0x1698 - 0x16C
			std::string Explosion; // , 	 //0x16B4 - 0x188
			std::string Enemy; // , 	 //0x16D0 - 0x1A4
			std::string Shot; // , 	 //0x16EC - 0x1C0

		} GameLoaLuaInfo;

		struct{
			enum{
				msg_hint,
				msg_hint_xenon
			};
			Sonicteam::SoX::IResource* hints[2]; 	//0x1708
		} GameHintTextBook;
		//0x1710
		unsigned unk0x1710;
		Sonicteam::SoX::MessageReceiver* GameMissionCore; //Sonicteam::Mission::Core //0x1714

		std::string unk0x1718; //0x1718
		std::string unk0x1734; //0x1734

		Sonicteam::SoX::LinkNodeA<unsigned int> unk0x1750; // 0x1750 -0x10
		std::string unk0x1760; // 0x1760 
		std::string unk0x177C; // 0x177C	 
		std::string unk0x1798; // 0x1798	 
		std::string unk0x17B4; // 0x17B4	

		std::string unk0x17D0; // 0x17D0 
		std::string unk0x17EC; // 0x17EC 

		boost::shared_ptr<unsigned int> unk0x1808[6]; //0x1808
		unsigned int unk0x1838; // 0x1838
		unsigned int unk0x183C; //0x183C
		Sonicteam::SoX::LinkNodeA<unsigned int> unk0x1840; // 0x1840 -0x10

		struct unk0x1850_struct{
			std::string unk0x0; //0x0;
			unsigned int unk0x1C; //0x1C
			unsigned int unk0x20; //0x20
			unsigned int unk0x24; //0x24
			unsigned int unk0x28; //0x28
			unsigned int unk0x2C; //0x2C
			unsigned int unk0x30; //0x30
			unsigned int unk0x34; //0x34
			unsigned int unk0x38; //0x38
			unsigned int unk0x3C; //0x3C
			unsigned int unk0x40; //0x40
			unsigned int unk0x44; //0x44
			unsigned int unk0x48; //0x48
			unsigned int unk0x4C; //0x4c
			unsigned int unk0x50; //0x50
			std::string unk0x54;
		} unk0x1850; // 0x1850 -0x10
		unsigned int unk0x18C0; // 0x18C0
		unsigned int unk0x18C4; // 0x18C4
		unsigned int unk0x18C8; // 0x18C8
		unsigned int unk0x18CC; // 0x18CC
		unsigned int unk0x18D0; // 0x18D0
		unsigned int unk0x18D4; // 0x18D4
		unsigned int unk0x18D8; // 0x18D8
		unsigned int unk0x18DC; // 0x18DC
		unsigned int unk0x18E0; // 0x18E0

		std::vector<unsigned int> unk0x18E4; // ... //0x18E4 ,0x20 - size of struct
		std::vector<unsigned int> unk0x18F4; // ... //0x18F4 ,0x20 - size of struct
		Sonicteam::SoX::IResource*  GameMapParticleContainer; //particle/map_common.plc //Sonicteam::Particles::ParticleContainer // 0x1904
		std::vector<Sonicteam::SoX::IResource*> GameStateParticleContainer; // others //Sonicteam::Particles::ParticleContainer, .plc //0x1908
		unsigned int unk0x1918; // 0x1918
		unsigned int unk0x191C; // 0x191C
		unsigned int unk0x1920; // 0x1920


		unsigned int unk0x1924; // 0x1924
		unsigned int unk0x1928; // 0x1928
		float unk0x192C; // 0x192C
		std::string unk0x1930; // 0x1930
		unsigned int unk0x194C; // 0x1958
		unsigned int unk0x1950; // 0x1950
		unsigned int GamePhysicsMaterialMgr; // 0x1954 //Sonicteam::PhysicsMaterialMgr:
		Sonicteam::SoX::Engine::Task* GameRaderMapManager; // 0x1958 //Sonicteam::RaderMapManager
		Sonicteam::SoX::Engine::Task* GameRadarMapIcon; // 0x195C //Sonicteam::RadarMapIcon

		Sonicteam::SoX::LinkNodeA<Sonicteam::SoX::Engine::Task> GamePopupScreenTask; //Sonicteam::PopupScreenTask //0x1960
		unsigned int unk0x1970; //0x1970
		Sonicteam::SoX::LinkNodeA<unsigned int> GamePopupScreenTask2; //Sonicteam::PopupScreenTask //0x1974
		Sonicteam::SoX::LinkNodeA<unsigned int> GamePopupScreenTask3; //Sonicteam::PopupScreenTask //0x1984





		//PlayersRenderArea
		Sonicteam::SoX::RefCountObject* GamePropActiveArea[4]; // 0x1994
		Sonicteam::SoX::RefCountObject* GamePropGenerateArea[4]; // 0x19A4
		boost::shared_ptr<Sonicteam::Prop::ActorCreators> GamePropActorCreators; //0x19B4
		Sonicteam::SoX::RefCountObject* GameWorldHavok; // 0x19BC
		Sonicteam::SoX::RefCountObject*  GameMyCollisionFilter; //Sonicteam::MyCollisionFilter // 0x19C0
		unsigned int unk0x19C4; // 0x19C4
		unsigned int unk0x19C8; // 0x19C8
		unsigned int unk0x19CC; // 0x19CC
		unsigned int unk0x19D0; // 0x19D0









		virtual void DestroyObject(unsigned int flag);
		virtual int OnMessageRecieved(Sonicteam::SoX::Message*);


		virtual bool IsPrevDestroyAll();
		virtual Sonicteam::DocMarathonImp* GetDocMarathon();
		virtual boost::shared_ptr<Sonicteam::ActorManager> GetActorManager();
		virtual bool IsGameKyWorldDef();
		virtual Sonicteam::SoX::RefCountObjContainer<Sonicteam::SoX::RefCountObject> GetWorldHavok();
		virtual unsigned int CollisionFilterFunc01(unsigned int);
		virtual unsigned int GetGameObjInfoMgr();
		virtual void GameActivateProp(Sonicteam::SoX::RefCountObject**);
		virtual void GameImpUnk01();
		virtual boost::shared_ptr<Sonicteam::Prop::Manager> GameGetPropManager();
		virtual Sonicteam::SoX::Engine::Task* GameGetPropTask(unsigned int);
		virtual boost::shared_ptr<Sonicteam::Player::Load> GameGetPlayerLoad();
		virtual boost::shared_ptr<Sonicteam::SoX::RefCountObject*>* GameGetKeyFramedScene(unsigned int);
		virtual std::string* GameGetCameraParamLua();
		virtual bool GameOLDGetActivePlayerA0Pos_1(XMVECTOR*,double); //not used ??????
		virtual bool GameOLDGetActivePlayerA0Pos_2(XMVECTOR*,double); //not used ??????
		virtual bool GameNEWGetActivePlayerA0Pos(XMVECTOR*,double);
		virtual Sonicteam::SoX::Engine::Task* GameGetImpactManager();
		virtual void GameProcessGlobalEventActions(double a2);
		virtual int GameGetSoundData();
		virtual int GameParticleContainerFirstData();
		virtual int GameGetGameRuleContext();
		virtual int GameGetPhysicsMaterialMgr();
	};
};
#endif


