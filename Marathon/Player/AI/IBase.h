#pragma  once
#include <Sox/MessageReceiver.h>
#include <Sox/Memory/Destruction.h>


namespace Sonicteam{
	namespace Player{
		namespace AI{
			class IBase{

				IBase(void);
				DESTRUCTION_H;
				virtual void AIOnMessageRecieved(int UnkFlag,Sonicteam::SoX::MessageReceiver*) = 0;
				virtual void AIBaseFlagExport() = 0;

			};

		}

	}
}
