#include "stdafx.h"
#include "Object.h"
#include "SceneMgr.h"
#include "Renderer.h"

#include <random>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;
default_random_engine dre;
uniform_int_distribution<> ui(-250 ,250);

void SceneMgr::ObjectAdd()
{
	unsigned int x = 0;
	unsigned int y = 0;
	srand((unsigned int)time(NULL));
	
	dre.seed(GetTickCount());

	x = (rand() % 250) + 1;
	y = (rand() % 250) + 1;
	
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		m_objects[i] = NULL;
		if (m_objects[i] == NULL)
		{
			// x, y, z, s, r, g, b, a
			m_objects[i] = new Object( ui(dre), ui(dre), 1, 5 , 1, 1, 1, 0);
			//cout << m_objects[i]->GetObjectXposition() << " - " << m_objects[i]->GetObjectYposition() << endl;
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
	srand(GetTickCount());
}

void SceneMgr::SceneUpdate()
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		m_objects[i]->Update();
	}
}

bool SceneMgr::CollisionTest()
{
	return 0;
}
