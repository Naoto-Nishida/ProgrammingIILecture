#include <stdio.h>

void QuoAndRem(int a, int b, int *c, int *d);

int main(){
  int a, b, c, d;

  printf("Input two positive number:");
  scanf("%d %d", &a, &b);

  while(a<=0 || b<=0){

    printf("Input two POSITIVE number!!:");
    scanf("%d %d", &a, &b);}
  
  QuoAndRem(a, b, &c, &d);
  printf("Quotient is %d \nRemainder is %d\n", c, d);

  return 0;
}

void QuoAndRem(int a, int b, int *c, int *d){
  *c = a / b;
  *d = a % b;
}
