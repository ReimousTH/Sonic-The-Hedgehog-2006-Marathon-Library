#ifndef SONICTEAM__CREATESTATIC
#define SONICTEAM__CREATESTATIC



namespace Sonicteam{
	namespace System{

		template <typename T>
		class CreateStatic {
		public:
			static T* Create() {	

				static T _value;
				return &_value;
			}
		};


	};
};
#endif