#include "stdafx.h"
#include "Object.h"
#include "SceneMgr.h"
#include "Renderer.h"
#include "LoadPng.h"

#include <random>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;
default_random_engine dre;
uniform_int_distribution<> ui(-250 ,250);

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
				//시간 경과후 오브젝트 삭제
				delete m_objects[i];
				m_objects[i] = NULL;
			}

			// 총알 발사
			else if (m_objects[i]->GetObjectType() == OBJECT_BUILDING)
			{
				if (m_objects[i]->ObjectLastBullet > 1.0f)
				{
					int bulletID = AddObject(
						m_objects[i]->GetObjectXposition(),
						m_objects[i]->GetObjectYposition(),
						OBJECT_BULLET);
					m_objects[i]->ObjectLastBullet = 0.f;
					if (bulletID >= 0)
					{
					m_objects[bulletID]->ParentID = i;
					}
				}
				m_objects[i]->Update((float)elapsedTime);
			}
			else if (m_objects[i]->GetObjectType() == OBJECT_CHARACTER)
			{
				m_objects[i]->Update((float)elapsedTime);
				if (m_objects[i]->ObjectLastArrow > 0.5f)
				{
					int arrowID = AddObject(
						m_objects[i]->GetObjectXposition(),
						m_objects[i]->GetObjectYposition(),
						OBJECT_ARROW);
					m_objects[i]->ObjectLastArrow = 0.f;
					if (arrowID >= 0)
					{
					m_objects[arrowID]->ParentID = i;
					}
				}
			}
			else
				m_objects[i]->Update((float)elapsedTime);
		}
		if (m_Bullets[i] != NULL)
		{
			m_Bullets[i]->Update(elapsedTime);
		}
		if (m_Arrows[i] != NULL)
		{
			m_Arrows[i]->Update(elapsedTime);
		}
	}
}


