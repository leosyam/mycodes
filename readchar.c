#include<stdio.h>

void main()
{
	int c,flag;
	//c = getchar();
	//flag=(c == EOF);
	while ((c=getchar()) != EOF) {
	   // c = getchar();
	    flag=(c != EOF);
	    printf("flag (is not EOF?): %d\n",flag);
	}
        flag=(c != EOF);
        printf("flag (is not EOF?): %d\n",flag);
	putchar(c);
        printf("the value of EOF is.. %d\n",EOF);
} 
