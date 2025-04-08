#include "Scene.h"


using namespace Chao::CSD;

Scene::Scene()
{

}

Scene::~Scene()
{

}

size_t Scene::GetMotionIndexFromName(const char* animation)
{
	
	for (int i = 0;i<static_cast<size_t>(this->_Motion.count);i++){

		Chao::IndexValueName* ivn =  &this->_Motion.NameTable.values[i];
		if (strcmp(ivn->first.get(),animation) == 0){
			return ivn->second.get();
		}
	
	}

	return -1;	
}
