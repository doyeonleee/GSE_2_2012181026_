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

default_random_engine dre3;
uniform_int_distribution<> ui3(-300, 300);

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
		//ChangeObjectColor(3, 0, 3, 1);
		Objectlife = 500.f;
		ObjectVectorX = 0;
		ObjectVectorY = 0;
	}

	if (ObjType == OBJECT_CHARACTER)
	{
		Objectlife = 10.f;
		ObjectVectorX = float(ui2(dre2));
		ObjectVectorY = float(ui2(dre2));
	}

	if (ObjType == OBJECT_BULLET)
	{
		Objectlife = 10.f;
		ObjectVectorX = float(ui3(dre3));
		ObjectVectorY = float(ui3(dre3));
	}

	//랜덤(캐릭터나 빌딩 등..)으로 바꿔주면 된다.
	ObjectlifeTime = 1000.f;

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

float Object::GetBulletDelay()
{
	return BulletDelay;
}

void Object::SetObjectLife(float life)
{
	Objectlife = life;
}

void Object::SetBulletDelay(float time)
{
	BulletDelay = time;
}

void Object::ChangeObjectColor(float r, float g, float b, float a)
{
	ObjectRed = r;
	ObjectGreen = g;
	ObjectBlue = b;
	ObjectAlpha = a;
}

void Object::ChangeObjectPosition(float x, float y, float z)
{
	ObjectXposition = x;
	ObjectYposition = y;
	ObjectZposition = z;
}

ObjectType Object::GetObjectType()
{
	return ObjType;
}


void Object::Update(float elapsedTime) {

	float eTime = elapsedTime / 1000.f;
	BulletDelay += eTime;

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
		Objectlife -= 0.5f;
	}

	if (ObjectlifeTime > 0.f)
	{
		ObjectlifeTime -= eTime;
	}

}