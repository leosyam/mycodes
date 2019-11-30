#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{

int thing;
int array[10];
srand(time(NULL));



for(thing=0;thing<10;thing++)
{
	int setter,helpset;

	array[thing]=(rand()%26)+97;
	printf("%c ",array[thing]);
	//printf("\n");

	if (thing==9) 
	{
		printf("\n");
		for (setter=0;setter<10;setter++)
			{
		for(helpset=0;helpset<10;helpset++)
		{
		array[helpset]=setter;
				printf("%d ",setter);
			}
		}
	//printf("\n");

/*
int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
for(thing=0;thing<26;thing++)
int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;

*/
}

}
