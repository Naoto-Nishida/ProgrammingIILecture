#include <stdio.h>

int main(void){
  int x, y;
  x = 10;
  y = 2;
  printf("%d / %d = %d\n", x, y, x / y);
  printf("%d %% %d = %d\n", x, y, x % y);
  printf("%d % %d = %d\n", x, y, x % y);

  printf("\"xの値は %d です\"\n", x);
  printf("\\nは改行を意味する\n");

  return 0;
}
