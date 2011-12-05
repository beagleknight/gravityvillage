#include <GL/glut.h>

#define GAME_WIDTH 640
#define GAME_HEIGHT 480

void RenderCallback(void);
void KeyDownCallback(unsigned char,int,int);
void setupRC(void);

int main(int argc, char **argv) {
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

  //Setup
  setupRC();

  glutMainLoop();
  return 0;
}

void RenderCallback(void) {
  glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glutSwapBuffers();
}

void KeyDownCallback(unsigned char key, int x, int y) {
  if(key == 27) {
    exit(0);
  }
}

void setupRC(void) {
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}
