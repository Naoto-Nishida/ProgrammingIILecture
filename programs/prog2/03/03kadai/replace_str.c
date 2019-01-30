#include <stdio.h>
#include <string.h>
#define MAX 255

int main(int argc, char *argv[]){
  int i;
  char str[MAX];
  FILE *fp;
  char *sp;
  
  for(i=1; i<=3; i++){
    if(argv[i]== NULL){
      printf("Usage: ./replace_str string1 string2 filename\n");
      return 0;
    }
  }
  
  fp = fopen(argv[3], "r");
  if( fp == NULL ){
    fputs( "ファイルオープンに失敗しました。\n", stderr );
    return 1;
  }
  

  while(fgets(str, sizeof(str), fp ) != NULL){
    if((sp=strstr(str, argv[1])) == NULL){
      printf("%s\n", str);
    }
    else{
      for(i=0; i< strlen(str)-strlen(sp)-1; i++){
	printf("%c", *(str+i));
      }

      printf(" %s", argv[2]);

      for(i=0; strlen(sp)-strlen(argv[1])-i != 0; i++){
	printf("%c", *(sp+i+strlen(argv[1])));
      }
    }
  }
  
  fclose(fp);
  
  return 0;
  
}
