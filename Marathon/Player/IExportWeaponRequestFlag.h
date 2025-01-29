#pragma once

#include <xtl.h>

namespace Sonicteam {
	namespace Player{
		class IExportWeaponRequestFlag
		{
		public:
			IExportWeaponRequestFlag(void);
			~IExportWeaponRequestFlag(void);
			virtual DWORD IEWRFExportFlag(void)  = 0;
		};

	}
}

