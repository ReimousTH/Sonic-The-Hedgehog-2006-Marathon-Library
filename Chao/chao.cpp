#include <chao.h>
#define VOID_FILE

#ifndef VOID_FILE

//testing only
void main(){

	void* ptr = CMAlloc(4,"",0);
	CMFree(ptr);

	Chao::CSD::CPlatform* platform;


	platform->DestroyObject(1);

	platform->DebugMessageA("f");


	



}


#endif



