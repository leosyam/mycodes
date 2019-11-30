#include <stdio.h>
#include <time.h>
#define N 4  
void main()
{
  int answer, input;
  int n1,n2,t1,t2,rt;
  t1=(time(NULL));
  //printf("t1=%ld\n",t1);
  srand(time(NULL));
  n1=rand()%500+1;
  n2=rand()%500+1;
  answer=n1+n2;
  printf("What is %d + %d ?\n",n1,n2);
  scanf("%d",&input);
  t2=(time(NULL));
  rt=t2-t1;
  if (input==answer)
  {
   printf("You found the correct answer in %d seconds...\n",rt);
   if (rt>N)
   {
    printf("... try to go faster next time :-) \n");
   }
   else
   {
    printf(" ... Great job !\n");
   }
  }
  else
  {
   printf(" Sorry, wrong answer :-( Try again !\n");
  }
}
 
