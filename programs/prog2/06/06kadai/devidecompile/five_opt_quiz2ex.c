#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"

void shuffle(int ary[],int size)
{
    for(int i=0;i<size;i++)
    {
        int j = rand()%size;
        int t = ary[i];
        ary[i] = ary[j];
        ary[j] = t;
    }
}



int five_opt_quiz2ex(char *argv[1], FILE *fp){
  QuizData quiz[NUMQUIZ];
  int i=0, num;
  int k, j, Ans=0, count = 0, input;
  char tmp[256];
  int quiznumber[NUMQUIZ]; // for the shuffle of quizes

  while(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", quiz[i].question, quiz[i].item[0], quiz[i].item[1], quiz[i].item[2], quiz[i].item[3], quiz[i].item[4]) != EOF){
    i++;
  }
  i--;
  num = i; // num: the number of the questions

  srand(time(NULL));

  
  for(i=0; i<num; i++){
    quiznumber[i] = i;
  }
  shuffle(quiznumber, num);


  
  for(i=0; i<num; i++){
    
    for(k=0;k<itemsize;k++)
      {

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
  }


  for(i=0; i<num; i++){
    fprintf(stdout, "Q%d: %s\n  1:%s 2:%s 3:%s 4:%s 5:%s\n", i+1, quiz[quiznumber[i]].question, quiz[quiznumber[i]].item[0], quiz[quiznumber[i]].item[1], quiz[quiznumber[i]].item[2], quiz[quiznumber[i]].item[3], quiz[quiznumber[i]].item[4]);
    //printf("%d\n  A:", Ans);
    scanf("%d", &input);
    if(input != Ans){
      count++;
      printf("wrong!\n");
    }
    else{
      printf("CORRECT!\n");
    }

    if(count >= 2){
      printf("Too many wrong answers, game over...\n");
      return 0;
    }
    
    
  }

  printf("Cleared! (wrong answers: %d)\n", count);
    
  fclose(fp);
  return 0;
}
