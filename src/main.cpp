#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include "Timer.hpp"
#include "TileMap.hpp"

void readKeyboard(unsigned char key, int x, int y);
void init();
void update();
void reshape(int w, int h);
void render();
void drawFPS();
void output(int x, int y, char *string);

Timer timer;
TileMap map(20, 20, 32, 32, "res/test.png");

int game_width = 640;
int game_height = 480;

int main(int argc, char** argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE); 
  glutInitWindowSize(game_width, game_height);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Gravity Village");

  glutKeyboardFunc(readKeyboard);
  glutReshapeFunc(reshape);
  glutDisplayFunc(render);
  glutIdleFunc(update);

  init();
  glutMainLoop();
}

void readKeyboard(unsigned char key, int x, int y)
{
  if(key == 27)
    exit(0);
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
    glOrtho(0.0f, game_height, 0, game_height / aspectRatio, 1.0, -1.0);
  }
  else
  {
    glOrtho(0, game_height * aspectRatio, 0, game_height, 1.0, -1.0);

  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void init()
{
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
  glAlphaFunc(GL_GREATER, 0.05f);
  glEnable(GL_ALPHA_TEST);
}

void update()
{
  timer.tick();
  glutPostRedisplay();
}

void render()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  drawFPS();
  map.draw();

  glutSwapBuffers();
}

void drawFPS()
{
  char fps[100];
  sprintf(fps, "FPS: %f", timer.getFPS());
  glColor3f(1.0f, 1.0f, 1.0f);
  output(0, game_height - 25, fps);
}

void output(int x, int y, char *string)
{
  int len, i;
  void *font = GLUT_BITMAP_TIMES_ROMAN_24;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}
