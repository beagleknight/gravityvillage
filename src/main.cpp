#include <GL/glut.h>
#include "Game.hpp"

void readKeyboard(unsigned char key, int x, int y);
void readUpKeyboard(unsigned char key, int x, int y);
void readSpecialKeyboard(int key, int x, int y);
void readSpecialUpKeyboard(int key, int x, int y);
void init();
void update();
void reshape(int w, int h);
void render();

Game game;

int main(int argc, char** argv)
{
  game.setWindowWidth(640);
  game.setWindowHeight(480);

  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE); 
  glutInitWindowSize(game.getWindowWidth(), game.getWindowHeight());
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Gravity Village");

  glutKeyboardFunc(readKeyboard);
  glutSpecialFunc(readSpecialKeyboard);
  glutSpecialUpFunc(readSpecialUpKeyboard);
  glutReshapeFunc(reshape);
  glutDisplayFunc(render);
  glutIdleFunc(update);

  init();

  glutMainLoop();
}

void readKeyboard(unsigned char key, int x, int y)
{
  game.readKeyboard(key, true);
}

void readUpKeyboard(unsigned char key, int x, int y)
{
  game.readKeyboard(key, false);
}

void readSpecialKeyboard(int key, int x, int y)
{
  game.readKeyboard(key, true);
}

void readSpecialUpKeyboard(int key, int x, int y)
{
  game.readKeyboard(key, false);
}

void reshape(int w, int h)
{
  if(h == 0) h = 1;

  glViewport(0, 0, w, h);

  game.setWindowWidth(w);
  game.setWindowHeight(h);
}

void init()
{
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
  glAlphaFunc(GL_GREATER, 0.05f);
  glEnable(GL_ALPHA_TEST);

  game.init();
}

void update()
{
  game.update();
  glutPostRedisplay();
}

void render()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  game.render();

  glutSwapBuffers();
}
