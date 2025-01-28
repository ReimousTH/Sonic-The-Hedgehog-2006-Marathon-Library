#pragma once



namespace Sonicteam{
	namespace Player{

		class IStepable
		{
		public:
			IStepable(void);
			virtual ~IStepable(void);
			virtual void OnStepable(float) = 0;

		};

	}
}


