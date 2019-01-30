#include <stdio.h>

void main(){
  int i, n;
  int sum, prod;

  printf("input n: ");
  scanf("%d", &n);

  sum = 0;
  prod = 1;
  for (i = 1; i <= n; i++){
    sum += i;
    prod *= i;
  }

  printf("sum from 1 to %d = %d\n", n, sum);
  printf("product from 1 to %d = %d\n", n, prod);

  
}
