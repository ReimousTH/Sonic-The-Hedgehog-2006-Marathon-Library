#ifndef SONICTEAM__PLAYER__ISTEPABLE
#define SONICTEAM__PLAYER__ISTEPABLE

#include <Sox/Memory/Destruction.h>

namespace Sonicteam{
	namespace Player{

		class IStepable
		{
		public:
			IStepable(void);
			~IStepable(void);


			DESTRUCTION_H;
			virtual void OnStepable(float) = 0;

		};

	}
}

#endif
