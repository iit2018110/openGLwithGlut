#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void display() {
	//glClearColor(0.5,1,0.5,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	//glPointSize(3);
	glBegin(GL_POLYGON);
	
	glVertex2i(-50,-30);
	glVertex2i(-30,-50);
	glVertex2i(0,-50);
	glVertex2i(10, 30);

	glEnd();
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);

	glutInitWindowPosition(800,300);
	glutInitWindowSize(700,700);

	glutCreateWindow("Shape");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
	
	return 0;
}