#pragma once

#include <sox/Memory/IDestructible.h>
namespace Sonicteam{
	namespace Player{
		class INotification
		{
		public:
			INotification(void);

			 ~INotification(void);

			virtual void DestroyObject();
			//for now
			virtual void OnNotificationSend(unsigned int) {};
			virtual void OnNotificationReceived(unsigned int) {};
		};
	}
}

