#include <stdio.h>
 
enum Color {
    RED,
    BLUE,
    GREEN
};
 
int main(void)
{
    const char *colorNames[] = { "Red", "Blue", "Green" };
     
    /* インデックスに 0 を指定する代わりに RED を指定 */
    printf("Color is %s\n", colorNames[RED]);
     
    return 0;
}
