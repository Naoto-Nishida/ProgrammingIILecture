#include <stdio.h>
#include <ctype.h>
 
int main(int argc, char *argv[] )
{
    int i;
    char c;
    int (*p[])(int a) = { isalpha, isdigit, islower, isupper };
    char *op[]= { "an alphabet", "a digit", "lowercase", "uppercase" };
 
    printf("0: isalpha, 1: isdigit, 2: islower, 3: isupper ? ");
    scanf("%d", &i);
 
    printf("char = ");
    scanf(" %c", &c);

    if(p[i]((int)c)){ //2つ以上の似た関数を扱うときに莫大な威力を発揮
      printf("'%c' is %s\n", c, op[i]);
    }
    else{
      printf("'%c' is NOT %s\n", c, op[i]);
    }
	

    
    return 0;
}
