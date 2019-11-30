#include<stdio.h>

void main()
{
 double i,j,k;
 j=10000;
 k=0;
 i=0;
 while (i<101)
 {
  i=i+1;
  k=j+k;
  printf("%f\n",k);
  j=j/2;
 }
}

