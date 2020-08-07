#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

using namespace std;

float x_position = -10;
bool forward = true;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	//glPointSize(10);
	glBegin(GL_POLYGON);
	glVertex2f(x_position,-1); glVertex2f(x_position,1);
	glVertex2f(x_position+2,1); glVertex2f(x_position+2,-1);

	glEnd();
	
	glutSwapBuffers();

}

void reshape(int w, int h) {
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
	glutPostRedisplay();
	
	switch(forward) {
		case true:
			if(x_position < 8) x_position += 0.1;
			else forward = false;
			break;

		case false:
			if(x_position > -10) x_position -= 0.1;
			else forward = true;
			break;
	}
	
	glutTimerFunc(1000/60,timer,0);
}

int main(int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowPosition(100,100);
	glutInitWindowSize(700,700);

	glutCreateWindow("animation");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(500,timer,0);

	glutMainLoop();

	return 0;
}
