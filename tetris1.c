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
int open[50][50],pantomino[5][5];
 
void draw_dot(int x, int y,int c)
{
  glBegin(GL_POINTS);
   glColor3f(c,c,c);
   glVertex2i(x,y);
  glEnd();
}
void draw_shape(int x, int y,int c)
{
 int xp,yp;
 for(xp=0;xp<5;xp++)
 {
  for(yp=0;yp<5;yp++) 
  {
   if (pantomino[xp][yp] == 1) draw_dot(x+((xp-2)*10),y+((yp-2)*10),c);
  }
 }
/*
 if (pantomino[1][1] == 1) draw_dot(x-10,y-10,c);
 if (pantomino[1][2] == 1) draw_dot(x,y-10,c);
 if (pantomino[1][3] == 1) draw_dot(x+10,y-10,c);
 if (pantomino[2][1] == 1) draw_dot(x-10,y,c);
 if (pantomino[2][2] == 1) draw_dot(x,y,c);
 if (pantomino[2][3] == 1) draw_dot(x+10,y,c);
 if (pantomino[3][1] == 1) draw_dot(x-10,y+10,c);
 if (pantomino[3][2] == 1) draw_dot(x,y+10,c);
 if (pantomino[3][3] == 1) draw_dot(x+10,y+10,c);
*/
}
void set_T(int pantomino[5][5])
{
 pantomino[1][0]=1;
 pantomino[2][0]=1;
 pantomino[3][0]=1;
 pantomino[2][1]=1;
 pantomino[2][2]=1;
}
void set_I(int pantomino[5][5])
{
 pantomino[3][0]=1;
 pantomino[3][1]=1;
 pantomino[3][2]=1;
 pantomino[3][3]=1;
 pantomino[3][4]=1;
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
   int x,y;
   glClearColor(1.0, 1.0, 1.0, 0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0,500.0,500.0,0.0);
   glPointSize(10);
   glFlush();
   for(x=0;x<50;x++) 
   {
    for(y=0;y<50;y++)
    {
     open[x][y]=0;
    }
   }
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
      default:
         printf("%d\n",key);
                }
}

void idleLoop(void)
{   
int x,y,xp,yp,setrand,end;

 x=245;
 y=-5;
 end=0;
 
 while(y < 495 && end == 0)
 {
  setrand=srand(time(NULL));
  if (floor(setrand/2) == setrand/2)  set_T(pantomino);
  else set_I(pantomino);
  // check if spot at y+10 is opened:
  // printf("%d\n",y);

/*if (open[(x+5-10)/10][(y+10+5)/10] == 1) end=1;	
  if (open[(x+5)/10][(y+10+5)/10]==1) end=1;
  if (open[(x+5+10)/10][(y+10+5)/10]==1) end=1;
  if (open[(x+5)/10][(y+5+20)/10]==1) end=1;
  if (open[(x+5)/10][(y+5+30)/10]==1) end=1;*/
  //printf("end=%d\n",end);
 
  	
   draw_shape(x,y,1);
   y=y+10;                  
   draw_shape(x,y,0);
   for(xp=0;xp<5;xp++)
   {
    for(yp=0;yp<5;yp++) 
    {
     if (pantomino[xp][yp] == 1)
     {
      if (open[((x+((xp-2)*10))+5)/10][(((y+((yp-2)*10))+5)/10)+1] == 1) 
      {
       end=1;
//       printf("original: x is %d  y is %d\n",x,y);
//       printf("open: x is %d  y is %d\n", ((x+((xp-2)*10))+5)/10, ((y+((yp-2)*10))+5)/10);
      }
     }
    }
   }

   usleep(500000);
   printf("%d\n",y);
   glFlush();
  
 }
 for(xp=0;xp<5;xp++)
 {
  for(yp=0;yp<5;yp++) 
  {
   if (pantomino[xp][yp] == 1) open[((x+((xp-2)*10))+5)/10][((y+((yp-2)*10))+5)/10]=1;
  }
 }
} 

void catchKey(int key, int x,int y)
{
/*switch(key) {
     case GLUT_KEY_LEFT:
       if(dx>0)
       {
       }
       else
       {
        break;
       }
     case GLUT_KEY_RIGHT:
       if(dx<0)
       {
       }
       else
       {
        break;
       }
     case GLUT_KEY_DOWN:
       if(dy<0)
       {
       }
       else
       {
        break;
       }
     case GLUT_KEY_UP:
       if(dy>0)
       {
       }
       else
       {
        break;
       }
 }
*/
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
