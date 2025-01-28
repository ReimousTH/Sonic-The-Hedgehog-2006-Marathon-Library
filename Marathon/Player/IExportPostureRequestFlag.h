#pragma once


#include <xtl.h>

namespace Sonicteam{


	namespace Player{
		class IExportPostureRequestFlag
		{
		public:
			IExportPostureRequestFlag(void);
			virtual ~IExportPostureRequestFlag(void);
			virtual DWORD IEPRFExportFlag(void) = 0;

		};

	}
}

