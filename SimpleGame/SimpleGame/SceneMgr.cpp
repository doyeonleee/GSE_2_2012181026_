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

#define OBJECT_BUILDING 0

void SceneMgr::ObjectFirstAdd()
{
	unsigned int x = 0;
	unsigned int y = 0;
	srand((unsigned int)time(NULL));
	
	dre.seed(GetTickCount());

	x = (rand() % 250) + 1;
	y = (rand() % 250) + 1;
	
	//OBJECT_BUILDING
	m_objects[OBJECT_BUILDING] = new Object(0, 0, 0, 50, 1, 1, 1, 0);
	m_objects[OBJECT_BUILDING]->ObjectInitialize(
		m_objects[OBJECT_BUILDING]->GetObjectXposition(),
		m_objects[OBJECT_BUILDING]->GetObjectYposition(),
		m_objects[OBJECT_BUILDING]->GetObjectZposition(),
		m_objects[OBJECT_BUILDING]->GetObjectSize(),
		m_objects[OBJECT_BUILDING]->GetObjectRed(),
		m_objects[OBJECT_BUILDING]->GetObjectGreen(),
		m_objects[OBJECT_BUILDING]->GetObjectBlue(),
		m_objects[OBJECT_BUILDING]->GetObjectAlpha()
	);
	m_objects[OBJECT_BUILDING]->ObjectVectorX = 0;
	m_objects[OBJECT_BUILDING]->ObjectVectorY = 0;


	for (int i = 1; i < MAX_OBJECTS_COUNT; ++i)
	{
		m_objects[i] = NULL;
		if (m_objects[i] == NULL)
		{
			// x, y, z, s, r, g, b, a
			m_objects[i] = new Object( ui(dre), ui(dre), 1, 7 , 1, 1, 1, 0);
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

void SceneMgr::SceneUpdate(float elapsedTime)
{
	CollisionTest();

	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		if (m_objects[i] != NULL)
		{
			m_objects[i]->Update((float)elapsedTime);
			
			if (m_objects[i]->GetObjectLife() < 0.0001f || m_objects[i]->GetObjectLifeTime() < 0.0001f)
			{
				delete m_objects[i];
				m_objects[i] = NULL;
			}
			else
			{
				m_objects[i]->Update((float)elapsedTime);
			}
		}
	}
}

int SceneMgr::AddPlusObject(float x, float y)
{
	//Find empty slot
	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		if (m_objects[i] == NULL)
		{
			m_objects[i] = new Object(x, y, 1, 7, 1, 1, 1, 0);
			return i;
		}
	}

	//slots are full
	std::cout << "slots are full \n";
	return -1;
}


void SceneMgr::DeleteObject(int i)
{
	if (m_objects[i] != NULL)
	{
		delete m_objects[i];
		m_objects[i] = NULL;
	}
}

void SceneMgr::CollisionTest()
{
	int collisionCount = 0;

	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		collisionCount = 0;
		if (m_objects[i] != NULL)
		{
			for (int j = 0; j < MAX_OBJECTS_COUNT; j++)
			{
				if (i == j)
					continue;

				if (m_objects[i] != NULL)
				{
					float minX, minY;
					float maxX, maxY;

					float minX1, minY1;
					float maxX1, maxY1;

					minX = m_objects[i]->ObjectXposition - m_objects[i]->ObjectSize / 2.f;
					minY = m_objects[i]->ObjectYposition - m_objects[i]->ObjectSize / 2.f;
					maxX = m_objects[i]->ObjectXposition + m_objects[i]->ObjectSize / 2.f;
					maxY = m_objects[i]->ObjectYposition + m_objects[i]->ObjectSize / 2.f;
					minX1 = m_objects[j]->ObjectXposition - m_objects[j]->ObjectSize / 2.f;
					minY1 = m_objects[j]->ObjectYposition - m_objects[j]->ObjectSize / 2.f;
					maxX1 = m_objects[j]->ObjectXposition + m_objects[j]->ObjectSize / 2.f;
					maxY1 = m_objects[j]->ObjectYposition + m_objects[j]->ObjectSize / 2.f;
					if (BoxCollisionTest(minX, minY, maxX, maxY, minX1, minY1, maxX1, maxY1))
					{
						collisionCount++;
					}
				}
			}
			if (collisionCount > 0)
			{
				m_objects[i]->ObjectRed = 1;
				m_objects[i]->ObjectGreen = 0;
				m_objects[i]->ObjectBlue = 0;
				m_objects[i]->ObjectAlpha = 1;
			}
			else
			{
				m_objects[i]->ObjectRed = 1;
				m_objects[i]->ObjectGreen = 1;
				m_objects[i]->ObjectBlue = 1;
				m_objects[i]->ObjectAlpha = 1;
			}
		}
	}
}

bool SceneMgr::BoxCollisionTest(float minX, float minY, float maxX, float maxY, float minX1, float minY1, float maxX1, float maxY1)
{
	if (minX > maxX1)
		return false;
	if (maxX < minX1)
		return false;

	if (minY > maxY1)
		return false;
	if (maxY < minY1)
		return false;

	return true;
}