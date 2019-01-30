#include <stdio.h>
 
/* 共用体 */
typedef union {
    int a;
    float b;
} UnionValue;
 
/* 構造体 */
typedef struct {
    int a;
    float b;
} StructValue;
 
int main(void)
{
    printf("sizeof(UnionValue) = %ld\n", sizeof(UnionValue));
    printf("sizeof(StructValue) = %ld\n", sizeof(StructValue));
    putchar('\n');
     
    printf("sizeof(int) = %ld\n", sizeof(int));
    printf("sizeof(float) = %ld\n", sizeof(float));
     
    return 0;
}
