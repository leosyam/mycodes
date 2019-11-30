#include<stdio.h>
#include<stdlib.h>
#define N 8
void main()
{
 int  i, lives, c, win, make;
 char  word[] = "optimist", progress[N];
 lives = 5;
 for(i=0;i<N;i++) progress[i]='_';
 while ((c = getchar()) != EOF ) 
 {
 if (c=='\n') continue;
 win = make = 0;
  for (i=0;i<N;i++)
  {
   if (c == word[i])
   {
    progress[i]=c;
    make = 1;
   }
   if (progress[i] == '_')
   {
    win = 1;
   }
  }
  if (make == 0)
  {
   lives = lives - 1;
   if (lives <= 0)
   {
    printf ("you loose***:( the word was ...................\n");
    exit (0);
   }
  }
  if (win == 0)
  {
   printf("you win!!!!! but watch out, the words aren't as obvious as you think they are...\n");
   exit(0);
  }
  printf("progress:\n");
  printf("lives:%d\n", lives);
  for (i=0;i<N;i++)
  {
   printf("%c", progress[i]);
  }
  printf("\n");
 }
}
