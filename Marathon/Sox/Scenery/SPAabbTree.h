#ifndef SONICTEAM__SOX__SPABBTREE
#define SONICTEAM__SOX__SPABBTREE

#include "Defs.h"
#include "SPWorld.h"


#include <xtl.h>
#include <Sox/RefCountObject.h>

namespace Sonicteam{
	namespace SoX{
		namespace Scenery{


			struct AABB{
			public:
				unsigned int unk0; //Placement ID???
				unsigned int unk4;  //Placament ID???

				AABB(){

				}

				AABB(unsigned int id0, unsigned int id4, 
					float min_x, float min_y, float min_z, 
					float max_x, float max_y, float max_z)
					: unk0(id0), unk4(id4), 
					minX(min_x), minY(min_y), minZ(min_z), 
					maxX(max_x), maxY(max_y), maxZ(max_z) {}


				float minX, minY, minZ; // seems all floats
				float maxX, maxY, maxZ; // seems all floats

				// Check if this AABB intersects with another AABB
				bool intersects(const AABB& other) const {
					return (minX <= other.maxX && maxX >= other.minX) &&
						(minY <= other.maxY && maxY >= other.minY) &&
						(minZ <= other.maxZ && maxZ >= other.minZ);
				}

			

			};

			//PropFile = v9->ScenePropFile;
			//  if ( *(_DWORD *)(PropFile + 0x2C) )
			// v13 = (float *)(*(_DWORD *)(PropFile + 0x30) + 0x24); 8245EB8C
			//next points to size + 0x10, as storing to std::vector<SPAabbNodeVector> in stack with size + 0x18



			//Get Extracted From PropFile
			struct SPAabbNodeVector{
				float minX, minY, minZ; // seems all floats
				float maxX, maxY, maxZ; // seems all floats

				SPAabbNodeVector(){

				}
				SPAabbNodeVector(unsigned int id0, unsigned int id4, 
					float min_x, float min_y, float min_z, 
					float max_x, float max_y, float max_z)
					:minX(min_x), minY(min_y), minZ(min_z), 
					maxX(max_x), maxY(max_y), maxZ(max_z) {}
			};

			class SPAabbTree:public Sonicteam::SoX::RefCountObject{
			public:
				SPAabbTree();
				~SPAabbTree();

				virtual void DestroyObject(unsigned int flag) override;


				//PropFileVectorData 
				virtual void SPAabbTreeInitialize(Sonicteam::SoX::Scenery::SPWorld* SPWorld,SPAabbNodeVector* VectorData,unsigned int count);
				virtual void SPAabbTreeTraverse() = 0; // 825B9890 finish later
 

				//my
				void initialize(int count);
				void insert(const AABB& box,unsigned int index);
				void add(const AABB& box);

				AABB* AABBObjects; //0x8, array
				int AABBCount; //0xC
			};



		}
	}
}
\
#endif