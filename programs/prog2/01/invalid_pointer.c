#include <stdio.h>
 
int *InvalidPointer(void)
{
        int a = 1;
        return &a;
}
 
int main(void)
{
        int *p;
 
        printf("*p = %d\n", *p);  /* 初期化されていないポインタを参照している */
 
        p = InvalidPointer();
 
        printf("*p = %d\n", *p);  /* 関数のローカル変数のアドレスを参照している */
 
        return 0;
}
