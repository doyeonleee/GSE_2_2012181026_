#include "stdafx.h"
#include "Object.h"
#include "SceneMgr.h"

using namespace std;

void SceneMgr::ObjectAdd()
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		m_objects[i] = NULL;
		if (m_objects[i] == NULL)
		{
			m_objects[i] = new Object(0, 0, 0, 4, 1, 0, 1, 1);
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
