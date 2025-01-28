#include "GameImp.h"


using namespace Sonicteam;

void Sonicteam::GameImp::DestroyObject(unsigned int flag)
{
	Sonicteam::GameImp::~GameImp();
}

int Sonicteam::GameImp::OnMessageRecieved(Sonicteam::SoX::Message*)
{
	throw std::logic_error("The method or operation is not implemented.");
}

Sonicteam::GameImp::~GameImp()
{
	

}

Sonicteam::GameImp::GameImp()
{

}

bool Sonicteam::GameImp::IsPrevDestroyAll()
{
	return this->PrevState == 9;
}

Sonicteam::DocMarathonImp* Sonicteam::GameImp::GetDocMarathon()
{
	return this->DocMarathon;
}

boost::shared_ptr<Sonicteam::ActorManager> Sonicteam::GameImp::GetActorManager()
{
	return boost::shared_ptr<Sonicteam::ActorManager>(this->GameActorManager);
}

bool Sonicteam::GameImp::IsGameKyWorldDef()
{
	return this->GameKyWorldDef;
}

Sonicteam::SoX::RefCountObjContainer<Sonicteam::SoX::RefCountObject> Sonicteam::GameImp::GetWorldHavok()
{
	return this->GameWorldHavok;
}

unsigned int Sonicteam::GameImp::CollisionFilterFunc01(unsigned int)
{
	return 0;
	//no idea
}

unsigned int Sonicteam::GameImp::GetGameObjInfoMgr()
{
	return this->GameObjInfoMgr;
}

void Sonicteam::GameImp::GameActivateProp(Sonicteam::SoX::RefCountObject**)
{

}

void Sonicteam::GameImp::GameImpUnk01()
{

}

boost::shared_ptr<Sonicteam::Prop::Manager> Sonicteam::GameImp::GameGetPropManager()
{
	return this->GamePropManager;
}

Sonicteam::SoX::Engine::Task* Sonicteam::GameImp::GameGetPropTask(unsigned int index)
{
	 Sonicteam::SoX::Engine::Task *result; // r3
	switch ( index )
	{
	case 1:
		result = this->GameRootTask;
		break;
	case 2:
		result = this->GameNamedActorPlayers;
		break;
	case 3:
		result = this->GameNamedActorCameras;
		break;
	case 4:
		result = this->GameNamedActorDependCameras;
		break;
	case 5:
		result = this->GameNamedActorSystemDependCameras;
		break;
	case 6:
		result = this->GameNamedActorEnemyThread;
		break;
	default:
		result = this->GameNamedActorEntities;
		break;
	}
	return result;

}

boost::shared_ptr<Sonicteam::Player::Load> Sonicteam::GameImp::GameGetPlayerLoad()
{
	return this->GamePlayerLoad;
}

boost::shared_ptr<Sonicteam::SoX::RefCountObject*>* Sonicteam::GameImp::GameGetKeyFramedScene(unsigned int index)
{
	return this->GameKeyframedPathScene[index];

}

std::string* Sonicteam::GameImp::GameGetCameraParamLua()
{
	return &this->GameLoaLuaInfo.CameraParamLua;

}

bool Sonicteam::GameImp::GameOLDGetActivePlayerA0Pos_1(XMVECTOR* vec,double delta) //i guess?
{
	return false; // easy to implement i wait until Actor class
}

bool Sonicteam::GameImp::GameOLDGetActivePlayerA0Pos_2(XMVECTOR* vec,double delta)
{
	return GameOLDGetActivePlayerA0Pos_1(vec,delta);
}

bool Sonicteam::GameImp::GameNEWGetActivePlayerA0Pos(XMVECTOR*,double)
{
	return false; // ESH too much vector operations
}

Sonicteam::SoX::Engine::Task* Sonicteam::GameImp::GameGetImpactManager()
{
	return this->ImpactManager;
}

void Sonicteam::GameImp::GameProcessGlobalEventActions(double a2)
{

}

int Sonicteam::GameImp::GameGetSoundData()
{
	return 0;
}

int Sonicteam::GameImp::GameParticleContainerFirstData()
{
	return 0;
}

int Sonicteam::GameImp::GameGetGameRuleContext()
{
	return this->GetDocMarathon()->DocGetGameRuleContext();
}

int Sonicteam::GameImp::GameGetPhysicsMaterialMgr()
{
	return this->GamePhysicsMaterialMgr;
}
