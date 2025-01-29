#ifndef SONICTEAM__PLAYER__OBJECTPLAYER
#define SONICTEAM__PLAYER__OBJECTPLAYER

#include "Defs.h"
#include <Actor.h>
#include <Sox/Engine/Task.h>
#include <Player/RootFrame.h>
#include <Player/IModel.h>
#include <Player/State/IMachine.h>
#include <boost/shared_ptr.hpp>
#include <Player/Gauge/IGauge.h>
#include <Player/Score.h>
#include <Player/Load.h>
#include <Player/IVariable.h>
#include <Player/IDynamicLink.h>
#include <Player/IStepable/IStepable.h>
#include <Player/IExportExternalFlag.h>
#include <Player/IExportPostureRequestFlag.h>
#include <Player/IExportWeaponRequestFlag.h>
//#include <Player/IImportAnimation>
#include <Player/INotification.h>
#include <Player/AI/IBase.h>
#include <Combo/AttackManager.h>

#include <xtl.h>


namespace Sonicteam{
	
	class Cameraman; 
	class PackageBinary; 


	namespace Player{
		
		namespace State{
				class Gravity;
				
		}

		class IPostureControl; 
		class IImpulseManager;
		class Path;
		class PathGuide;
		class PathCollision;
		class PathLightDash;
		class GameMasterCommunicator;
		class IEventer;
		class PostureRodeo;
		class PathWaterSlider;
		class IImportAnimation;

		struct ObjectPlayerCreationData{
			const char *PlayerName;
			int PlayerIndex;
			int PlayerControllerID;
			int CameraActorID;
			int SetupModuleIndex;
			int Unk0x14;
			int Unk0x18;
			int Unk0x1C;
			XMVECTOR PlayerRotation;
			XMVECTOR PlayerPosition;
			int PlayerStartRingsCount;
			void *player_based_on;
			char player_unk_flag2;
		};
		struct ObjectPlayerUnk1C8{
			unsigned int Flag1;
			unsigned int Flag2;
		};
		

		class ObjectPlayer:Sonicteam::Actor{


			ObjectPlayer(Sonicteam::SoX::Engine::Task* NamedTask,ObjectPlayerCreationData* CreationData);

			virtual int OnMessageRecieved(Sonicteam::SoX::Message*) override;

			virtual char* GetObjectType() override;

			virtual void OnTaskUpdate(float) override;

			std::string PlayerLUAFile; // 0x58;
			std::string PlayerPKGFile; // 0x58;

			unsigned int CameramanActorID; //0x90
			Sonicteam::Cameraman* Cameraman; //0x94
			unsigned PlayerIndex; //0x98 (not sure )
			unsigned PlayerControllerID; //0x9C

			XMVECTOR SpawnRotation; //0xA0
			XMVECTOR SpawnPosition; //0xB0

			unsigned int SpawnRingsCount; //0xC0
			REF_TYPE(Sonicteam::SoX::RefCountObject) SpawnSource; //0xC4
			char IsPlayer; //0xC8
			char IsPostureEnabled; //0xC9
			char IsFlag0xCA; //0xCA //82196F78
			char IsFlag0xCB; //0xCB //82196F78
			REF_TYPE(Sonicteam::Player::RootFrame) RootFrame; //0xCC
			REF_TYPE(Sonicteam::PackageBinary) PackageBinary; //0xD0

			boost::shared_ptr<Sonicteam::Player::IModel> PlayerModel; //0xD4, either just Model, Replace Later 
			boost::shared_ptr<Sonicteam::Player::IPostureControl> PlayerPosture; // 0xDC
			boost::shared_ptr<Sonicteam::Player::State::IMachine> PlayerMachine; // 0xE4
			boost::shared_ptr<Sonicteam::Player::State::Gravity> PlayerGravity; // 0xEC
			boost::shared_ptr<Sonicteam::Player::IImpulseManager> PlayerImpulse; // 0xF4
			unsigned int NextSetupModuleIndex; //0xFC
			unsigned int LastSetupModuleIndex; //0x100
			boost::shared_ptr<Sonicteam::Player::IGauge> PlayerGauge; //0x104
			unsigned int unk0x10C; //0x10C
			unsigned int unk0x110; //0x110
			std::vector<boost::shared_ptr<Sonicteam::Player::IPlugIn>>* PlayerPlugins; //0x114
			
