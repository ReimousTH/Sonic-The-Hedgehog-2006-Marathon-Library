#ifndef SONICTEAM__SOX__PHYSICS__HAVOK__ENTITYHAVOK
#define SONICTEAM__SOX__PHYSICS__HAVOK__ENTITYHAVOK

#include <Sox/Physics/EntityContainer.h>
#include <Sox/Physics/Havok/WorldHavok.h>

#include <xtl.h>



namespace Sonicteam{
	namespace SoX{	
		namespace Physics{

			struct __declspec(align(0x10)) EntityInfo{
				size_t hkrigidbody; // guess
				Sonicteam::SoX::Physics::Havok::WorldHavok* hkworld;
			};

			namespace Havok{
				class EntityHavok
				{
				public:
					//size0x60
					EntityHavok();
					~EntityHavok();


					//Really HUH (seems Scale/Translation/Rotation not always at same position which means )

					
					//XMVECTOR Scale; //0x10
					//some kind of struct, maybe somewhere boost to it please
					Sonicteam::SoX::Physics::EntityInfo EntityInfo;
					XMVECTOR Rotation; //0x20 
					XMVECTOR Translation; //0x30
					LinkSoxNode<EntityContainer> EntityContainer; //0x40,0x44,0x48 ; // 825813F0 ref here (a2 == body havok)
					

					virtual void EntityHavokVFT01(double);
					virtual void EntityHavokVFT02();
					virtual int EntityHavokVFT03(void*,void*); //XMVECTOR*, ????
					
					//custom
					XMVECTOR GetRotation();
					XMVECTOR GetPosition();

		
					




				};
			};
		};
	}
}
#endif
