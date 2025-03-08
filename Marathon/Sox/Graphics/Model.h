#ifndef Sonicteam__SOX__Graphics__MODEL
#define Sonicteam__SOX__Graphics__MODEL



#include "Defs.h"

#include <Sox/IResource.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/Graphics/InstanceModelCommon.h>


namespace Sonicteam{
	namespace SoX{
		namespace Graphics{


	
			//:)
			class Model:public Sonicteam::SoX::IResource //Need Aditional Methods, FullClearLink()
			{

			public:
				Model();
				~Model();

				DESTRUCTION_H override;

				virtual REF_TYPE(Sonicteam::SoX::RefCountObject) GetMotionHierarchy(); //Sonicteam::SoX::Graphics::AnimationHierarchyCommon
				virtual size_t GetMotionHierarchyCount1(); 
				virtual size_t GetMotionHierarchyCount2();
				virtual Sonicteam::SoX::Graphics::InstanceModelCommon* GetMotionHierarchyInstance1(); //i think (void* = 0xE0)
				virtual Sonicteam::SoX::Graphics::InstanceModelCommon* GetMotionHierarchyInstance2(); //i think (void* = 0xE0)



			};
		};
	}
}

#endif

