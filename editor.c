#include<stdio.h>

void main()
{
int i,j,k;
printf("\n");
printf("\n");
printf("I am going to write the fibunachi numbers up to 3,000!");
printf("\n");

i=0;
j=1;
k=0;
while(j<20000)
{

	k=i+k;
	printf("%d %f %f\n",k,1.0*k/j,1.0*(k+j)/k);
	printf("\n");
	i=j;
	j=k;
}
}
