#include "Scene.h"
#include "Game.h"

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::render()
{
  TextureManager *tm = Game::getInstance().getSceneManager()->getTextureManager();

  glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

  glEnable(GL_TEXTURE_2D);

  //tm->setActive("bub");
  glBegin(GL_QUADS);
  glTexCoord2f(0.25f, 0.25f); glVertex2f(25.0f, -25.0f);
  glTexCoord2f(0.25f, 0.0f); glVertex2f(25.0f, 25.0f);
  glTexCoord2f(0.0f, 0.0f); glVertex2f(-25.0f, 25.0f);
  glTexCoord2f(0.0f, 0.25f); glVertex2f(-25.0f, -25.0f);
  glEnd();

  glDisable(GL_TEXTURE_2D);

  //glBegin(GL_LINES);
  //glColor3f(1.0f, 0.0f, 0.0f);
  //glVertex2f(0.0f, 0.0f);
  //glVertex2f(200.0f, 0.0f);
  //glColor3f(0.0f, 1.0f, 0.0f);
  //glVertex2f(0.0f, 0.0f);
  //glVertex2f(0.0f, 200.0f);
  //glEnd();

	glutSwapBuffers();
}

void Scene::update(float dt)
{

}
