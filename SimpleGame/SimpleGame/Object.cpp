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

default_random_engine dre4;
uniform_int_distribution<> ui4(-600, 600);


Object::Object(ObjectType type, float x, float y)
{
	ObjectXposition = x;
	ObjectYposition = y;
	ObjType = type;
	srand((unsigned int)time(NULL));

	ObjectLastBullet = 0.f;
	ObjectLastArrow = 0.f;
	ParentID = -1;
	
	if (ObjType == OBJECT_BUILDING)
	{
		ChangeObjectColor(1, 0, 0, 1);
		Objectlife = 500.f;
		ObjectVectorX = 0;
		ObjectVectorY = 0;
		ObjectSize = 100;
		Objectlife = 500;
		ObjectlifeTime = 100000.f;
		ObjectLevel = 0.1f;
	}

	else if (ObjType == OBJECT_CHARACTER)
	{
		ChangeObjectColor(0, 0, 1, 1);
		ObjectSize = 30;
		Objectlife = 100;
		ObjectlifeTime = 1000000.f;
		ObjectVectorX = float(ui2(dre2));
		ObjectVectorY = float(ui2(dre2));
		ObjectLevel = 0.2f;
	}

	else if (ObjType == OBJECT_BULLET)
	{
		ChangeObjectColor(1, 0, 0, 1);
		Objectlife = 200;
		ObjectlifeTime = 1000000.f;
		ObjectSize = 2;
		ObjectVectorX = float(ui3(dre3));
		ObjectVectorY = float(ui3(dre3));
		ObjectLevel = 0.3f;
	}

	else if (ObjType == OBJECT_ARROW)
	{
		ChangeObjectColor(0, 0, 1, 1);
		Objectlife = 100;
		ObjectlifeTime = 100000.f;
		ObjectSize = 2;
		ObjectVectorX = float(ui4(dre4));
		ObjectVectorY = float(ui4(dre4));
		ObjectLevel = 0.3f;
	}

	//����(ĳ���ͳ� ���� ��..)���� �ٲ��ָ� �ȴ�.

	srand(GetTickCount());

}

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

void Object::GetDamage(float dmg)
{
	Objectlife -= dmg;
}

void Object::SetObjLife(float life)
{
	Objectlife = life;
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

float Object::GetObjectLevel()
{
	return ObjectLevel;
}


void Object::Update(float elapsedTime) {

	float eTime = elapsedTime / 1000.f;
	ObjectLastBullet += eTime;
	ObjectLastArrow += eTime;

	ObjectXposition = ObjectXposition + (ObjectVectorX * eTime);
	ObjectYposition = ObjectYposition + (ObjectVectorY * eTime);

	if (ObjectXposition > 250) {
		if (ObjType == OBJECT_BULLET || ObjType == OBJECT_ARROW )
		{
			Objectlife = 0.f;
		}
		ObjectVectorX = -ObjectVectorX;
	}

	if (ObjectXposition < -250) {
		if (ObjType == OBJECT_BULLET || ObjType == OBJECT_ARROW)
		{
			Objectlife = 0.f;
		}
		ObjectVectorX = -ObjectVectorX;
	}

	if (ObjectYposition > 500) {
		if (ObjType == OBJECT_BULLET || ObjType == OBJECT_ARROW)
		{
			Objectlife = 0.f;
		}
		ObjectVectorY = -ObjectVectorY;
	}

	if (ObjectYposition < -500) {
		if (ObjType == OBJECT_BULLET || ObjType == OBJECT_ARROW)
		{
			Objectlife = 0.f;
		}
		ObjectVectorY = -ObjectVectorY;
	}

	if (Objectlife > 0.f)
	{
		if (ObjType != OBJECT_BUILDING) {
			//Objectlife -= 0.5f;
		}
	}

	if (ObjectlifeTime > 0.f)
	{
		//ObjectlifeTime -= eTime;
	}
}