#pragma once				

#ifndef _T1
#define _T1

#define DefineVirtualDestroyerH() virtual RefObjectDestroy(unsigned int flag)

#define DefineVirtualDestroyerCPP(ClassName) virtual RefObjectDestroy(unsigned int flag)\
	{\
	this->~#ClassName();\
		if ((flag & 1 ) != 0 ){\
	delete this;\
	}\


#endif
