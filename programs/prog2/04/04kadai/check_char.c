#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[] )
{
  int j, i=-1;
  int (*p[])(int a) = { isalpha, isdigit, islower, isupper };
  char *op[]= { "an alphabet", "a digit", "lowercase", "uppercase" };
  char *sp[]= { "-a", "-d", "-l", "-u" };
  
  if(argc == 1 || argc == 2){
    printf("Usage: ./check_char -adlu char\n");
    return 1;
  }
  else{
    for(j=0; j<4; j++){
      if(strcmp(argv[1], sp[j]) == 0){
	i = j;
      }
    }
    if(i == -1){
      printf("Error: unknown option: %s.\n", argv[1]);
      printf("Usage: ./check_char -adlu char\n");
      return 1;
    }
  }
  
  if(p[i]((int)*argv[2])){ //2つ以上の似た関数を扱うときに莫大な威力を発揮
    printf("'%s' is %s\n", argv[2], op[i]);
  }
  else{
    printf("'%s' is NOT %s\n", argv[2], op[i]);
  } 
  
  return 0;
}
