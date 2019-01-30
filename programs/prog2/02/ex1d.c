#include <stdio.h>

int main(void)
{
    int b[2] = { 10, 20 };
    int *p;

    p = b;

    printf("p[1] = %d\n", p[1]);
    printf("p[2] = %d\n", p[2]);

    return 0;
}
