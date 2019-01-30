#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _data{
  int no;
  char name[20];
  int score;
  struct _data *prev;
  struct _data *next;
} Data;

typedef struct {
  char expname[ 100];
  Data *head;
  Data *tail;
} Experiment;

int main(){
  int i;
  char name[5][10] ={"Atarashi", "Eisaki", "Koroyasu", "Tsukuda", "Magome"};
  int score[5] = {10, 30, 40, 20, 50};
  Data *nowplace = NULL, *tmp = NULL;
  Experiment *expe = NULL;
  char command;

  expe = (Experiment *)malloc(sizeof(Experiment));

  for(i=0; i<5; i++){
    if(i == 0){
      expe->head = (Data *)malloc(sizeof(Data));
      expe->head->prev = NULL;
      nowplace = expe->head;
    }
    else{
      nowplace->next = (Data *)malloc(sizeof(Data));
      nowplace->next->prev = nowplace;
      nowplace = nowplace->next;
    }

    nowplace->no = i+1;
    strcpy(nowplace->name, name[i]);
    nowplace->score = score[i];
    nowplace->next = NULL;
    expe->tail = nowplace;
  }

  expe->tail = nowplace;

  strcpy(expe->expname, "mast18の中でのテストスコアの比較");

  printf("Experiment name: %s\n", expe->expname);

  nowplace = expe->head;

  //printf("%d", expe->tail->score); //for debugging

  while(1){
    printf("participant no. %d\n name: %s\n score:%d\n", nowplace->no, nowplace->name, nowplace->score);

    printf("N: nextdata\nP:previousdata\nQ:quit this program\n\n");
    scanf("%c", &command);

    switch (command){
      case 'N':
      case 'n':
      if(nowplace != expe->tail){
        nowplace = nowplace->next;
      }
      break;
      case 'P':
      case 'p':
      if(nowplace != expe->head){
        nowplace = nowplace->prev;
      }
      break;
      case 'Q':
      case 'q':
      nowplace = expe->head;
      while(nowplace != NULL){
        tmp = nowplace;
        nowplace = nowplace->next;
        free(tmp);
      }
      free(expe);
      return 0;
      break;
      default:
      printf("Not allocated command.\n");
      break;

    }
   scanf("%*c");
 }  // i couldn't debug all of the program(such as when input "pp")



  return 0;
}
