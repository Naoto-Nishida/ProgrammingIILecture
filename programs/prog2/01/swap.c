#include <stdio.h>
 
void swap(int *x, int *y);
 
int main(void)
{
    int a = 5;
    int b = 10;
 
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("\n");
 
    swap(&a, &b);
 
    printf("a = %d\n", a);
    printf("b = %d\n", b);
 
    return 0;
}
 
void swap(int *x, int *y){
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}
