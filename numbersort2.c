#include<stdio.h>
#include<stdlib.h>
void main ()
{
  int a[10];
  int i;
  int max;
  srand(time(NULL));
  for (i=0;i<10;i++) {
    a[i]=rand()%100;
    printf("%d\n",a[i]);
  }
int j,k,maxprev;
//max=-2000;
maxprev=10000;
for(k=1;k<=10;k++)
{
 max=-2000;
 for(j=0;j<10;j++){
   if (a[j] < maxprev) 
    {
     if (max < a[j] && a[j] < maxprev){
     //maxprev=max;
     max=a[j];
     }
    }
 }
 printf("max%d=%d\n",k,max);
 maxprev=max;
}
}
