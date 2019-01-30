#include <stdio.h>
 
enum Order {
    FIRST,
    SECOND=10,
    THRID,
    FORTH
};
 
int main(void)
{
    printf("FIRST = %d\n", FIRST);
    printf("SECOND = %d\n", SECOND);
    printf("THRID = %d\n", THRID);
    printf("FORTH = %d\n", FORTH);
     
    return 0;
}
