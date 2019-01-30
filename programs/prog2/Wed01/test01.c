#include <stdio.h>

int sum(int n);

int main(){
  int n;

  printf("Input\n");
  scanf("%d", &n);
  printf("sum of 1 to %d is %d\n", n, sum(n));

  
  return 0;
}

int sum(int n){
  int i, ans=0;
  for(i=1; i<=n; i++){
    ans += i;
  }

  return  ans;
}

