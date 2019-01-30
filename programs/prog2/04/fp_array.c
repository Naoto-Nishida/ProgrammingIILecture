#include <stdio.h>
 
int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div(int x, int y);
int mod(int x, int y);
 
int main(void)
{
#ifdef MACRO
  int (*p[])(int x, int y) = { add, sub, mul };     /* 関数ポインタの配列 p を定義 */
    char op[] = { '+', '-', '*' };
#endif
    char op[] = { '+', '-', '*', '/', '%'};
    int a = 15, b = 5, ans, i;
 
    printf("0: add, 1: sub, 2: mul, 3: div, 4: mod ? ");
    scanf("%d", &i);
#ifdef MACRO
    if ((i >= 0) && (i <= 2))
    {
      printf("%d %c %d = %d\n", a, op[i], b, p[i](a, b));
      
    }
#endif
    switch(i){
    case 0:
      printf("%d %c %d = %d\n", a, op[i], b, add(a, b));
      break;
    case 1:
      printf("%d %c %d = %d\n", a, op[i], b, sub(a, b));
      break;
    case 2:
      printf("%d %c %d = %d\n", a, op[i], b, mul(a, b));
      break;
    case 3:
      printf("%d %c %d = %d\n", a, op[i], b, div(a, b));
      break;
    case 4:
      printf("%d %c %d = %d\n", a, op[i], b, mod(a, b));
      break;
    default:
      printf("iの値が不正です\n");
    }
      
    return 0;
}
 
int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }
int div(int x, int y) { return x / y; }
int mod(int x, int y) { return x % y; }
