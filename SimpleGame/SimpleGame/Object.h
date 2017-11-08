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

	float ObjectVolume;		//����
	float ObjectWeight;		//����

	float ObjectVectorX;
	float ObjectVectorY;

	float Objectlife;
	float ObjectlifeTime;

	float BulletDelay = 0;


	ObjectType ObjType;

public:
	// �����ڸ� ���� �������� ��ǥ�� �� ������ �����ϵ��� ��.


	//Rect
	Object(ObjectType type, float x, float y, float z, float s, float r, float g, float b, float a) {
		ObjectInitialize(type, x, y, z, s, r, g, b, a);
	}

	//�ʱ�ȭ
	void ObjectInitialize(ObjectType type, float x, float y, float z, float s, float r, float g, float b, float a);

	//Get�Լ��� 
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

	float GetBulletDelay();

	void SetObjectLife(float life);
	void SetBulletDelay(float time);

	void ChangeObjectColor(float r, float g, float b, float a);
	void ChangeObjectPosition(float x, float y, float z);

	ObjectType GetObjectType();
	
	//�߰� �Լ���
	void Update(float elapsedTime);

	//�Ҹ���
	~Object() {};

};