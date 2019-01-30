#include <stdio.h>
 
typedef union {
        unsigned int a;
        unsigned char b[4];
} Integer;
 
int main(void)
{
        Integer v;
 
        printf("sizeof(Integer) = %d\n", sizeof(Integer));
        putchar('\n');
 
        v.a = 3;
        printf("int: %d\n", v.a);
        printf("hex: 0x%x\n", v.a);
        printf("hex: 0x%x %x %x %x\n", v.b[0], v.b[1], v.b[2], v.b[3]);
        putchar('\n');
 
        v.a = 256;
        printf("int: %d\n", v.a);
        printf("hex: 0x%x\n", v.a);
        printf("hex: 0x%x %x %x %x\n", v.b[0], v.b[1], v.b[2], v.b[3]);
        putchar('\n');
 
        v.a = 1000;
        printf("int: %d\n", v.a);
        printf("hex: 0x%x\n", v.a);
        printf("hex: 0x%x %x %x %x\n", v.b[0], v.b[1], v.b[2], v.b[3]);
        putchar('\n');
 
        v.a = 10000;
        printf("int: %d\n", v.a);
        printf("hex: 0x%x\n", v.a);
        printf("hex: 0x%x %x %x %x\n", v.b[0], v.b[1], v.b[2], v.b[3]);
        putchar('\n');
 
        return 0;
}
