#include "stdafx.h"
#include "Object.h"

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

	ObjectVectorX = 1;
	ObjectVectorY = 0;
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

	if (ObjectYposition < -250)
		ObjectVectorX = -ObjectVectorX;

}