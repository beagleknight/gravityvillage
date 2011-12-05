#include "Scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::render()
{
  glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

  glBegin(GL_LINES);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(0.0f, 0.0f);
  glVertex2f(200.0f, 0.0f);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(0.0f, 0.0f);
  glVertex2f(0.0f, 200.0f);
  glEnd();

	glutSwapBuffers();
}

void Scene::update(float dt)
{

}
