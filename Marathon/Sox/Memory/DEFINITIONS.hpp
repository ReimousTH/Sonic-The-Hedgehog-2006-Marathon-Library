#ifndef _DEFINITONS_
#define _DEFINITONS_


static void Test(...){

}

#define _MARATHON_DEFINE_CONSTRUCTOR_(CLASS,ADDRESS, ...) \
	private:\
	static const unsigned int CONSTRUCTOR##ADDRESS = (unsigned int)ADDRESS; \
	public:\
	static CLASS* CreateMarathon(CLASS* _this, __VA_ARGS__) { \
	__asm { stmw r4, -0x50(r1)  } \
	int mem = (int)malloc(sizeof(CLASS)); \
	unsigned int R13 = CONSTRUCTOR##ADDRESS;\
	__asm { lmw r4, -0x50(r1)  } \
	__asm{mr r12,R13 }\
	__asm{mtctr r12 }\
	__asm{bctrl }\
	__asm{mr mem,r3 }\
	return (CLASS*)mem; \
	} \
	//R3 CONSTRUCTOR##ADDRESS



#endif
