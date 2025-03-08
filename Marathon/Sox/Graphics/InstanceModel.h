#ifndef Sonicteam__SOX__Graphics__INSTANCEMODEL
#define Sonicteam__SOX__Graphics__INSTANCEMODEL



#include "Defs.h"
#include <Sox/IResource.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/Scenery/CameraEventCallback.h>
#include <Sox/Graphics/SamplerCommon.h>
#include <boost/shared_ptr.hpp>
#include <Sox/Graphics/FrameObserver.h>
#include <Sox/Graphics/Node.h>


namespace Sonicteam{
	namespace SoX{
		namespace Graphics{


	
			//:)
			class InstanceModel:public Sonicteam::SoX::RefCountObject,public Sonicteam::SoX::Scenery::CameraEventCallback//Need Aditional Methods, FullClearLink()
			{

				public:
				class frameObserver:public Sonicteam::SoX::Graphics::FrameObserver{
				public:
					frameObserver();
					~frameObserver();
					virtual void ObserveFrameStep(FrameObserverStepType) override;
					Sonicteam::SoX::Graphics::InstanceModel* FInstanceModel;
					DESTRUCTION_HPP;
				};


		
				InstanceModel();
				~InstanceModel();
				DESTRUCTION_H;
				//..

				frameObserver observer;
				REF_TYPE(Sonicteam::SoX::Graphics::Node) GNode; //0x24
				char empty_data[0x2C];
				char IMFlag1; //should pad to 4
				unsigned int unk0x54;
				unsigned int unk0x58;
				unsigned int unk0x5C;
	

		
			};
		};
	};
};

#endif

