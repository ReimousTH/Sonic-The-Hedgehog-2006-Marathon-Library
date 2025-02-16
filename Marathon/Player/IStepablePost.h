#ifndef SONICTEAM__PLAYER__ISTEPABLEPOST
#define SONICTEAM__PLAYER__ISTEPABLEPOST




namespace Sonicteam{
	namespace Player{

		class IStepablePost
		{
		public:
			IStepablePost(void);
			~IStepablePost(void);


			DESTRUCTION_H;
			virtual void OnStepablePost(float) = 0;

		};

	}
}


#endif