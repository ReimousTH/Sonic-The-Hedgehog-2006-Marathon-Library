#pragma once


#include <xtl.h>
#include <Sox/Memory/IDestructible.h>

namespace Sonicteam{


	namespace Player{
		class IExportExternalFlag
		{
		public:
			IExportExternalFlag(void);
			~IExportExternalFlag(void);
			DESTRUCTION_H;
			virtual unsigned long long ExportExternalFlag(void) = 0;
		

		};

	}
}

