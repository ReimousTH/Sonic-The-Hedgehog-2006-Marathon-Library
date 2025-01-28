#pragma once	


#include <xtl.h>

#define alloc06(size) ((void* (__fastcall *)(size_t))0x82186158)(size)


#define CallTo(offset,rtype,...) \
	((rtype (__fastcall *)(...))offset)(__VA_ARGS__) \


#define FUNCTION_POINTER_CAST(RETURN_TYPE, NAME, ADDRESS, ...) \
	static RETURN_TYPE (__cdecl *const NAME)(__VA_ARGS__) = (RETURN_TYPE (__cdecl *)(__VA_ARGS__))ADDRESS






//Custom
namespace Sonicteam{
	namespace SoX{
		namespace Memory{







			

			class IUDestructible {
			public:
				~IUDestructible() {}
				template <typename T>
				inline static void DestroyObject(T& obj,unsigned int flag){
					if ((flag & 1) != 0) {
						free(obj);
					}
				}
				template <typename T>
				inline static void DestroyObjectEX(T& obj,unsigned int flag){
					&obj->~T();
					if ((flag & 1) != 0) {
						free(obj);
					}
				}
			};
			
			template <typename T>
			class BoostDestructorHelper {
			public:
				void operator()(T* obj) const {
					if (obj) obj->DestroyObject(1);

				}
			};

		



			static void boost_ptr_cleanup(IUDestructible* obj){
				//obj->DestroyObject(1);
			}



		}

	}
}







