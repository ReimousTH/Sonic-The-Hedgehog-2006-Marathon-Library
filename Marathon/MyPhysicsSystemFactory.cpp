#include "MyPhysicsSystemFactory.h"


using namespace Sonicteam;




Sonicteam::MyPhysicsSystemFactory::MyPhysicsSystemFactory(void)
{

}

//not complete
Sonicteam::MyPhysicsSystemFactory::~MyPhysicsSystemFactory(void)
{
	
	
}



Sonicteam::SoX::Physics::Havok::SphereShapeHavok* Sonicteam::MyPhysicsSystemFactory::CreateSphereShapeHavok(double radius)
{
	return new Sonicteam::SoX::Physics::Havok::SphereShapeHavok(radius);
}

Sonicteam::SoX::Physics::Havok::BoxShapeHavok* Sonicteam::MyPhysicsSystemFactory::CreateBoxShapeHavok(double width,double height,double length)
{
	return new Sonicteam::SoX::Physics::Havok::BoxShapeHavok(width,height,length);
}

Sonicteam::SoX::Physics::Havok::CapsuleShapeHavok* Sonicteam::MyPhysicsSystemFactory::CreateCapsuleShapeHavok(double radius,double height)
{
	return new Sonicteam::SoX::Physics::Havok::CapsuleShapeHavok(radius,height);
}

Sonicteam::SoX::Physics::Havok::CylinderShapeHavok* Sonicteam::MyPhysicsSystemFactory::CreateCylinderShapeHavok(double radius,double height)
{
	return new Sonicteam::SoX::Physics::Havok::CylinderShapeHavok(radius,height);
}

void Sonicteam::MyPhysicsSystemFactory::CreateMeshShapeHavok(unsigned int* RawMesh)
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateConvexShapeHavok(unsigned int* RawMesh)
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateBodyHavokA(unsigned int* RawBody)
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateBodyHavokB()
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateMyPhantomA(unsigned int* RawPhantom)
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateMyPhantomB()
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateRayCastHavokA(unsigned int* RawRayCast)
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateRayCastHavokB()
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateShapeCastHavokA(unsigned int* RawShapeCast)
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateShapeCastHavokB()
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateLineConstraintHavok(double,unsigned int* PhysicsBody)
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateMyRagdollInfo()
{

}

void Sonicteam::MyPhysicsSystemFactory::CreatMyVehicleInfo()
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateMyLandCollisionInfo()
{

}

//not complete
void Sonicteam::MyPhysicsSystemFactory::DestroyObject(unsigned int flag)
{
	
}


MyPhysicsSystemFactory* Sonicteam::MyPhysicsSystemFactory::GetInstance()
{
	
	if (!MyPhysicsSystemFactory::Instance){

		MyPhysicsSystemFactory::Instance = &CreateInstance();
	}
	return MyPhysicsSystemFactory::Instance;
	
}

MyPhysicsSystemFactory& Sonicteam::MyPhysicsSystemFactory::CreateInstance()
{
	static MyPhysicsSystemFactory instance;
	return instance;
}

MyPhysicsSystemFactory*& Sonicteam::MyPhysicsSystemFactory::GetOriginInstance()
{
	return *MyPhysicsSystemFactoryInstanceMarathon;
}

MyPhysicsSystemFactory* Sonicteam::MyPhysicsSystemFactory::Instance;


MyPhysicsSystemFactory** Sonicteam::MyPhysicsSystemFactory::MyPhysicsSystemFactoryInstanceMarathon = (MyPhysicsSystemFactory**)0x82D3C194;

