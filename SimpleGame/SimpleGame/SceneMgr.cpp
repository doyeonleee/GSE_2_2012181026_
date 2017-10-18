#include "stdafx.h"
#include "Object.h"
#include "SceneMgr.h"

#include <random>

using namespace std;
default_random_engine dre;
uniform_int_distribution<> ui(0, 80);


void SceneMgr::ObjectAdd()
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		m_objects[i] = NULL;
		if (m_objects[i] == NULL)
		{
			// x, y, z, s, r, g, b, a
			m_objects[i] = new Object(ui(dre), ui(dre), 1, 10, 1, 1, 1, 0);
			m_objects[i]->ObjectInitialize(
				m_objects[i]->GetObjectXposition(),
				m_objects[i]->GetObjectYposition(),
				m_objects[i]->GetObjectZposition(),
				m_objects[i]->GetObjectSize(),
				m_objects[i]->GetObjectRed(),
				m_objects[i]->GetObjectGreen(),
				m_objects[i]->GetObjectBlue(),
				m_objects[i]->GetObjectAlpha()
			);
		}
	}
}

void SceneMgr::SceneUpdate()
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		m_objects[i]->Update();
	}
}
