#include <stdio.h>
#include <math.h>



int main(){
  int T;
  double th;
  char *op[] = { "sin", "cos", "tan" };
  double (*p[])(double arg) = { sin, cos, tan };

  printf("0: sin, 1: cos, 2: tan ? ");
  scanf("%d", &T);

  printf("theta = ");
  scanf("%lf", &th);

  printf("%s(theta) = %lf\n", op[T], p[T](th));

  return 0;
}
