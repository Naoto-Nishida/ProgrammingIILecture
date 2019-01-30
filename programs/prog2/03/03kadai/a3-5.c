#include <stdio.h>
#define MAX 255

int main(int argc, char *argv[]){
  FILE *fp1, *fp2;
  int i;
  char str[MAX];
  
  for(i=1; i<=2; i++){
    if(argv[i]== NULL){
      printf("Usage: ./a3-5 filename1 filename2 \nyou can copy a file to another file. filename1:the source(original) file\n filename2:the destination file \n");
      return 0;
    }
  }
  
  fp1 = fopen(argv[1], "r");
  if( fp1 == NULL ){
    fputs( "ファイルオープンに失敗しました。\n", stderr );
    return 1;
  }
  fp2 = fopen(argv[2], "w");
  if( fp2 == NULL ){
    fputs( "ファイルオープンに失敗しました。\n", stderr );
    return 1;
  }

  while(fgets(str, sizeof(str), fp1 ) != NULL){
    fputs(str, fp2);
    //fprintf(fp2, "\n");
  }

  fclose(fp1);
  fclose(fp2);
  return 0;
}

//this is the program which performs like the "copy" command in UNIX.
