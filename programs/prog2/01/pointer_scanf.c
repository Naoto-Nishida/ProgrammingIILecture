#include <stdio.h>
 
int main(void)
{
    int n;
    int *p;
 
    p = &n;
 
    printf("input integer: ");
    scanf("%d", p); /* scanf の第 2 引数はアドレスなのでこれで OK */
     
    printf("input: %d\n", *p);
 
    return 0;
}
