#ifndef SONICTEAM__PLAYER__ITESTCASE
#define SONICTEAM__PLAYER__ITESTCASE

#include "Defs.h"
#include <Sox/Memory/Destruction.h>

namespace Sonicteam {
	namespace Player {
		namespace Unit {
			class ITestCase {
			public:  // Add public access specifier

				ITestCase();
				~ITestCase(); // Make the destructor virtual
				DESTRUCTION_HPP;
			};
		} // namespace Unit

	} // namespace Player
} // namespace Sonicteam

#endif
