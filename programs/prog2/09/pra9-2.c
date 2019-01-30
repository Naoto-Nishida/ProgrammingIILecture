#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Data{
  char name[20];
  int score;
} data;


int main(int argc, char *argv[]){
  int i, j, n;
  FILE *fp;
  data *tmp;
  int tmpnum;
  //char namename[20];
  //int scosco;

  tmp = (data *)malloc(sizeof(data));

  if(argc != 2){
    printf("Usage: ./pra9-2 filename\n");
    return 1;
  }

  fp= fopen(argv[1], "r");
  if(fp ==NULL){
    printf("file open error!\n");
    return 1;
  }

  fscanf(fp, "%d\n", &n);

  data *person[n];

  printf("original\n");
  for(i=0; i<n; i++){
    person[i] = (data *)malloc(sizeof(data));
    fscanf(fp, "%d %s", &(person[i]->score), person[i]->name);
    printf("%d %s\n", person[i]->score, person[i]->name);
  }


  for(i = 0; i<n-1; i++){
    for(j=i; j<n; j++){
      if(person[i]->score < person[j]->score){
        strcpy(tmp->name, person[i]->name);
        strcpy(person[i]->name, person[j]->name);
        strcpy(person[j]->name, tmp->name);

        tmpnum = person[i]->score;
        person[i]->score = person[j]->score;
        person[j]->score = tmpnum;

      }
    }
  }

  printf("\nsorted\n");
  for(i=0; i<n; i++){
    printf("%d %s\n", person[i]->score, person[i]->name);
    free(person[i]);
  }
  free(tmp);

  fclose(fp);

  return 0;
}
