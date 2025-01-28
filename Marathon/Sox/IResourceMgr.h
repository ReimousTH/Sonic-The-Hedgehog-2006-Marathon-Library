#pragma once

namespace Sonicteam{
	namespace SoX{
		class IResourceMgr
		{
		public:
			IResourceMgr(void);
			virtual ~IResourceMgr(void);

			virtual void InitResource();
			
		};
	}
}
