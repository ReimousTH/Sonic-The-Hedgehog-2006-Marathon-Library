#ifndef SONICTEAM__PLAYER__IEVENTERLISTENER
#define SONICTEAM__PLAYER__IEVENTERLISTENER


namespace Sonicteam{
	namespace Player{
		class IEventerListener
		{
		public:
			IEventerListener(void);
			~IEventerListener(void);

			virtual void DestroyObject(unsigned int Flag);

			virtual void IEventerListener01();
			virtual void IEventerListener02(unsigned int flag);
			virtual void IEventerListener03();
			virtual void IEventerListener04();
			virtual void IEventerListener05();
			virtual void IEventerListener06();
			virtual void IEventerListener07(void*,unsigned int);
			virtual void IEventerListener08();
			virtual void IEventerListener09(unsigned int, unsigned int); //AnimationID, AnimationState
			virtual void IEventerListener0A();
			virtual void IEventerListener0B();
			virtual void IEventerListener0C(unsigned int);
			virtual void IEventerListener0D();
			virtual void IEventerListener0E();
			virtual void IEventerListener0F();
			virtual void IEventerListener10(void*);
			virtual void IEventerListener11(unsigned int, unsigned int);
			virtual void IEventerListener12(void*,void*,unsigned int);



		};
	}
}




#endif


