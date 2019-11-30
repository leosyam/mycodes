#include<stdio.h>

void main()
{
 int i,j;

 for(j=1;j<=10;j++)
 {
  for(i=1;i<=10;i++)
  {
    printf("%d ",(j-1)*10+i);
   if (j==1) printf(" ");
  }
  printf("\n");
 }

}
