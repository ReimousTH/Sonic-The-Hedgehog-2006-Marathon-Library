#pragma once
#include <string>
#include <Sox/Memory/IDestructible.h>



namespace Sonicteam{

	namespace Player{

		class IPlugIn
		{
		public:
			IPlugIn(char*);
			~IPlugIn(void);

			DESTRUCTION_H;

			std::string PluginName;

		};
	};
};

