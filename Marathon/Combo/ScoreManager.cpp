#include "ScoreManager.h"


using namespace Sonicteam::Combo;

ScoreManager::ScoreManager(void)
{
}

ScoreManager::~ScoreManager(void)
{
}

DESTRUCTION_CPP(ScoreManager);

Sonicteam::Combo::ScoreManager::ScoreManager(boost::weak_ptr<Sonicteam::GameImp> GameImp,unsigned ActorID):
GameImp(GameImp),
PlayerActorID(ActorID)
{

}
