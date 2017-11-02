#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;


class Object {

public:
	float ObjectXposition;
	float ObjectYposition;
	float ObjectZposition;

	float ObjectSize;

	float ObjectRed;
	float ObjectGreen;
	float ObjectBlue;
	float ObjectAlpha;

	float ObjectVolume;		//부피
	float ObjectWeight;		//무게

	float ObjectVectorX;
	float ObjectVectorY;

	float Objectlife;
	float ObjectlifeTime;

	ObjectType ObjType;

public:
	// 생성자를 통해 도형마다 좌표값 및 색상값을 설정하도록 함.


	//Rect
	Object(ObjectType type, float x, float y, float z, float s, float r, float g, float b, float a) {
		ObjectInitialize(type, x, y, z, s, r, g, b, a);
	}

	//초기화
	void ObjectInitialize(ObjectType type, float x, float y, float z, float s, float r, float g, float b, float a);

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

	ObjectType GetObjectType();
	
	//추가 함수부
	void Update(float elapsedTime);

	//소멸자
	~Object() {};

};