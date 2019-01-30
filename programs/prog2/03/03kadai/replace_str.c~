#include <stdio.h>
#include <string.h>
#define MAX 255

int main(int argc, char *argv[]){
  int i;
  char str[MAX];
  FILE *fp;
  char *sp, *head;
  
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
    //if((sp=strstr(str, argv[1])) != NULL){
      for(i=0; i < strlen(str)-strlen(sp); i++){
	//strncpy(head, str, strlen(str)-strlen(sp));
	//printf("%s", head);
	
	printf("%c", *(str+i));
	//printf("UNTI!!");
      }
      
      
      printf("%s", argv[2]);
      
      for(i=0; *(sp+i+strlen(argv[1])) != EOF ;i++){
	printf("%c", *(sp+i+strlen(argv[1])));
	
	//printf("%s\n", str);
	//}
	//}
     }
  }
    
    
    fclose(fp);
    
    return 0;
  
}
