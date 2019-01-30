#include <stdio.h>
#include <string.h>
//#define MACRO

int main(int argc, char *argv[]){
  int i;
  
  if(argv[1]== NULL){
    printf("Usage: ./my_command [-h name] [-s]\n  -h: say hello to 'name' \n  -s: print smiley mark\n");
  }
  else{
#ifndef MACRO
    for(i=1; i<=3; i++){
      if(strcmp(argv[i] ,"-s") == 0){
	printf("(^-^)\n");
      }
      else if(strcmp(argv[i], "-h") == 0){
	if(argv[i+1] == NULL){
	  printf("Error: missing name for \"-h\" option\n");
	  break;
	}
	if(strcmp(argv[i+1], "-s") ==0){
	  printf("Error: missing name for \"-h\" option\n");
	  break;
	}
	else{
	  printf("Hello!!%s!!\n", argv[i+1]);
	}
      }
      else{
      }
      if(argv[i+1] == NULL){
	break;
      }
    }
  }
#endif
  
#ifdef MACRO
  if(strcmp(argv[1], "-h") ==0 || strcmp(argv[3], "-h") == 0){
    printf("(^-^)\n");
  }
  else{}
  
  if(strcmp(argv[1], "-h") ==0 && (argv[2] != NULL)){
    printf("Hey, %s!!\n", argv[2]);
  }
  else if(strcmp(argv[2], "-h") ==0 && (argv[3] != NULL)){
    printf("Hey, %s!!\n", argv[3]);
  }
  else{
    printf("Error: missing name for '-h' option\n");
  }
}
//一応試行錯誤の痕を残しておく・・・。
#endif

  return 0;
}
