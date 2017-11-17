#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;


class Object {

private:
	float ObjectXposition;
	float ObjectYposition;
	float ObjectZposition;

	float ObjectSize;

	float ObjectRed;
	float ObjectGreen;
	float ObjectBlue;
	float ObjectAlpha;

	float ObjectVectorX;
	float ObjectVectorY;

	float Objectlife;
	float ObjectlifeTime;

	ObjectType ObjType;

public:
	
	Object(ObjectType type, float x, float y);


	//Get함수부 
	float GetObjectXposition();
	float GetObjectYposition();
	float GetObjectZposition();

	float GetObjectSize();

	float GetObjectRed();
	float GetObjectGreen();
	float GetObjectBlue();
	float GetObjectAlpha();

	float GetObjectLife();
	float GetObjectLifeTime();

	void GetDamage(float dmg);
	void SetObjLife(float life);

	void ChangeObjectColor(float r, float g, float b, float a);
	void ChangeObjectPosition(float x, float y, float z);

	ObjectType GetObjectType();
	
	//추가 함수부
	void Update(float elapsedTime);

	//소멸자
	~Object()
	{
		if (ObjType == OBJECT_CHARACTER)
		{
			cout << "error" << endl;
		}
	};

	float ObjectLastBullet;
	float ObjectLastArrow;
	int ParentID;

};