			boost::shared_ptr<Sonicteam::Player::Path> PlayerPath; //0x124
			boost::shared_ptr<Sonicteam::Player::PathGuide> PlayerPathGuide; //0x12C
			boost::shared_ptr<Sonicteam::Player::PathCollision> PlayerPathCollision; //0x134
			boost::shared_ptr<Sonicteam::Player::PathLightDash> PlayerPathLightDash; //0x13C
			boost::shared_ptr<Sonicteam::Player::Score> PlayerScore; //0x144
			boost::shared_ptr<Sonicteam::Player::GameMasterCommunicator> PlayerGameMaster; //0x14C
			boost::shared_ptr<Sonicteam::Player::Load> PlayerLoad; //0x154
			boost::shared_ptr<Sonicteam::Player::IEventer> PlayerEventer; //0x15C
			boost::shared_ptr<Sonicteam::Player::IEventer> PlayerPostureRodeo; //0x164
			unsigned int unk0x16C;
			unsigned int unk0x170;
			boost::shared_ptr<Sonicteam::Player::PathWaterSlider> PlayerPathWaterSlider; //0x174
			unsigned int PlayerSpeedDelta; //0x17C
			XMMATRIX CameraMatrix; // 0x180
			float unk0x1C0; // 0x1C0 ???
			char unk1C4; //0x1C4
			char unk1C5; //0x1C5
			char unk1C6; //0x1C6
			char unk1C7; //0x1C7

			std::vector<Sonicteam::Player::ObjectPlayerUnk1C8> ObjectPlayerUnk1C8; //0x1C8
			std::string PlayerName; //0x1D8

			unsigned int unk0x1F4; //0x1F4
			unsigned int unk0x1F8; //0x1F4 == -1
			unsigned int unk0x1FC; //0x1F4 == -1
			ObjectPlayerCreationData* PlayerSpawnData; //0x200, removes after init i think
			unsigned int PlayerExportFlag1; //0x204 i think
			unsigned int unk0x208; //0x208
			unsigned int unk0x20C; //0x20C
			unsigned int unk0x210; //0x210
			unsigned int PlayerExportFlag2; //0x214
			unsigned int unk0x218; //0x218

			std::vector<boost::shared_ptr<Sonicteam::Player::IVariable>> PlayerIVarible; //0x21C
			std::vector<boost::shared_ptr<Sonicteam::Player::IDynamicLink>> PlayerIDynamicLink; //0x22C
			std::vector<boost::shared_ptr<Sonicteam::Player::IFlagCommunicator>> PlayerIFlagCommunicator; //0x23C

			std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>> PlayerIStepable1; //0x24C
			std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>> PlayerIStepable2; //0x25C
			std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>> PlayerIStepable3; //0x26C
			std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>> PlayerIStepable4; //0x27C
		
			std::vector<boost::shared_ptr<Sonicteam::Player::IExportExternalFlag>> PlayerIExportExternalFlag; //0x28C;
			std::vector<boost::shared_ptr<int>> PlayerUnk0x29C; //0x29C (not used)

			std::vector<boost::shared_ptr<Sonicteam::Player::IExportPostureRequestFlag>> PlayerIExportPostureRequestFlag; //0x2AC
			std::vector<boost::shared_ptr<Sonicteam::Player::IExportWeaponRequestFlag>> PlayerIExportWeaponRequestFlag; //0x2BC
			std::vector<boost::shared_ptr<Sonicteam::Player::IImportAnimation>> PlayerIImportAnimation; //0x2CC
			std::vector<boost::shared_ptr<Sonicteam::Player::INotification>> PlayerINotification; //0x2DC


			boost::shared_ptr<Sonicteam::Player::AI::IBase> PlayerAIAmigo; //0x2EC
			unsigned int unk0x2F4;
			unsigned int unk0x2F8;
			REF_TYPE(Sonicteam::Combo::AttackManager) PlayerComboAttackManager; //0x2FC
			unsigned int unk0x300;
			unsigned int unk0x304;
			unsigned int unk0x308;
			unsigned int unk0x30C;
			 
	

		};

	}
}




#endif
