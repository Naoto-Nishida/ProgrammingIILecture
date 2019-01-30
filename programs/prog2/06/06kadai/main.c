#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"


int main(int argc, char *argv[]){
  int choice;
  FILE *fp;
  
    if((fp = fopen(argv[1], "rb")) == NULL){
    printf("File couldn't be opened.\n");
    return -1;
  }
  
  
  if(argc != 2){
    printf("FUCK YOU\n you've made a wrong command.\n");
    return -1;
  }

  printf("which function do you want to use?\n 1:csv_dump 2:five_opt_quiz 3:five_opt_quiz2\n");
  scanf("%d", &choice);

  switch(choice){
  	case 1:
  		csv_dumpex(argv[1], fp);
  		 break;
  	case 2:
  		five_opt_quizex(argv[1], fp);
  		 break;
  	case 3:
  		five_opt_quiz2ex(argv[1], fp);
  		 break;
  	default:
		break;	
}

return 0;
}
