#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

using namespace std;

float max(float a, float b) {
	return a > b ? a : b;
}

void setPointsByDDA() {
	float x1,y1,x2,y2;
	cout<<"Line joing two points -- Only for positive slope"<<endl;
	cout<<"Enter x1 and y1"<<" "; cin>>x1>>y1;
	cout<<"\nEnter x2 and y2"<<" "; cin>>x2>>y2;

	float delX = abs(x2-x1);
	float delY = abs(y2-y1);
	float slope = delY/delX;
	int steps = max(delX,delY);
	int x[steps],y[steps]; x[0] = x1+0.5; y[0] = y1+0.5;
	if(delX >= delY) {
		for (int i = 1; i < steps; ++i)
		{
			x[i] = x[0] + i;
            y[i] = y[0] + slope*i + 0.5;
		}
	} 
	else if (delX < delY)
	{
		for (int i = 1; i < steps; ++i)
		{
			x[i] = x[0] + (1/slope)*i + 0.5;
            y[i] = y[0] + i;
		}
	}

	for (int i = 0; i < steps; ++i)
	{
		glVertex2i(x[i],y[i]);
	}
}

void display() {
	//glClearColor(0.5,1,0.5,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPointSize(2);

	glBegin(GL_LINES);
	glVertex2i(0,-100); glVertex2i(0,100);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(-100,0); glVertex2i(100,0);
	glEnd();
	glFlush();

	glBegin(GL_POINTS);

	setPointsByDDA();

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

	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);

	glutCreateWindow("DDA");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
	
	return 0;
}