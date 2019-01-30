#include <stdio.h>
#include <string.h>
#define MAX 255

int main(int argc, char *argv[]){
  int i;
  char str[MAX];
  FILE *fp;
  
  for(i=1; i<=2; i++){
    if(argv[i]== NULL){
      printf("Usage: ./my_grep string filename\n");
      return 0;
    }
  }

  fp = fopen(argv[2], "r");
  if( fp == NULL ){
    fputs( "ファイルオープンに失敗しました。\n", stderr );
    return 1;
  }

  i=1;
  
  while(fgets(str, sizeof(str), fp ) != NULL){
    if(strstr( str, argv[1]) != NULL){
      printf("%d: %s\n", i, str);
    }
    i++;
  }


  fclose(fp);

  return 0;
}
