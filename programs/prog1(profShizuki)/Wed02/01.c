#include <stdio.h>

void main(){
  double F, C;
  
  printf("PUT A TEMPERATURE IN F: ");
  scanf("%lf", &F);

  C = 5*(F-32)/9;
  printf("C=%lf\n", C);
}
