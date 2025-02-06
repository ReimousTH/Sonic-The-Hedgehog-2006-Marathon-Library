#pragma once	


#include <xtl.h>
#include "Destruction.h"

#define alloc06(size) ((void* (__fastcall *)(size_t))0x82186158)(size)


#define CallTo(offset,rtype,...) \
	((rtype (__fastcall *)(...))offset)(__VA_ARGS__) \


#define FUNCTION_POINTER_CAST(RETURN_TYPE, NAME, ADDRESS, ...) \
	static RETURN_TYPE (__cdecl *const NAME)(__VA_ARGS__) = (RETURN_TYPE (__cdecl *)(__VA_ARGS__))ADDRESS








