#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 15
void main()
{
int a,b,c,d;
int i[N];
srand(time(NULL));

for(d=0;d<N;d++)
 {
 i[d]=rand()%500+1;
 }


printf("Before:\n");
 for(d=0;d<N;d++)
 {
 printf("%d\n",i[d]);
 }

    for(d=0;d<N;d++)
    {
	for(c=0;c<N-1;c++)
	{
             if (i[c]<i[c+1])
	     {
	     a=i[c];
	     i[c]=i[c+1];
	     i[c+1]=a;
	     }



	}

    }

printf("After:\n");
  for(d=0;d<N;d++)
  {
  printf("%d\n",i[d]);
  }

}
