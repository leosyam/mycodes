#include<stdio.h>

void rcpr()
{
 int c;
 c=getchar();
 if (c=='\n') {
  return;
 }
 rcpr();
 putchar(c);
 return;
}

void main(void)
{
 while(1)
 {
  rcpr();
  printf("\n");
 }
}
