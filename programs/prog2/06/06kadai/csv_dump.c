#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"

int main(int argc, char *argv[]){
  QuizData0 quiz[NUMQUIZ];
  int i=0, num;
  FILE *fp;
  

  if((fp = fopen(argv[1], "rb")) == NULL){
    printf("File couldn't be opened.\n");
    return -1;
  }
  
  
  if(argc != 2){
    printf("FUCK YOU\n you've made a wrong command.\n");
    return -1;
  }

  while(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", quiz[i].question, quiz[i].item1, quiz[i].item2, quiz[i].item3, quiz[i].item4, quiz[i].item5) != EOF){
    i++;
  }
  i--;
  num = i;

  for(i=0; i<num; i++){
    fprintf(stdout, "%d: %s\n  %s %s %s %s %s\n", i, quiz[i].question, quiz[i].item1, quiz[i].item2, quiz[i].item3, quiz[i].item4, quiz[i].item5);
  }
    
  fclose(fp);
  return 0;
}


