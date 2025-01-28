#pragma  once
#include <Sox/MessageReceiver.h>


namespace Sonicteam{
	namespace Player{
		namespace AI{
			class IBase{

				IBase(void);
				virtual ~IBase(void);
				virtual void AIOnMessageRecieved(int UnkFlag,Sonicteam::SoX::MessageReceiver*) = 0;
				virtual void AIBaseFlagExport() = 0;

			};

		}

	}
}
