#include<stdio.h>

void main()
{
 float c;
 printf("celcius   fahrenheigt\n");
 for(c=300;c>=0;c-=20)
 {
  printf("%3f %6.f\n ", c, 32+(((9*c))/5.0));
 }
} 
