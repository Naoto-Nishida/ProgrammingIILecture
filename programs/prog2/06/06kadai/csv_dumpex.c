#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"

int csv_dumpex(char *argv[1], FILE *fp){
  QuizData0 quiz[NUMQUIZ];
  int i=0, num;
  
  while(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", quiz[i].question, quiz[i].item1, quiz[i].item2, quiz[i].item3, quiz[i].item4, quiz[i].item5) != EOF){
    i++;
  }
  i--;
  num = i;

  for(i=0; i<num; i++){
    fprintf(stdout, "%d: %s\n  %s %s %s %s %s\n", i, quiz[i].question, quiz[i].item1, quiz[i].item2, quiz[i].item3, quiz[i].item4, quiz[i].item5);
  }

  return 0;
}


