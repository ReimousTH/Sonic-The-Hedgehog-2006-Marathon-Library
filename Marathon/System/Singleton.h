#ifndef SONICTEAM__SYSTEM
#define SONICTEAM__SYSTEM


#define SSINGLETON(CLASS) SINGLETON(CLASS,Sonicteam::System::CreateStatic)
#define SINGLETON(CLASS,CREATOR) Sonicteam::System::Singleton<CLASS,CREATOR<CLASS>>


namespace Sonicteam{
	namespace System{

		template <typename T, typename Creator>
		class Singleton {
		private:
			Singleton() {
			}

			~Singleton() {
			}

			static T* m_instance;

		public:
	//		Singleton(const Singleton& obj) = delete;
	//		Singleton& operator=(const Singleton& obj) = delete;

			static T& getInstance() {
				if (m_instance == NULL) {
					m_instance = Creator::Create();
				}
				return *m_instance;
			}
			static T& getInstance(void* address) {
				m_instance = (T*)address;
				return *m_instance;
			}

			static void cleanup() {
				if (m_instance != nullptr) {
					delete m_instance;
					m_instance = nullptr;
				}
			}
		};
	

		template <typename T, typename Creator>
		T* Sonicteam::System::Singleton<T, Creator>::m_instance = nullptr;


	};
};
#endif