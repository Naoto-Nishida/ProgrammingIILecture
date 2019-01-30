#include <stdio.h>
 
#define N 5
 
int main(void)
{
    int a[N] = { 80, 60, 55, 22, 75 };
    int i, *p;
 
    printf("array access:\n");
    for(i=0; i< N; i++){
      printf("%p: a[%d] = %d\n", &a[i], i, a[i]);
    }
    putchar('\n');
 
    p = a;
 
    printf("%p: p\n\n", p);
 
    printf("pointer access:\n");
    for(i=0; i<N; i++){
      printf("%d: a[%d] = %d\n", *(a+i), i, a[i]);
    }
    return 0;
}
