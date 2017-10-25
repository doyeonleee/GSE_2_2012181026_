/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"
#include "Object.h"
#include "SceneMgr.h"

Renderer *g_Renderer = NULL;
//ObjectManager Rect(0, 0, 0, 4, 1, 0, 1, 1);

Object *Rect = NULL;
//Object *Rect2 = NULL;

SceneMgr *Mgr = NULL;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test

	//g_Renderer->DrawSolidRect(0, 0, 0, 4, 1, 0, 1, 1);


	//g_Renderer->DrawSolidRect(
	//	Rect->GetObjectXposition(), Rect->GetObjectYposition(), Rect->GetObjectZposition(),
	//	Rect->GetObjectSize(), Rect->GetObjectRed(), Rect->GetObjectGreen(),
	//	Rect->GetObjectBlue(), Rect->GetObjectAlpha()
	//);

	for (int i = 0; i < Mgr->MAX_OBJECTS_COUNT; ++i) {
		Mgr->m_renderer->DrawSolidRect(
			Mgr->m_objects[i]->GetObjectXposition(), 
			Mgr->m_objects[i]->GetObjectYposition(),
			Mgr->m_objects[i]->GetObjectZposition(),
			Mgr->m_objects[i]->GetObjectSize(),
			Mgr->m_objects[i]->GetObjectRed(),
			Mgr->m_objects[i]->GetObjectGreen(),
			Mgr->m_objects[i]->GetObjectBlue(),
			Mgr->m_objects[i]->GetObjectAlpha()
			
			);
	}

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
	
	//Rect->Update();

	Mgr->SceneUpdate();

}

void MouseInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//g_LButtonDown = true;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//if(g_LButtonDown)
		{

		}
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

	// Initialize Renderer
	//g_Renderer = new Renderer(500, 500);
	//if (!g_Renderer->IsInitialized())
	//{
	//	std::cout << "Renderer could not be initialized.. \n";
	//}
	//Rect = new Object(0, 0, 0, 4, 1, 0, 1, 1);


	//
	Mgr = new SceneMgr(500, 500);

	for (int i = 0; i < Mgr->MAX_OBJECTS_COUNT; ++i) {
		Mgr->ObjectAdd();
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	//delete g_Renderer;
	delete Mgr;

    return 0;
}

