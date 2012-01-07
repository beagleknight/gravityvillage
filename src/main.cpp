#include <GL/glut.h>
#include "Game.hpp"

void readKeyboard(unsigned char key, int x, int y);
void readUpKeyboard(unsigned char key, int x, int y);
void readSpecialKeyboard(int key, int x, int y);
void readSpecialUpKeyboard(int key, int x, int y);
void reshape(int w, int h);
void init();
void update();
void render();

#define GAME_WIDTH 640
#define GAME_HEIGHT 480

Game game;

int main(int argc, char** argv)
{
  int res_x, res_y, pos_x, pos_y;

  game.setWindowWidth(GAME_WIDTH);
  game.setWindowHeight(GAME_HEIGHT);

  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE); 

  res_x = glutGet(GLUT_SCREEN_WIDTH);
  res_y = glutGet(GLUT_SCREEN_HEIGHT);
  pos_x = (res_x>>1)-(game.getWindowWidth()>>1);
  pos_y = (res_y>>1)-(game.getWindowHeight()>>1);

  glutInitWindowPosition(pos_x,pos_y);
  glutInitWindowSize(game.getWindowWidth(), game.getWindowHeight());
  glutCreateWindow("Gravity Village");

  glutKeyboardFunc(readKeyboard);
  glutKeyboardUpFunc(readUpKeyboard);
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
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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
