#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include "Timer.hpp"
#include "Texture.hpp"

void readKeyboard(unsigned char key, int x, int y);
void init();
void update();
void reshape(int w, int h);
void render();
void drawAxis(float size = 100.0f);
void drawFPS();
void output(int x, int y, char *string);
void drawTexture(float size = 100.0f);

Timer timer;
Texture texture;

int main(int argc, char** argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE); 
  glutInitWindowSize(640, 480);
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
    glOrtho(-300.0, 300.0, -300 / aspectRatio, 300.0 / aspectRatio, 1.0, -1.0);
  }
  else
  {
    glOrtho(-300.0 * aspectRatio, 300.0 * aspectRatio, -300.0, 300.0, 1.0, -1.0);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void init()
{
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
  glAlphaFunc(GL_GREATER, 0.05f);
  glEnable(GL_ALPHA_TEST);
  texture.load("res/test.png");
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
  drawTexture();
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
  output(200, 200, fps);
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

void drawTexture(float size)
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture.getId());
  glColor3f(1.0f, 1.0f, 1.0f);
  glBegin(GL_QUADS);
  glVertex2f(0.0f, 0.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex2f(0.0f, size);
  glTexCoord2f(1.0f, 0.0f);
  glVertex2f(size, size);
  glTexCoord2f(1.0f, 1.0f);
  glVertex2f(size, 0.0f);
  glTexCoord2f(0.0f, 1.0f);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}
