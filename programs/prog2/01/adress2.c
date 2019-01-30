#include <stdio.h>
 
int main(void)
{
    int a = 3, b = 5;
 
    printf("変数 a の値 ： %d\n", a);
    printf("変数 a のアドレス: %p\n", &a);
    printf("変数 b の値 ： %d\n", b);
    printf("変数 b のアドレス: %p\n", &b);
    printf("\n");
 
    a = b;
 
    printf("変数 a の値 ： %d\n", a);
    printf("変数 a のアドレス: %p\n", &a);
    printf("変数 b の値 ： %d\n", b);
    printf("変数 b のアドレス: %p\n", &b);
    printf("\n");
 
    return 0;
}
