/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include "windows.h"

#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"
#include "Object.h"
#include "SceneMgr.h"

Renderer *g_Renderer = NULL;
Object *Rect = NULL;

SceneMgr *Mgr = NULL;
DWORD elapsedTime = 0;
DWORD g_prevTime = 0;

bool g_LButtonDown = false;


void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	DWORD currentTime = timeGetTime();
	DWORD elapsedTime = currentTime - g_prevTime;
	g_prevTime = currentTime;

	Mgr->SceneUpdate((float)elapsedTime);
	Mgr->DrawObject();

	//for (int i = 0; i < Mgr->MAX_OBJECTS_COUNT; ++i) {
	//	if (Mgr->m_objects[i] != NULL) {
	//		Mgr->m_renderer->DrawSolidRect(
	//			Mgr->m_objects[i]->GetObjectXposition(),
	//			Mgr->m_objects[i]->GetObjectYposition(),
	//			Mgr->m_objects[i]->GetObjectZposition(),
	//			Mgr->m_objects[i]->GetObjectSize(),
	//			Mgr->m_objects[i]->GetObjectRed(),
	//			Mgr->m_objects[i]->GetObjectGreen(),
	//			Mgr->m_objects[i]->GetObjectBlue(),
	//			Mgr->m_objects[i]->GetObjectAlpha()
	//		);
	//	}
	//}

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		g_LButtonDown = true;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if(g_LButtonDown)
		{
			for (int i = 0; i < 1; i++)
				Mgr->AddPlusObject((float)x-250, (float)-y+250);
		}
		g_LButtonDown = false;
	}
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	//
	Mgr = new SceneMgr(500, 500);

	//ºôµù »ý¼º
	Mgr->ObjectFirstAdd();

	//for (int i = 0; i < Mgr->MAX_OBJECTS_COUNT; ++i) {
	//	Mgr->ObjectFirstAdd();
	//}
	
	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	g_prevTime = timeGetTime();

	glutMainLoop();

	//delete g_Renderer;
	delete Mgr;

    return 0;
}

