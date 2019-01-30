#include <stdio.h>
#define NUMQUIZ 3

typedef struct {
  char *question;
  char *item[5];
} QuizData;


int main(int argc, char *argv[]){
  QuizData *quiz1;
  QuizData *quiz2;
  QuizData *quiz3;
  int i;
  FILE *fp;
  

  if((fp = fopen(argv[1], "rb")) == NULL){
    printf("File couldn't be opened.\n");
    return -1;
  }
  
  
  if(argc != 2){
    printf("FUCK YOU\n you've made a wrong command.\n");
    return -1;
  }

  for(i=0; i<3; i++){
    fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", ((*quiz[i]).question), ((*quiz[i]).item[0]), ((*quiz[i]).item[1]), ((*quiz[i]).item[2]), ((*quiz[i]).item[3]), ((*quiz[i]).item[4]));
    
    fprintf(stdout, "%d: %s\n  %s %s %s %s %s\n", i, ((*quiz[i]).question), ((*quiz[i]).item[0]), ((*quiz[i]).item[1]), ((*quiz[i]).item[2]), ((*quiz[i]).item[3]), ((*quiz[i]).item[4]));
  }
    
  fclose(fp);
}

