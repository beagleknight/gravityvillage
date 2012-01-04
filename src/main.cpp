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

int game_width = 640;
int game_height = 480;

Game game(game_width, game_height);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE); 
  glutInitWindowSize(game_width, game_height);
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
  GLfloat aspectRatio;

  if(h == 0) h = 1;

  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  aspectRatio = (GLfloat)w / (GLfloat)h;
  if(w <= h)
  {
    glOrtho(0.0f, game_height / 2, 0, (game_height / 2) / aspectRatio, 1.0, -1.0);
  }
  else
  {
    glOrtho(0, (game_height / 2) * aspectRatio, 0, game_height / 2, 1.0, -1.0);

  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
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
