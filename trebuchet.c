#include<stdio.h>
#include<math.h>

void main(void)
{
 double M=1.8*453.592;
 double m=17.8;
 double x;
 double k=m/M;
 for(x=1;x < 10; x+=0.01)
  {
   //printf("%f %f\n",x,(-M/x+m)/(M+m*x*x));
   printf("%f %f\n",x,(M*x-m)/(M+m*x*x));
  }
 printf("l2/l1=%f\n",k*(1+sqrt(1+1./k/k/k)));
} 
