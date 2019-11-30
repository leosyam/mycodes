/*  tetris, a game using 
    pantominoes,
    inspired by 
    Chasing Vermeer
 */
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
int xlist[500],ylist[500];
int dx,dy,xx,yy,q,length,score;

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

//for(i=0;i<500;i+=5)
//{
// draw_dot(100,100,0);
// draw_dot(i-5,100,1);
// glFlush();
// usleep(500);
//}

}
 

void init(void)
{  
   glClearColor(1.0, 1.0, 1.0, 0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0,500.0,500.0,0.0);
   glPointSize(10);
   glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
      default:
         printf("%d\n",key);
        break;
      case 32:
        q=q/1.618;
        break;
   }
}

void idleLoop(void)
{
 int open[50][50];
 int x,y,end;

 for(x=0;x<50;x++) 
 {
  for(y=0;y<50;y++)
  {
   open[x][y]=0;
  }
 }
 x=250;
 y=-5;
 end=0;
 
 draw_dot(x-10,y,0);
 draw_dot(x,y,0);
 draw_dot(x+10,y,0);
 draw_dot(x,y+10,0);
 draw_dot(x,y+20,0);

 while(y+20 != 495 && end == 0)
 {
  draw_dot(x-10,y,1);
  draw_dot(x,y,1);
  draw_dot(x+10,y,1);
  draw_dot(x,y+10,1);
  draw_dot(x,y+20,1);
  y=y+10;                  
  draw_dot(x-10,y,0);
  draw_dot(x,y,0);
  draw_dot(x+10,y,0);
  draw_dot(x,y+10,0);
  draw_dot(x,y+20,0);

//if(open[(x-10)/10][(y+5)/10] == 1) end=1;
//if(open[(x+10)/10][(y+5)/10] == 1) end=1;
  if(open[x/10][(y+35)/10] == 1) end=1;

  usleep(50000);
  glFlush();
 }
 //open[(x-10)/10][(y-5)/10]=1;
 //open[x/10][(y-5)/10]=1;
 //open[(x+10)/10][(y-5)/10]=1;
 //open[x/10][(y+5)/10]=1;
 //open[x/10][(y+15)/10]=1;
 open[25][50]=1;
 printf("%d\n",open[25][50]);
}

void catchKey(int key, int x,int y)
{
  switch(key) {
     case GLUT_KEY_LEFT:
       if(dx>0)
       {
       }
       else
       {
        dx=-10;dy=0;   
        break;
       }
     case GLUT_KEY_RIGHT:
       if(dx<0)
       {
       }
       else
       {
        dx=10;dy=0;
        break;
       }
     case GLUT_KEY_DOWN:
       if(dy<0)
       {
       }
       else
       {
        dx=0;dy=10;
        break;
       }
     case GLUT_KEY_UP:
       if(dy>0)
       {
       }
       else
       {
        dx=0;dy=-10;
        break;
       }
 }
}

int main(int argc, char **argv)
{
   
  // return 0;	
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
