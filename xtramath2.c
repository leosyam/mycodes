#include<stdio.h>
#include<time.h>
int main(void) {   
    clock_t start, end;
    double t1,t2;
    start = clock();
    t1=time(NULL);
    int i,j,c;
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++) {
            c++;
        }
    }
    sleep(5);
    end = clock();
    t2=time(NULL);
    printf("start = %d, end = %d\n", (int)start, (int)end);
    printf(" time taken:  %f\n",t2-t1);
    return 0;
}
