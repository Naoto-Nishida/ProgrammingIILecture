#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUMQUIZ 1024
#define itemsize 5

typedef struct {
  char question[256];
  char item[itemsize][256];
} QuizData;



int main(int argc, char *argv[]){
  QuizData quiz[NUMQUIZ];
  int i=0, num;
  FILE *fp;
  int k, j, Ans=0;
  char tmp[256];

  // printf("e");

  if((fp = fopen(argv[1], "rb")) == NULL){
    printf("File couldn't be opened.\n");
    return -1;
  }

  //printf("d");
  
  if(argc != 2){
    printf("you've made a wrong command.\n");
    return -1;
  }

  while(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", quiz[i].question, quiz[i].item[0], quiz[i].item[1], quiz[i].item[2], quiz[i].item[3], quiz[i].item[4]) != EOF){
    i++;
  }
  i--;
  num = i; // num: the number of the questions
  // printf("c");
  //srand(time(NULL));

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
	  printf("b");
	  sleep(1);
	}
	/*	else if(j==0){
	  strcpy(tmp, quiz[i].item[k]);
	  strcpy(quiz[i].item[k], quiz[i].item[j]);
	  strcpy(quiz[i].item[j], tmp);
	  Ans = k+1;
	  printf("b");
	  sleep(1);
	  }*/
	else{
	  printf("a");
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
    //   if(i=0){
    //    fprintf(stdout, "A%d: %d\n\n", i, Ans);
      //  }
    //  else{
      fprintf(stdout, "A%d: %d\n\n", i+1, Ans);
      //  }
  }
    
  fclose(fp);
  return 0;
}
