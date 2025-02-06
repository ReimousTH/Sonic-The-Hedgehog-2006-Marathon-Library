#include "SPAabbTree.h"


using namespace Sonicteam::SoX::Scenery;



Sonicteam::SoX::Scenery::SPAabbTree::SPAabbTree():
AABBObjects(0),
AABBCount(0)
{

}

Sonicteam::SoX::Scenery::SPAabbTree::~SPAabbTree()
{

}

void Sonicteam::SoX::Scenery::SPAabbTree::initialize(int count)
{
	this->AABBObjects = new AABB[count];
	this->AABBCount = count;
}

void Sonicteam::SoX::Scenery::SPAabbTree::insert(const AABB& box,unsigned int index)
{
	this->AABBObjects[index] = box;
}

void Sonicteam::SoX::Scenery::SPAabbTree::add(const AABB& box)
{
	
	unsigned int PreviousCount = this->AABBCount;
	this->AABBCount += 1;
	AABB* newAABBs = new AABB[this->AABBCount];
	if (this->AABBObjects) {
		memcpy(newAABBs, this->AABBObjects, PreviousCount * sizeof(AABB));
		delete[] this->AABBObjects; // Free old memory
	}
	newAABBs[PreviousCount] = box;


	if (PreviousCount > 0) {
		newAABBs[PreviousCount].unk0 = PreviousCount - 1; // Point to previous box
		newAABBs[PreviousCount].unk4 = PreviousCount;     // Could point to itself or next index
	} else {
		newAABBs[PreviousCount].unk0 = 0; // First element points to itself or default value
		newAABBs[PreviousCount].unk4 = 0; // Default initialization
	}

	this->AABBObjects = newAABBs;


}





void Sonicteam::SoX::Scenery::SPAabbTree::SPAabbTreeInitialize(Sonicteam::SoX::Scenery::SPWorld* SPWorld,SPAabbNodeVector* VectorData,unsigned int count)
{

}
