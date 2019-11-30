#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 11
#define M 10000

void stats(int open[N][N]);

void update(int open[N][N],int l, int c)
{
 int i,j;
 for(j=0;j<N;j++)
 {
  if (j!=c) open[l][j]=0;
 }
 for(i=0;i<N;i++)
 {
  if (i!=l) open[i][c]=0;
 }
 for(i=l+1,j=c+1;i<N && j<N;i++,j++)
 {
  open[i][j]=0;
 }
 for(i=l+1,j=c-1;i<N && j>-1;i++,j--)
 {
  open[i][j]=0;
 }
 for(i=l-1,j=c+1;i>-1 && j<N;i--,j++)
 {
  open[i][j]=0;
 }
 for(i=l-1,j=c-1;i>-1 && j>-1;i--,j--)
 {
  open[i][j]=0;
 }
}
int checkallsol(int open[N][N],int solutions[N][N][M],int solnb)
{
 int i,j,k,ii,jj;
 int newsol,mychar,flag;
 newsol=0;
 for(k=0;k<solnb;k++)
 {
//  printf("comparing open to old solution %d out of %d\n",k+1,solnb);
  flag=checkonesol(open,solutions,k);
  if (flag==0)
  {
  // printf("solution rejected\n");  
 //  mychar=getchar();
   return newsol;
  }
 // printf("ready to check next solution?\n");  
 // mychar=getchar();
 }
 //printf("solution accepted\n");  
 //mychar=getchar();
 newsol=1;
 return newsol;
}
int checkonesol(int open[N][N],int solutions[N][N][M],int k)
{
 int i,j,mychar,flag; 
 flag=0;
  for(i=0;i<N;i++)
  {
   for(j=0;j<N;j++)
   {
    if (solutions[i][j][k]!=open[i][j])
    {   
   // printf("solution is different \n"); 
    //mychar=getchar();
    flag=1;
    return flag; 
    } 
   }
  }
 return flag;
}
void stats(int open[N][N])
{
 int i,j;
 for(i=0;i<N;i++)
 {
  for(j=0;j<N;j++)
  {
  printf("%d   ",open[i][j]);
  }
 printf("\n\n");
 }
 printf("\n\n\n");
}
void main()
{
 int open[N][N];
 int i,ii,j,jj,k,ln,stop,closed,solnb,trynb,newsol;
 int mychar;
 int solutions[N][N][M];
 newsol=0;
 for(i=0;i<N;i++)
 {
  for(j=0;j<N;j++)
  {
   for(k=0;k<M;k++)
   {
    solutions[i][j][k]=0;
   }
  }
 }
 solnb=0;
 srand(time(NULL));
 for(trynb=0;trynb<10000000;trynb++)
 {
 for(i=0;i<N;i++)
 {
  for(j=0;j<N;j++)
  {
  open[i][j]=1;
  }
 }
 //stats(open);
 for(ln=0;ln<N;ln++){
 // printf("Trying to fill in line nb %d \n",ln+1);
  closed=1;
  for(k=0;k<N;k++)
  {
   if (open[ln][k]==1)
   {
    closed=0;
    break;
   }
  }
  if (closed==1) 
  {
   //printf("%d\n",ln);
   //main();
   break;
  }
  stop=0;
  while(stop==0 && closed==0) 
  {
   k=rand()%N;
   if (open[ln][k]==1) stop=1;
  }
  open[ln][k]=2; 
  update(open,ln,k);
  if (ln==N-1 && closed==0)
  {
   newsol=checkallsol(open,solutions,solnb);
   if (newsol==1)
   {
    solnb+=1;
    printf("found solution nb. %d out of %d\n", solnb, trynb);
    for(ii=0;ii<N;ii++)
     {
      for(jj=0;jj<N;jj++)
      {
       solutions[ii][jj][solnb-1]=open[ii][jj];  
      }
     }
    }
//  stats(open);
  //mychar=getchar();
  }
 } 
}
}

