#pragma once
#include <Sox/RefCountObject.h>
#include <Sox/Object.h>


template <typename T>
void ObjectDestroyBoostDeleter(T& obj, int flag) {
	if (obj) obj.ObjectDestroy(flag);
}


void SoxRefCountObjectBoostDeleter(Sonicteam::SoX::RefCountObject& obj) {
	if (obj) obj.RefObjectDestroy(1);
}



void SoxObjectBoostDeleter(Sonicteam::SoX::Object& obj) {
	if (obj) obj.DestroyObject(1);
}

