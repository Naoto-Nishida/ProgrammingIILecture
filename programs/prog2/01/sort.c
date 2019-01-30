#include <stdio.h>
 
void sort(int *x, int *y);
 
int main(void)
{
    int a = 5;
    int b = 10;
 
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("\n");
 
    sort(&a, &b);
 
    printf("a = %d\n", a);
    printf("b = %d\n", b);
 
    return 0;
}
 
void sort(int *x, int *y){
  int tmp;

  if(*x<*y){
  tmp = *x;
  *x = *y;
  *y = tmp;}
}
