#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

using namespace std;

float angle = 0;

void init() {
	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0,0,-8);
	glRotatef(angle,1,0,0);
	glRotatef(angle,0,1,0);
	glRotatef(angle,0,0,1);

	//draw
	glBegin(GL_QUADS);

	//front
	glColor3f(0.7,0.3,0.5); 
	glVertex3f(-1,1,1);  
	glVertex3f(1,1,1);
	glVertex3f(1,-1,1);
	glVertex3f(-1,-1,1);

	//back
	glColor3f(0,1,0);
	glVertex3f(-1,1,1);  
	glVertex3f(1,1,1);
	glVertex3f(1,-1,1);
	glVertex3f(-1,-1,1);

	//right
	glColor3f(0,0,1); 
	glVertex3f(1,1,1);  
	glVertex3f(1,1,-1);
	glVertex3f(1,-1,-1);
	glVertex3f(1,-1,1);

	//left
	glColor3f(1,0,1); 
	glVertex3f(-1,1,1);
	glVertex3f(-1,-1,1);
	glVertex3f(-1,-1,-1);
	glVertex3f(-1,1,-1);

	//top
	glColor3f(1,0,0); 
	glVertex3f(1,1,1);
	glVertex3f(1,1,-1);
	glVertex3f(-1,1,-1);
	glVertex3f(-1,1,1);

	//bottom
	glColor3f(1,1,0); 
	glVertex3f(1,-1,1);
	glVertex3f(1,-1,-1);
	glVertex3f(-1,-1,-1);
	glVertex3f(-1,-1,1);

	glEnd();
	
	glutSwapBuffers();

}

void reshape(int w, int h) {
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,1,5,50);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
	glutPostRedisplay();
	
	/*switch(forward) {
		case true:
			if(z_position > -40) z_position -= 0.2;
			else forward = false;
			break;

		case false:
			if(z_position < -10) z_position += 0.2;
			else forward = true;
			break;
	}*/
	
	angle += 2;
	if(angle>360) angle-=360;
	glutTimerFunc(1000/60,timer,0);
}

int main(int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB/* | GLUT_DOUBLE*/);

	glutInitWindowPosition(100,100);
	glutInitWindowSize(700,700);

	glutCreateWindow("rotation");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);

	init();
	glutMainLoop();

	return 0;
}
