#include <stdio.h>

int main(void) {
  int m, n;
  int wa, sa,seki, shou, amari;

  m = 23;
  n =4;
  wa = m+n; sa = m-n;
  seki = m*n; shou = m/n;
  amari = m-n*shou;

  printf("%d\n", wa);
  printf("%d\n", sa);
  printf("%d\n", seki);
  printf("%d\n", shou);
  printf("%d\n", amari);

  return 0;
}

