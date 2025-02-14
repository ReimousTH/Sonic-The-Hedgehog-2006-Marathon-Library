#include "ActorManager.h"


using namespace Sonicteam;

Sonicteam::ActorManager::~ActorManager()
{

}

Sonicteam::ActorManager::ActorManager()
{

}

DESTRUCTION_CPP(ActorManager)




Sonicteam::Actor* Sonicteam::ActorManager::SearchActorByID(unsigned int& ID)
{

	unsigned int left = 0;
	unsigned int right = this->LastActorIndex-1;
	int Index = 0;

	while (left <= right) {
		unsigned int mid = left + (right - left) / 2;
		if (this->ActorID[mid] == ID) {
			Index = mid;
			break;
		}
		if (this->ActorID[mid] < ID) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	if (!this->Actor[Index]) return 0;
	return this->Actor[Index];

}
