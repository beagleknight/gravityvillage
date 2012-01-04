#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include "Timer.hpp"
#include "TileMap.hpp"
#include "Player.hpp"

void readKeyboard(unsigned char key, int x, int y);
void readSpecialKeyboard(int key, int x, int y);
void readSpecialUpKeyboard(int key, int x, int y);
void init();
void update();
void reshape(int w, int h);
void render();
void renderFPS();
void output(int x, int y, char *string);

Timer timer;
TileMap map;
Player player;

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
  if(key == 27)
    exit(0);
}

void readSpecialKeyboard(int key, int x, int y)
{
  switch(key)
  {
    case GLUT_KEY_LEFT:
      player.setVelX(-50);
      break;
    case GLUT_KEY_RIGHT:
      player.setVelX(50);
      break;
  }
}

void readSpecialUpKeyboard(int key, int x, int y)
{
  player.setVelX(0);
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

  timer.init();
  map.init(20, 20, 8, 10, 32, 32, "res/test.png");
  player.init(96, 96, "res/link.png");
  player.setCols(7);
  player.setTotalFrames(7);
  player.setWidth(16);
  player.setHeight(24);
  player.setAnimationTime(0.5f);
}

void update()
{
  float dt = timer.tick();

  player.update(dt);

  glutPostRedisplay();
}

void render()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  map.render();
  player.render();

  renderFPS();

  glutSwapBuffers();
}

void renderFPS()
{
  char fps[100];
  sprintf(fps, "FPS: %f", timer.getFPS());
  glColor3f(1.0f, 1.0f, 1.0f);
  output(0, (game_height / 2) - 25, fps);
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
