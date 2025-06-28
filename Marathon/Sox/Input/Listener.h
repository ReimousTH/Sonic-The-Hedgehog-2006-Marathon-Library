#ifndef __Sonicteam__SOX__INPUT__LISTENER__
#define  __Sonicteam__SOX__INPUT__LISTENER__



#include <Sox/Object.h>
#include <Sox/Input/Defs.h>
#include <Sox/Misc/LinkSoxNode.h>


#define SOXLISTENER_ARG_1 double
#define SOXLISTENER_ARG_2 Sonicteam::SoX::Input::Manager*
#define SOXLISTENER_ARGSC SOXLISTENER_ARG_2 mgr,SOXLISTENER_ARG_1 delta
#define SOXLISTENER_ARGS SOXLISTENER_ARG_2,SOXLISTENER_ARG_1






namespace Sonicteam{
	namespace SoX{
		namespace Input{






			class Listener:Sonicteam::SoX::Object
			{
			public:
				//size0x60
				Listener(void);
				~Listener(void);
				DESTRUCTION_H;
				virtual void UpdateListener(SOXLISTENER_ARGS) = 0;
				//4
				LinkSoxNode<Listener> LinkInput; //4,8,C
				char flag0x10;
				char flag0x11;
				char flag0x12;
				char flag0x13;
				size_t unk0x14; //0x14


			};

		};

	};
};
#endif