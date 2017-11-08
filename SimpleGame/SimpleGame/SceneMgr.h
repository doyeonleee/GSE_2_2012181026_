#pragma once

#include "stdafx.h"
#include "Object.h"
#include "Renderer.h"
#include "windows.h"

class Object;
class Renderer;

class SceneMgr
{
private:
	static const int MAX_OBJECTS_COUNT = 11;
	static const int MAX_BULLET_COUNT = 10;

	Object *m_objects[MAX_OBJECTS_COUNT];
	Object *m_Bullets[MAX_BULLET_COUNT];
	Renderer *m_renderer = NULL;

	int m_BuildingID;

public:
	SceneMgr(int width, int height) {
		m_renderer = new Renderer(width, height);
		if (!m_renderer->IsInitialized())
		{
			std::cout << "Renderer could not be initialized.. \n";
		}
	}

	void ObjectBulidingAdd();
	void SceneUpdate(float elapsedTime);
	void DrawObject();
	void DrawBullet(float elapsedTime);


	int AddPlusObject(float x, float y);
	void DeleteObject(int i);

	void CollisionTest();
	void BulletCollisionTest();
	bool BoxCollisionTest(float minX, float minY, float maxX, float maxY, float minX1, float minY1, float maxX1, float maxY1);

	~SceneMgr() {};
};