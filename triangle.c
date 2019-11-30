#include <stdio.h>
void main()
{
int j,i,k;

k=0;

 for(j=14;j>=1;j--)
{
 for(i=1;i<=j;i++)
  {
    k=k+1;
    if (k > 200) break;
   // printf("%5d ",k);
    printf("pink puppy ");
  }
  printf("\n");
  if (k>200) break;
}

}
