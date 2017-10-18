#pragma once

#include "stdafx.h"
#include "Object.h"

class Object;

class SceneMgr
{
public:
	static const int MAX_OBJECTS_COUNT = 50;
	Object *m_objects[MAX_OBJECTS_COUNT] = { 0 };


public:
	void ObjectAdd();
	void SceneUpdate();
};