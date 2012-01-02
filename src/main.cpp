#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include "Timer.hpp"

void readKeyboard(unsigned char key, int x, int y);
void init();
void update();
void render();
void drawAxis(float size = 1.0f);
void drawFPS();
void output(int x, int y, char *string);

Timer timer;

int main(int argc, char** argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE); 
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Gravity Village");

  glutKeyboardFunc(readKeyboard);

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

void init()
{

}

void update()
{
  timer.tick();
  glutPostRedisplay();
}

void render()
{
  glClear(GL_COLOR_BUFFER_BIT);
  drawAxis();
  drawFPS();
  glutSwapBuffers();
}

void drawAxis(float size)
{
  glBegin(GL_LINES);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(size, 0.0f, 0.0f);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, size, 0.0f);
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, size);
  glEnd();
}

void drawFPS()
{
  char fps[100];
  sprintf(fps, "FPS: %f", timer.getFPS());
  glColor3f(1.0f, 1.0f, 1.0f);
  output(0, 0, fps);
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
