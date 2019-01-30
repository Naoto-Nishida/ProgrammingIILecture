#include <stdio.h>


void main(){
  double A;
  printf("正の長さA(m)を入力してください: ");
  scanf("%lf", &A);

  printf("%lf尺になります。\n", 10*A / 33);
  printf("%lf寸になります。\n", A / 33);
  printf("%lf町になります。\n", A / (33*36));
}
