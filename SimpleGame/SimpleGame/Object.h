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


public:
	// �����ڸ� ���� �������� ��ǥ�� �� ������ �����ϵ��� ��.


	//Rect
	Object(float x, float y, float z, float s, float r, float g, float b, float a) {
		ObjectInitialize(x, y, z, s, r, g, b, a);
	}

	//�ʱ�ȭ
	void ObjectInitialize(float x, float y, float z, float s, float r, float g, float b, float a);

	//Get�Լ��� 
	float GetObjectXposition();
	float GetObjectYposition();
	float GetObjectZposition();

	float GetObjectSize();

	float GetObjectRed();
	float GetObjectGreen();
	float GetObjectBlue();
	float GetObjectAlpha();

	//�߰� �Լ���
	void Update();



	//�Ҹ���
	~Object() {};

};