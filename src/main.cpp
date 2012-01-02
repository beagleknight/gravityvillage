#include <GL/glut.h>

void render();
void readKeyboard(unsigned char key, int x, int y);
void drawAxis(float size = 1.0f);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE); 
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Gravity Village");

  glutDisplayFunc(render);
  glutKeyboardFunc(readKeyboard);

  glutMainLoop();
}

void render()
{
  glClear(GL_COLOR_BUFFER_BIT);
  drawAxis();
  glutSwapBuffers();
}

void readKeyboard(unsigned char key, int x, int y)
{
  if(key == 27)
    exit(0);
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
