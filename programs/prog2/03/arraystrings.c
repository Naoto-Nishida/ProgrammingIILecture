#include <stdio.h>
 
int main(void)
{
    int i;
    char *name[3] = { "first", "second", "third" };

    name[1] = name[2];
    
    /* 文字列ごとに出力 */
    for (i = 0; i < 3; i++) {
        printf("%s\n", name[i]);
    }
 
    return 0;
}
