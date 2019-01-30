#include <stdio.h>

int main(void)
{
    int a[3] = { 3, 1, 6 };

    printf("a[1] = %d\n", a[1]);

    /* 配列名に ++ 演算子を適用 */
    a++;

    printf("a[0] = %d\n", a[0]);

    return 0;
  
}
