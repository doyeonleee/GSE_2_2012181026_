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
	static const int MAX_OBJECTS_COUNT = 100;

	Object *m_objects[MAX_OBJECTS_COUNT];
	Object *m_Bullets[MAX_OBJECTS_COUNT];
	Renderer *m_renderer = NULL;

	int m_BuildingID;
	int m_CharacterID;
	int m_BulletID;

public:
	SceneMgr(int width, int height) {
		m_renderer = new Renderer(width, height);
		if (!m_renderer->IsInitialized())
		{
			std::cout << "Renderer could not be initialized.. \n";
		}
		for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
		{
			m_objects[i] = NULL;
			m_Bullets[i] = NULL;
		}
	}

	void SceneUpdate(float elapsedTime);
	void DrawObject();

	int AddObject(float x, float y, ObjectType type);
	void DeleteObject(int i);

	void CollisionTest();
	bool BoxCollisionTest(float minX, float minY, float maxX, float maxY, float minX1, float minY1, float maxX1, float maxY1);

	~SceneMgr() {};
};