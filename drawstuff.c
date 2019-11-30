/*  learn to draw points and lines
     Leo and Papa
     04/20/2019
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
   int i;
   q=1000000;
   score=0;
   srand(time(NULL));
   glClearColor(1.0, 1.0, 1.0, 0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0,500.0,500.0,0.0);
   glPointSize(10);
   length=1;
   for(i=0;i<length;i++)
     {
      xlist[i]=10+i*10;
      ylist[i]=250;
      draw_dot(xlist[i],ylist[i],0);
     }
   dx=0; 
   dy=0;
   glBegin(GL_POINTS);
     glColor3f(1,0,0);
     yy=rand()%500+1;
     while (yy%10!=0)
     {
      yy=rand()%500+1; 
      printf("%d\n",yy);
     }
      xx=rand()%500+1;
      while (xx%10!=0)
     {
      xx=rand()%500+1; 
      printf("%d\n",xx);
     }
     glVertex2i(xx,yy);
   glEnd();


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
      case 32:
        q=q/1.618;
        break;
   }
}

void idleLoop(void)
{
int i,t;
int xnew,ynew;
draw_dot(xlist[0],ylist[0],1); // erase the tail
xnew=xlist[length-1]+dx;
ynew=ylist[length-1]+dy;
for(i=0;i<length-1;i++)
  {
   xlist[i]=xlist[i+1];
   ylist[i]=ylist[i+1];
  }
xlist[length-1]=xnew;
ylist[length-1]=ynew;
draw_dot(xnew,ynew,0); // draw the head
if (length > 1) 
{
  for(t=0;t<length-1;t++) 
   {
     if (xnew==xlist[t] && ynew==ylist[t]) //check to make sure you are not touching yourself
     {
        printf("failure\n");
        exit(0);
     }
   }
}
     if (xnew==xx && ynew==yy) 
     {
     q=q/1.1;
     glBegin(GL_POINTS);
     glColor3f(1,0,0);
     yy=rand()%500+1;
     while (yy%10!=0)
     {
      yy=rand()%498+2; 
     }
      xx=rand()%500+1;
      while (xx%10!=0)
     {
      xx=rand()%498+2; 
     }
     glVertex2i(xx,yy);
     glEnd();
     length+=1;
     printf("your score just increased!! it is now %d\n",length);
     for (score=0;score<5;score++)
     {
     xlist[length-1]=xlist[length-2]+dx;
     ylist[length-1]=ylist[length-2]+dy;
     draw_dot(xlist[length-1],ylist[length-1],0);
     }
     } 
     if (xnew>500||xnew<0||ynew>500||ynew<0)
     {
     exit(0);
     }
usleep(100000);
glFlush();
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