void SceneMgr::DrawObject()
{
	//m_renderer->DrawSolidRect(0, 0, 0, 500, 0, 0, 0, 0.4f);

	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i) {
		if (m_objects[i] != NULL) {
			if (m_objects[i]->GetObjectType() == OBJECT_BUILDING)
			{
				m_BuildingID = m_renderer->CreatePngTexture("./Resourse/Building.png");
				m_renderer->DrawTexturedRect(
					m_objects[OBJECT_BUILDING]->GetObjectXposition(),
					m_objects[OBJECT_BUILDING]->GetObjectYposition(),
					m_objects[OBJECT_BUILDING]->GetObjectZposition(),
					m_objects[OBJECT_BUILDING]->GetObjectSize(),
					m_objects[OBJECT_BUILDING]->GetObjectRed(),
					m_objects[OBJECT_BUILDING]->GetObjectGreen(),
					m_objects[OBJECT_BUILDING]->GetObjectBlue(),
					m_objects[OBJECT_BUILDING]->GetObjectAlpha(),
					m_BuildingID
				);
			}
			else {
				m_renderer->DrawSolidRect(
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
}


//Add Object
int SceneMgr::AddObject(float x, float y, ObjectType type)
{
	//Find empty slot
	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		if (m_objects[i] == NULL)
		{
			m_objects[i] = new Object(type, x, y);
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
	int ObjectCollisionCount = 0;

	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		ObjectCollisionCount = 0;
		if (m_objects[i] != NULL)
		{
			for (int j = i+1; j < MAX_OBJECTS_COUNT; j++)
			{
				if (m_objects[i] != NULL && m_objects[j] != NULL)
				{
					float minX, minY;
					float maxX, maxY;

					float minX1, minY1;
					float maxX1, maxY1;
					minX = m_objects[i]->GetObjectXposition() - m_objects[i]->GetObjectSize() / 2.f;
					minY = m_objects[i]->GetObjectYposition() - m_objects[i]->GetObjectSize() / 2.f;
					maxX = m_objects[i]->GetObjectXposition() + m_objects[i]->GetObjectSize() / 2.f;
					maxY = m_objects[i]->GetObjectYposition() + m_objects[i]->GetObjectSize() / 2.f;
					minX1 = m_objects[j]->GetObjectXposition() - m_objects[j]->GetObjectSize() / 2.f;
					minY1 = m_objects[j]->GetObjectYposition() - m_objects[j]->GetObjectSize() / 2.f;
					maxX1 = m_objects[j]->GetObjectXposition() + m_objects[j]->GetObjectSize() / 2.f;
					maxY1 = m_objects[j]->GetObjectYposition() + m_objects[j]->GetObjectSize() / 2.f;
					if (BoxCollisionTest(minX, minY, maxX, maxY, minX1, minY1, maxX1, maxY1))
					{
						//캐릭터와 빌딩
						if ((m_objects[i]->GetObjectType() == OBJECT_BUILDING) && (m_objects[j]->GetObjectType() == OBJECT_CHARACTER))
						{
							m_objects[i]->GetDamage(m_objects[j]->GetObjectLife());
							m_objects[j]->SetObjLife(0.f);
							ObjectCollisionCount++;
						}
						else if ((m_objects[j]->GetObjectType() == OBJECT_BUILDING)	&& (m_objects[i]->GetObjectType() == OBJECT_CHARACTER))
						{
							m_objects[i]->GetDamage(m_objects[j]->GetObjectLife());
							//m_objects[j]->SetObjLife(0.f);
							ObjectCollisionCount++;
						}

						//캐릭터와 총알
						else if ((m_objects[i]->GetObjectType() == OBJECT_CHARACTER) && (m_objects[j]->GetObjectType() == OBJECT_BULLET))
						{
							m_objects[i]->GetDamage(m_objects[j]->GetObjectLife());
							m_objects[j]->SetObjLife(0.f);
							ObjectCollisionCount++;
						}
						else if ((m_objects[j]->GetObjectType() == OBJECT_CHARACTER) &&	(m_objects[i]->GetObjectType() == OBJECT_BULLET))
						{
							m_objects[j]->GetDamage(m_objects[i]->GetObjectLife());
							m_objects[i]->SetObjLife(0.f);
							ObjectCollisionCount++;
						}

						
						// Arrow와 캐릭터
						else if ((m_objects[i]->GetObjectType() == OBJECT_ARROW) && (m_objects[j]->GetObjectType() == OBJECT_CHARACTER))
						{
							m_objects[j]->GetDamage(m_objects[i]->GetObjectLife());
							m_objects[i]->SetObjLife(0.f);
							ObjectCollisionCount++;
						}
						else if ((m_objects[j]->GetObjectType() == OBJECT_ARROW) && (m_objects[i]->GetObjectType() == OBJECT_CHARACTER))
						{
							m_objects[i]->GetDamage(m_objects[i]->GetObjectLife());
							m_objects[j]->SetObjLife(0.f);
							ObjectCollisionCount++;
						}

						// Arrow와 빌딩
						else if ((m_objects[i]->GetObjectType() == OBJECT_ARROW) && (m_objects[j]->GetObjectType() == OBJECT_BUILDING))
						{
							m_objects[j]->GetDamage(m_objects[i]->GetObjectLife());
							m_objects[i]->SetObjLife(0.f);
							ObjectCollisionCount++;
						}
						else if ((m_objects[j]->GetObjectType() == OBJECT_ARROW) && (m_objects[i]->GetObjectType() == OBJECT_BUILDING))
						{
							m_objects[i]->GetDamage(m_objects[j]->GetObjectLife());
							m_objects[j]->SetObjLife(0.f);
							ObjectCollisionCount++;
						}
					}
				}
			}

			if (ObjectCollisionCount > 0)
			{
				if (m_objects[i] != NULL && m_objects[i]->GetObjectType() == OBJECT_BUILDING)
				{
					m_objects[i]->ChangeObjectColor(1, 0, 0, 1);
				}
			}
			else
			{
				if (m_objects[i] != NULL && m_objects[i]->GetObjectType() == OBJECT_BUILDING)
				{
					m_objects[i]->ChangeObjectColor(1, 1, 1, 1);
				}
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