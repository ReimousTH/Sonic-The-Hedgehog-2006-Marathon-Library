#ifndef Sonicteam__SOX__FrameObserver
#define Sonicteam__SOX__FrameObserver

#include "../MessageReceiver.h"
#include <SoX/RefCountObject.h>
#include <xtl.h>
#include <Sox/Misc/List.h>
#include <Sox/Memory/IDestructible.h>
#include <Sox/Memory/DEFINITIONS.hpp>
#include "Defs.h"





namespace Sonicteam{
	namespace SoX{
		namespace Graphics{


			/////////////////FrameObserver//////////////
			class FrameObserver
			{

			public:
				FrameObserver();
				~FrameObserver(void);

				virtual void ObserveFrameStep(double a1) = 0;
				virtual void DestroyObject(unsigned int flag);


				Sonicteam::SoX::LinkNode<FrameObserver> RNodeH;
				unsigned int UFOFlag0x10;
	

				void OnRNodeHClear(); //


			};



		}

	}
}

#endif