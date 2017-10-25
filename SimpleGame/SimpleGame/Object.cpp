#include "stdafx.h"
#include "Object.h"
//#include "SceneMgr.h"

#include <random>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

default_random_engine dre2;
uniform_int_distribution<> ui2(-1, 1);



void Object::ObjectInitialize(float x, float y, float z, float s, float r, float g, float b, float a)
{
	ObjectXposition = x;
	ObjectYposition = y;
	ObjectZposition = z;
	ObjectSize = s;
	ObjectRed = r;
	ObjectGreen = g;
	ObjectBlue = b;
	ObjectAlpha = a;

	srand((unsigned int)time(NULL));

	ObjectVectorX = ui2(dre2);
	ObjectVectorY = ui2(dre2);

	srand(GetTickCount());

};

float Object::GetObjectXposition() {
	return ObjectXposition;
}
float Object::GetObjectYposition() {
	return ObjectYposition;
};
float Object::GetObjectZposition() {
	return ObjectZposition;
};
float Object::GetObjectSize() {
	return ObjectSize;
};
float Object::GetObjectRed() {
	return ObjectRed;
};
float Object::GetObjectGreen() {
	return ObjectGreen;
};
float Object::GetObjectBlue() {
	return ObjectBlue;
};
float Object::GetObjectAlpha() {
	return ObjectAlpha;
};

void Object::Update() {

	float eTime = 0.1;
	ObjectXposition = ObjectXposition + (ObjectVectorX * eTime);
	ObjectYposition = ObjectYposition + (ObjectVectorY * eTime);

	if (ObjectXposition > 250)
		ObjectVectorX = -ObjectVectorX;

	if (ObjectXposition < -250)
		ObjectVectorX = -ObjectVectorX;

	if (ObjectYposition > 250)
		ObjectVectorY = -ObjectVectorY;

	if (ObjectYposition < -250)
		ObjectVectorY = -ObjectVectorY;

}