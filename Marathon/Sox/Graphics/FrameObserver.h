#ifndef Sonicteam__SOX__FrameObserver
#define Sonicteam__SOX__FrameObserver

#include "../MessageReceiver.h"
#include <SoX/RefCountObject.h>
#include <xtl.h>
#include <Sox/Misc/List.h>
#include <Sox/Memory/IDestructible.h>
#include <Sox/Memory/DEFINITIONS.hpp>

#include <Sox/Memory/Destruction.h>
#include <Sox/Misc/LinkSoxNode.h>
#include "Defs.h"


#define FrameObserverStepType void*



namespace Sonicteam{
	namespace SoX{
		namespace Graphics{


			/////////////////FrameObserver//////////////
			class FrameObserver
			{

			public:
				FrameObserver();
				~FrameObserver(void);

				virtual void ObserveFrameStep(FrameObserverStepType) = 0;

				DESTRUCTION_H;


				LinkSoxNode<FrameObserver> LinkNode;
				unsigned int FrameObserverFlag;
	

				void OnRNodeHClear(); //


			};



		}

	}
}

#endif