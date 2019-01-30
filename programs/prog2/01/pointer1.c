#include <stdio.h>
 
int main(void)
{
        int a = 3;
        int *p; /* ポインタの宣言 */
 
        p = &a; /* 変数 a のアドレスを代入*/
 
        printf("変数 a のアドレス: %p\n", &a);
        printf("ポインタ p の値: %p\n\n", p);
 
        printf("変数 a の値 (間接参照前): %d\n", a);
 
        *p = 10;        /* ポインタの間接参照 */
 
        printf("変数 a の値 (間接参照後): %d\n", a);
 
        return 0;
}
