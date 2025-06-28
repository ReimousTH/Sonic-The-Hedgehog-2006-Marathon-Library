#ifndef SONICTEAM__KHRONOCONTROLLINPUTLISTENER
#define SONICTEAM__KHRONOCONTROLLINPUTLISTENER


#include <Defs.h>
#include <boost/function.hpp>
#include <Sox/Input/Defs.h>
#include <Sox/Input/Listener.h>


#define KhronoControlInputListenerBFUNC boost::function<void(double)>

namespace Sonicteam{




	class KhronoControlInputListener:Sonicteam::SoX::Input::Listener{

	public:
		KhronoControlInputListener(KhronoControlInputListenerBFUNC);
		~KhronoControlInputListener();
		DESTRUCTION_H;
		virtual void UpdateListener(SOXLISTENER_ARGS);
		KhronoControlInputListenerBFUNC func0x18; //0x18

	};

};




#endif