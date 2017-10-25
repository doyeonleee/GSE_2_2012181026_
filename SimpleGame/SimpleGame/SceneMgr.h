#pragma once

#include "stdafx.h"
#include "Object.h"
#include "Renderer.h"

class Object;
class Renderer;

class SceneMgr
{
public:
	static const int MAX_OBJECTS_COUNT = 50;
	Object *m_objects[MAX_OBJECTS_COUNT] = { 0 };
	Renderer *m_renderer = NULL;


public:
	SceneMgr(int width, int height) {
		m_renderer = new Renderer(width, height);
		if (!m_renderer->IsInitialized())
		{
			std::cout << "Renderer could not be initialized.. \n";
		}
	}

	void ObjectAdd();
	void SceneUpdate();

	bool CollisionTest();
};