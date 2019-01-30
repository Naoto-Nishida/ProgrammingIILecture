#include <stdio.h>

void AddAndMul(int a, int b, int *sum, int *mul);

int main(){
  int sum, mul, a, b;

  printf("Input two integers:");
  scanf("%d %d", &a, &b);
  
  AddAndMul(a, b, &sum, &mul);

  printf("sum is %d \n multiple is %d", sum, mul);
  

  return 0;
}

void AddAndMul(int a, int b, int *sum, int *mul){
  *sum = a+b;
  *mul = a*b;
}


