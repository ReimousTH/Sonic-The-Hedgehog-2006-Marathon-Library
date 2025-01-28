#include "Marathon.h"




DWORD _std_string_getpointer(int* str){
	
	DWORD* v7;
	if ( str[6] < 0x10u )
		v7 = (DWORD *)(str + 1);
	else
		v7 = (DWORD *)str[1];


	return (DWORD)v7;

}


DWORD* Marathon::NewObjectCopy(DWORD a1,DWORD a2){

	typedef DWORD func(DWORD,DWORD);
	func* f = (func*)0x821620E8 ;
	f(a1,a2);
	return (DWORD*)a1;
}

DWORD* Marathon::NewObjectCopy(DWORD a1,DWORD a2,DWORD a3){

	typedef DWORD func(DWORD,DWORD,DWORD);
	func* f = (func*)0x82161E08 ;
	f(a1,a2,a3);
	return (DWORD*)a1;
}
_DWORD *__fastcall Marathon::NewObject(NORT *a1,int a2, int a3)
{
	return ((_DWORD *(__fastcall *)(NORT*,int,int))0x821620E8)(a1,a2,a3);
}

_DWORD *__fastcall Marathon::NewObject(NORT *a1, int a2)
{
	return ((_DWORD *(__fastcall *)(NORT*,int))0x821620E8)(a1,a2);
}

const char Marathon::Player::IVarible::str[] = "c_%s_max";

const float Marathon::Player::State::ICommonContextIF::flt  = 0.94999999;
