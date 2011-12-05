#include "Globals.h"
#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::render()
{
  glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
  
  glColor3f(1.0f, 0.0f, 0.0f);
  glRectf(-25.0f, 25.0f, 25.0f, -25.0f);

	glutSwapBuffers();
}

void Game::update(float dt)
{

}
