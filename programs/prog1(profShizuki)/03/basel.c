# include <stdio.h>
#include <math.h>

int main(void){
  int n, i;
  double r;

  scanf("%d", &n);

  r = 0;
  for(i = 1; i <= n; i++){
    r += 1.0 / i / i;
  }

  printf("n=%d\n", n);
  printf("r=%14.13f\n", r);
  printf("πの近似値=%14.1f3\n", sqrt(r*6));

  return 0;
}
