#ifndef Sonicteam__SOX__FrameSynchronizer
#define Sonicteam__SOX__FrameSynchronizer


#include "Defs.h"
#include "../MessageReceiver.h"
#include <SoX/RefCountObject.h>
#include <xtl.h>
#include <Sox/Misc/List.h>
#include <Sox/Memory/IDestructible.h>
#include <Sox/Memory/DEFINITIONS.hpp>






namespace Sonicteam{
	namespace SoX{
		namespace Graphics{


	
			class FrameSynchronizer
			{

			public:
				FrameSynchronizer();
				FrameSynchronizer(unsigned int); //Frame Count
				~FrameSynchronizer(void);

				virtual void DestroyObject(unsigned int flag);

				Sonicteam::SoX::LinkNodeListA<Sonicteam::SoX::Graphics::Frame> LFrame;
				//	unsigned int FSuint0x4; //self
				//	unsigned int FSuint0x8; //self
				//	unsigned int FSuint0xC; 

				/*
				FrameSyncT01 FrameBuffer;
				unsigned int FSFrameBuffer01; //0x10
				unsigned int FSFrameBuffer02; //0x14
				unsigned int FSFrameCount; //0x18
				unsigned int FSuint0x1C; //
				*/


			};



		}

	}
}



#endif
