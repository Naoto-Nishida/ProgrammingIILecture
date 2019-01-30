#include <stdio.h>
 
#define N 5
 
int global_counter = 0;
 
int counter(void)
{
        return ++global_counter;
}
 
int main(void)
{
        int i;
 
        for (i=0; i<N; i++)
                printf("count: %d\n", counter());
 
        return 0;
}
