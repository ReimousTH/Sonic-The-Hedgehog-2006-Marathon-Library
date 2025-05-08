#pragma once

#include <xtl.h>
#include <string>
#include <list>


#include <deque>

#include "Sox/Misc/List.h"
#include <SoX/Memory/IDestructible.h>

#include <System/Singleton.h>
#include <System/CreateStatic.h>


namespace Sonicteam {
	namespace SoX {
		class PerformanceFrequency:public SSINGLETON(PerformanceFrequency){
		public:

			PerformanceFrequency();
			~PerformanceFrequency();

			LARGE_INTEGER LastFrequency;
	
			static void QueryFrequency();
			static LARGE_INTEGER* QPerfomanceCounter(LARGE_INTEGER* counter);
			static void QPerfomanceCounterEx(LARGE_INTEGER* counter);
			static LARGE_INTEGER PerfomanceScale(LARGE_INTEGER* counter);
			static LARGE_INTEGER PerfomanceScaleEX(LARGE_INTEGER* counter);
			unsigned __int64 GetTimeBase();
			LARGE_INTEGER GetPerformanceFrequency();
	
		};
	};
};