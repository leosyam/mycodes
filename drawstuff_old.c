/*  learn to draw points and lines
     Leo and Papa
     04/20/2019
 */
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
int xx,yy,xxold,yyold,dx,dy;

void draw_dot(int x, int y,int c)
{
  glBegin(GL_POINTS);
   glColor3f(c,c,c);
   glVertex2i(x,y);
  glEnd();
}

void display(void)
{
int i;
/*
for(i=0;i<500;i+=5)
{
 draw_dot(i,100,0);
 draw_dot(i-5,100,1);
 glFlush();
 usleep(500);
}
*/
}
 

void init(void)
{
   glClearColor(1.0, 1.0, 1.0, 0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0,500.0,500.0,0.0);
   glPointSize(10);
   xx=100;
   yy=100;
   dx=0; 
   dy=0;
   glFlush();
}
int a,b;
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
      default:
        printf("%d\n",key);
        break;
   }
}

void idleLoop(void)
{
xx=(xx+dx)%500;
yy=(yy+dy)%500;
if (xx < 0) xx=500+xx;
if (yy < 0) yy=500+yy;
draw_dot(xxold,yyold,1);
draw_dot(xx,yy,0);
xxold=xx;
yyold=yy;
usleep(1000);
glFlush();
}
void catchKey(int key, int x,int y)
{
  switch(key) {
     case GLUT_KEY_LEFT:
        dx=-1;dy=0;   
        break;
     case GLUT_KEY_RIGHT:
        dx=1;dy=0;
        break;
     case GLUT_KEY_DOWN:
        dx=0;dy=1;
        break;
     case GLUT_KEY_UP:
        dx=0;dy=-1;
        break;
   }
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(catchKey);
   glutIdleFunc(idleLoop);
   glutMainLoop();
   return 0;
}
