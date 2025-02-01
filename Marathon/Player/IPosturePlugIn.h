#ifndef SONIC__PLAYER__IPOSTUREPLUGIN
#define SONIC__PLAYER__IPOSTUREPLUGIN


#include <Sox/Memory/Destruction.h>
#include <Player/IPlugIn.h>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include <xtl.h>



namespace Sonicteam{
	namespace Player{

		class IPosturePlugIn
		{
		public:
			IPosturePlugIn(void);
			~IPosturePlugIn(void);

			DESTRUCTION_H;
			
			//Export
			virtual int PosturePlugGet01();
			virtual int PosturePlugGet02(unsigned int,XMVECTOR);
			virtual int GetPostureDirectionFlag();
			virtual int GetPostureCustomData();
			virtual int GetPostureDirectionFlag(XMVECTOR&); //out data

			//Process
			virtual void PosturePlugInProcess01(XMVECTOR&);
			virtual void PosturePlugInProcess02(); 
			virtual void PosturePlugInProcess03(XMVECTOR,XMMATRIX,XMVECTOR,XMVECTOR&); 
			virtual void PosturePlugInProcess04(XMVECTOR,XMVECTOR&); //out vector XMVECTOR&
			virtual void PosturePlugInProcess05(XMVECTOR, XMVECTOR&);

	

		};
	}
}

#endif