#include "CScene.h"


using namespace Chao::CSD;


Chao::CSD::CScene::CScene(void)
{

}

Chao::CSD::CScene::~CScene(void)
{

}

void Chao::CSD::CScene::DestroyObject(unsigned int flag)
{
	if ( (flag & 1) != 0){
		Sonicteam::CMemoryAllocMarathon::GetInstance()->FFreeMemoryA((void*)this);
	}

}
