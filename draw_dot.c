#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>

void main(int argc, char*argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

glutInitWindowPosition(10, 10);
glutInitWindowSize(500,500);

glutCreateWindow("A Simple OpenGL Program");

glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode( GL_PROJECTION );
glLoadIdentity();
gluOrtho2D( 0.0, 500.0, 500.0,0.0 );
glPointSize(10);
glBegin(GL_POINTS);
   glColor3f(1,1,1);
   glVertex2i(100,100);
   glVertex2i(200,200);
glEnd();
glFlush();
glutMainLoop();
}
