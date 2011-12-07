#include "Globals.h"
#include "Game.h"

void RenderCallback(void);
void KeyDownCallback(unsigned char, int, int);
void setupRC(void);
void ChangeSize(GLsizei, GLsizei);

int main(int argc, char **argv)
{
	int res_x,res_y,pos_x,pos_y;

  //GLUT Initialization
  glutInit(&argc,argv);

  //RGBA with double buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE);

	//Create centered window
	res_x = glutGet(GLUT_SCREEN_WIDTH);
	res_y = glutGet(GLUT_SCREEN_HEIGHT);
	pos_x = (res_x>>1)-(GAME_WIDTH>>1);
	pos_y = (res_y>>1)-(GAME_HEIGHT>>1);
	glutInitWindowPosition(pos_x,pos_y);
	glutInitWindowSize(GAME_WIDTH,GAME_HEIGHT);
  glutCreateWindow("Gravity Village");

  //Register callbacks
  glutDisplayFunc(RenderCallback);
	glutKeyboardFunc(KeyDownCallback);		
  glutReshapeFunc(ChangeSize);

  //Setup
  setupRC();

  glutMainLoop();
  return 0;
}

void RenderCallback(void)
{
  Game::getInstance().render();
}

void KeyDownCallback(unsigned char key, int x, int y)
{
  if(key == 27) {
    exit(0);
  }
}

void setupRC(void)
{
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glAlphaFunc(GL_GREATER, 0.05f);
	glEnable(GL_ALPHA_TEST);
}

void ChangeSize(GLsizei w, GLsizei h)
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
