#include <stdio.h>
 
#define N 5
 
int *get_array(void)
{
    int a[N] = { 1, 2, 3, 4, 5 };
    return a;
}
 
int main(void)
{
    int i;
    int *p;
 
    p = get_array();
 
    for (i=0; i<N; i++)
        printf("%d ", *p++);
    putchar('\n');
 
    return 0;
}
