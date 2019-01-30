#include <stdio.h>
#include <stdlib.h>

int CountLine(FILE *fp){
  int ch, count=0;

  while((ch = fgetc(fp)) != EOF){
    if((char)ch == '\n'){
      count++;
    }
  }
  return count;
}

int CountWord(FILE *fp){
  int ch, ch2, count=0;

  while((ch = fgetc(fp)) != EOF){
    if(!((char)ch == ' ' || (char)ch == '\t' || (char)ch == '\n')){
      ch2 = fgetc(fp);
      if((char)ch2 == ' ' || (char)ch2 == '\t' || (char)ch2 == '\n'){
        count++;
        printf("%c", (char)ch);
      }
      else if(ch2 == EOF){
        break;
      }
      fseek(fp, -1, SEEK_CUR);
    }
  }

  return count;
}

int CountByte(FILE *fp){
  int ch, count=0;

  while((ch = fgetc(fp)) != EOF){
    if((char)ch != '\0'){ //wheres null character in files??
      count++;
    }
  }

  return count;
}

int main(){
  FILE *fp;
  int line, word, byte;
  char filename[30];

  printf("Input the filename:\n");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if(fp == NULL){
    printf("file open error!\n");
    exit(1);
  }

  line = CountLine(fp);
  fseek(fp, 0, SEEK_SET);

  word = CountWord(fp);
  fseek(fp, 0, SEEK_SET);

  byte = CountByte(fp);


  printf("line = %d, word = %d, byte = %d\n", line, word, byte);

  return 0;
}
