#include "stdafx.h"
#include "Object.h"
#include "SceneMgr.h"

#include <random>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <math.h>

default_random_engine dre2;
uniform_int_distribution<> ui2(-100, 100);

void Object::ObjectInitialize(ObjectType type, float x, float y, float z, float s, float r, float g, float b, float a)
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

	//ObjectVectorX = float(100 * ui2(dre2));
	//ObjectVectorY = float(100 * ui2(dre2));

	ObjType = type;

	if (ObjType == OBJECT_BUILDING)
	{
		Objectlife = 500.f;
		ObjectVectorX = 0;
		ObjectVectorY = 0;
	}

	if (ObjType == OBJECT_CHARACTER)
	{
		Objectlife = 100.f;
		ObjectVectorX = float(ui2(dre2));
		ObjectVectorY = float(ui2(dre2));
	}

	//랜덤(캐릭터나 빌딩 등..)으로 바꿔주면 된다.
	ObjectlifeTime = 1000000000000000000000000000.f;

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
}
float Object::GetObjectLife()
{
	return Objectlife;
}
float Object::GetObjectLifeTime()
{
	return ObjectlifeTime;
}

ObjectType Object::GetObjectType()
{
	return ObjType;
}


void Object::Update(float elapsedTime) {

	float eTime = elapsedTime / 1000.f;
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

	if (Objectlife > 0.f)
	{
		//Objectlife -= 0.5f;
	}

	if (ObjectlifeTime > 0.f)
	{
		//ObjectlifeTime -= eTime;
	}

}