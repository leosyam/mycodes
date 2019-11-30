#include<stdio.h>
void main()
{
 int c,wc,endword,graph[10],i,j;
 for(i=0;i<10;i++)
 {
  graph[i]=0;
 }
 while ((c=getchar()) != EOF)
 {
  wc+=1;
  if (c == ' ' || c == '\'' || c == '\t' || c == '.' || c == '\n' || c == '\?' || c == ',')
  {
   endword=1;
   if (wc<12)
   {
    graph[wc-2]+=1;
   }
   else 
   {
    printf("word is too long! %d letters!\n",wc-1);
   }
   wc=0;
  }
  if(c == '\n')
  {
   for(i=0;i<10;i++)
   {
    printf("%d  ",i+1); 
    for(j=0;j<graph[i];j++)
    {
     printf(" -");
    }
   printf("\n"); 
   }
   printf("  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20\n");
   wc=0;
   for(i=0;i<10;i++)
   {
   graph[i]=0;
   }
  }
 }
}
