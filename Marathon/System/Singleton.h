#ifndef SONICTEAM__SYSTEM
#define SONICTEAM__SYSTEM


#define SSINGLETON(CLASS) SINGLETON(CLASS,Sonicteam::System::CreateStatic)
#define SSINGLETON_INSTANCE(CLASS) (&(SINGLETON(CLASS,Sonicteam::System::CreateStatic)::getInstance()))
#define SINGLETON(CLASS,CREATOR) Sonicteam::System::Singleton<CLASS,CREATOR<CLASS>>



namespace Sonicteam{
	namespace System{

		template <typename T, typename Creator>
		class Singleton {
			public:

			Singleton() {
			}

			~Singleton() {
			}
			private:
			static T* m_instance;

		public:
	//		Singleton(const Singleton& obj) = delete;
	//		Singleton& operator=(const Singleton& obj) = delete;

			static T& getInstance() {
				if (m_instance == 0) {
					m_instance = Creator::Create();
				}
				return *m_instance;
			}
			static T& getInstance(void* address) {
				m_instance = (T*)address;
				return *m_instance;
			}
			//singleton address,Create Function
			//saddress:82D3B264,CreatorFunction: 82581F00
			static T& getInstance(void** saddress,void* CreatorFunction) {
				if (*saddress == 0){
					*saddress = ((T* (*)())CreatorFunction)();
				}

				if (!m_instance) m_instance = (T*)*saddress;
				return *m_instance;
			}
			static T& getInstanceQuick()
			{
				return *m_instance;
			}
		

			static void cleanup() {
				if (m_instance != 0) {
					delete m_instance;
					m_instance = 0;
				}
			}
		};
	

		template <typename T, typename Creator>
		T* Sonicteam::System::Singleton<T, Creator>::m_instance = 0;


	};
};
#endif