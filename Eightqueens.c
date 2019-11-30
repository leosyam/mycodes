#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void stats(int open[8][8]);

void update(int open[8][8],int l, int c)
{
 int i,j;
 for(j=0;j<8;j++)
 {
  if (j!=c) open[l][j]=0;
 }
 for(i=0;i<8;i++)
 {
  if (i!=l) open[i][c]=0;
 }
 for(i=l+1,j=c+1;i<8 && j<8;i++,j++)
 {
  open[i][j]=0;
 }
 for(i=l+1,j=c-1;i<8 && j>-1;i++,j--)
 {
  open[i][j]=0;
 }
 for(i=l-1,j=c+1;i>-1 && j<8;i--,j++)
 {
  open[i][j]=0;
 }
 for(i=l-1,j=c-1;i>-1 && j>-1;i--,j--)
 {
  open[i][j]=0;
 }
}
int checkallsol(int open[8][8],int solutions[8][8][200],int solnb)
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
int checkonesol(int open[8][8],int solutions[8][8][200],int k)
{
 int i,j,mychar,flag; 
 flag=0;
  for(i=0;i<8;i++)
  {
   for(j=0;j<8;j++)
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
void stats(int open[8][8])
{
 int i,j;
 for(i=0;i<8;i++)
 {
  for(j=0;j<8;j++)
  {
  printf("%d   ",open[i][j]);
  }
 printf("\n\n");
 }
 printf("\n\n\n");
}
void main()
{
 int open[8][8];
 int i,ii,j,jj,k,ln,stop,closed,solnb,trynb,newsol;
 int mychar;
 int solutions[8][8][200];
 newsol=0;
 for(i=0;i<8;i++)
 {
  for(j=0;j<8;j++)
  {
   for(k=0;k<200;k++)
   {
    solutions[i][j][k]=0;
   }
  }
 }
 solnb=0;
 srand(time(NULL));
 for(trynb=0;trynb<1000000;trynb++)
 {
 for(i=0;i<8;i++)
 {
  for(j=0;j<8;j++)
  {
  open[i][j]=1;
  }
 }
 //stats(open);
 for(ln=0;ln<8;ln++){
 // printf("Trying to fill in line nb %d \n",ln+1);
  closed=1;
  for(k=0;k<8;k++)
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
   k=rand()%8;
   if (open[ln][k]==1) stop=1;
  }
  open[ln][k]=2; 
  update(open,ln,k);
  if (ln==7 && closed==0)
  {
   newsol=checkallsol(open,solutions,solnb);
   if (newsol==1)
   {
    solnb+=1;
    printf("found solution nb. %d out of %d\n", solnb, trynb);
    for(ii=0;ii<8;ii++)
     {
      for(jj=0;jj<8;jj++)
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

