#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"



int five_opt_quizex(char *argv[1], FILE *fp){
  QuizData quiz[NUMQUIZ];
  int i=0, num;
  int k, j, Ans=0;
  char tmp[256];

  while(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", quiz[i].question, quiz[i].item[0], quiz[i].item[1], quiz[i].item[2], quiz[i].item[3], quiz[i].item[4]) != EOF){
    i++;
  }
  i--;
  num = i; // num: the number of the questions

  for(i=0; i<num; i++){
    
    for(k=0;k<itemsize;k++)
      {
	srand(time(NULL));
	j = rand()%itemsize; // k and j are gonna be replaced to each other 
	sleep(1);
	if(k==0){
	  strcpy(tmp, quiz[i].item[k]);
	  strcpy(quiz[i].item[k], quiz[i].item[j]);
	  strcpy(quiz[i].item[j], tmp);
	  Ans = j+1;

	  sleep(1);
	}
	else{

	  strcpy(tmp, quiz[i].item[k]);
	  strcpy(quiz[i].item[k], quiz[i].item[j]);
	  strcpy(quiz[i].item[j], tmp);
	  sleep(1);
	  if(Ans == k+1){
	    Ans = j+1;
	  }
	  else if(Ans == j+1){
	    Ans = k+1;
	  }
	}
      }	
	
    fprintf(stdout, "Q%d: %s\n  1:%s 2:%s 3:%s 4:%s 5:%s\n", i+1, quiz[i].question, quiz[i].item[0], quiz[i].item[1], quiz[i].item[2], quiz[i].item[3], quiz[i].item[4]);

      fprintf(stdout, "A%d: %d\n\n", i+1, Ans);

  }
    
  fclose(fp);
  return 0;
}
