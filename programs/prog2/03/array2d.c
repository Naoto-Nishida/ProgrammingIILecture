#include <stdio.h>
#include <string.h>
 
int main(void)
{
    int i;
    char name[3][10] = { "first", "second", "third" };
 
    /* 文字列ごとに出力 */
    for (i = 0; i < 3; i++) {
        printf("%s\n", name[i]);

    
    }

    for(i=0; i<3; i++){
      printf("%p\n", &name[i][0]);
      printf("%p\n", name[i]);

    }

    for(i=0;i<3;i++){
      printf("%lu\n", strlen(name[i]));

    }
    
    return 0;
}
