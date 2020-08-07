#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>

void display() {

    glClearColor(1,1,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    glFlush();
}

int main(int argc, char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(800,300);
    glutInitWindowSize(500,500);

    glutCreateWindow("Test Window");

    glutDisplayFunc(display);

    glutMainLoop();


    return 0;
}
