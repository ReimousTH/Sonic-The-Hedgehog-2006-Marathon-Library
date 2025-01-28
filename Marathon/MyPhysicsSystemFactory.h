#pragma once
#include <DocMarathonImp.h>
#include <sox/Memory/IDestructible.h>
#include <Sox/Engine/Task.h>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>

#include <Sox/Physics/Havok/BoxShapeHavok.h>
#include <Sox/Physics/Havok/SphereShapeHavok.h>
#include <Sox/Physics/Havok/CapsuleShapeHavok.h>
#include "Sox/Physics/Havok/CylinderShapeHavok.h"




namespace Sonicteam{


	 
	//Or SonicTeamSoxComponent
	class MyPhysicsSystemFactory
		{
		public:
			MyPhysicsSystemFactory(void);
			~MyPhysicsSystemFactory(void);

			
			unsigned int Flag; // IsDestructible

			virtual Sonicteam::SoX::Physics::Havok::SphereShapeHavok* CreateSphereShapeHavok(double radius); //0x0 + 0x0 (void = type (r3))
			virtual Sonicteam::SoX::Physics::Havok::BoxShapeHavok* CreateBoxShapeHavok(double width,double height,double length); // width, height, length

			virtual Sonicteam::SoX::Physics::Havok::CapsuleShapeHavok* CreateCapsuleShapeHavok(double radius,double height); 
			virtual Sonicteam::SoX::Physics::Havok::CylinderShapeHavok* CreateCylinderShapeHavok(double radius,double height); // 0x0 + 0xC


			virtual void CreateMeshShapeHavok(unsigned int* RawMesh); // 0x0 + 0xC
			virtual void CreateConvexShapeHavok(unsigned int* RawMesh); // 0x0 + 0xC

			virtual void CreateBodyHavokA(unsigned int* RawBody); // 0x0 + 0xC
			virtual void CreateBodyHavokB(); //YES NO args

			virtual void CreateMyPhantomA(unsigned int* RawPhantom); // 0x0 + 0xC
			virtual void CreateMyPhantomB(); // 0x0 + 0xC

			virtual void CreateRayCastHavokA(unsigned int* RawRayCast); // 0x0 + 0xC
			virtual void CreateRayCastHavokB(); // 0x0 + 0xC

			virtual void CreateShapeCastHavokA(unsigned int* RawShapeCast); // 0x0 + 0xC
			virtual void CreateShapeCastHavokB(); // 0x0 + 0xC


			virtual void CreateLineConstraintHavok(double,unsigned int* PhysicsBody); // 0x0 + 0xC

			virtual void CreateMyRagdollInfo(); // i GUESS??
			virtual void CreatMyVehicleInfo(); // 0x0 + 0xC
			virtual void CreateMyLandCollisionInfo(); // 0x0 + 0xC
			
			
			//??????s
			void DestroyObject(unsigned int flag); //0x0 + 0x10


			static MyPhysicsSystemFactory* GetInstance();
			static MyPhysicsSystemFactory& CreateInstance();
			static MyPhysicsSystemFactory*& GetOriginInstance();


			static MyPhysicsSystemFactory* Instance;
			static MyPhysicsSystemFactory** MyPhysicsSystemFactoryInstanceMarathon;
	};
};