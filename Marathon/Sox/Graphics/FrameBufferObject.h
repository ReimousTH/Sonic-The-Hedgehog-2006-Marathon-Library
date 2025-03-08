#ifndef Sonicteam__SOX__Graphics__FRAMEBUFFEROBJECT
#define Sonicteam__SOX__Graphics__FRAMEBUFFEROBJECT

#include "Defs.h"
#include <Sox/IResource.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/Destruction.h>
#include <Sox/Graphics/Xenon/TextureXenon.h>



namespace Sonicteam{
	namespace SoX{
		namespace Graphics{
			class FrameBufferObject:public Sonicteam::SoX::RefCountObject{

				DESTRUCTION_H;

			};
		};
	};
};
#endif
