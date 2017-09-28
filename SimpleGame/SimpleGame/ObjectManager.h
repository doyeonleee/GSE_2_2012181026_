#pragma once

#include <iostream>

using namespace std;

class ObjectManager {
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


public:
	// �����ڸ� ���� �������� ��ǥ�� �� ������ �����ϵ��� ��.


	//Rect
	ObjectManager(float x, float y, float z, float s, float r, float g, float b, float a) {
		ObjectXposition = x;
		ObjectYposition = y;
		ObjectZposition = z;
		ObjectSize = s;
		ObjectRed = r;
		ObjectGreen = g;
		ObjectBlue = b;
		ObjectAlpha = a;
	}

	//�ʱ�ȭ?
	/*void ObjectRectInitialize(float x, float y, float z, float s, float r, float g, float b, float a)
	//{
	//	ObjectXposition = x;
	//	ObjectYposition = y;
	//	ObjectZposition = z;
	//	ObjectSize = s;
	//	ObjectRed = r;
	//	ObjectGreen = g;
	//	ObjectBlue = b;
	//	ObjectAlpha = a;
	};*/


	//Get�Լ��� 
	float GetObjectXposition();
	float GetObjectYposition();
	float GetObjectZposition();

	float GetObjectSize();

	float GetObjectRed();
	float GetObjectGreen();
	float GetObjectBlue();
	float GetObjectAlpha();


	//�Ҹ���
	~ObjectManager() {};

};