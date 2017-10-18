#include "stdafx.h"
#include "Object.h"

float Object::GetObjectXposition() {
	return ObjectXposition;
};
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
	
	//float UpdatedXposition = 0;
	//float UpdatedYposition = 0;

	//float SpeedVector;
	//float time;

	//SpeedVector = 0.1;
	//time = 1;

	//UpdatedXposition = ObjectXposition + (SpeedVector * time);
	//UpdatedYposition = ObjectYposition + (SpeedVector * time);

	//ObjectXposition = UpdatedXposition;
	//ObjectYposition = UpdatedYposition;

	float eTime = 0.1;
	ObjectXposition = ObjectXposition + (ObjectVectorX * eTime);
	ObjectYposition = ObjectYposition + (ObjectVectorY * eTime);

	if (ObjectXposition > 250)
		ObjectVectorX = -ObjectVectorX;

	if (ObjectYposition < -250)
		ObjectVectorX = -ObjectVectorX;

}