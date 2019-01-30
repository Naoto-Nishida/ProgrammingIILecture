#include <stdio.h>
#include <stdlib.h>
#include "header1.h"

void ListInit(LinkedList *list)
{
    list->head = NULL;   /* リストの先頭を NULL に */
    list->tail = NULL;   /* リストの末尾を NULL に */
}

Node *CreateNode(int no, const char *name)
{
    Node *n = (Node *)malloc(sizeof(Node));

    if (n == NULL)
    {
        fprintf(stderr, "CreateNode: error: memory allocation failed\n");
        return NULL;
    }

    n->data.no = no;
    strcpy(n->data.name, name);

    return n;
}

void PrintData(LinkedList *list){
  Node *nowplace;
  nowplace = list->head;

  if(list->head == NULL){
    printf("(NULL)\n");
  }
  else{
    while(nowplace != NULL){

      printf("no: %d, name: %s\n", nowplace->data.no, nowplace->data.name);
      nowplace = nowplace->next;
    }
  }
}

void AddData(LinkedList *list, Node *node){

  if (list->head == NULL) /* 要素がまだないとき */
    {
      /* 要素をひとつ追加すると、それが先頭かつ末尾になる */
      list->head = node;
      node->next = NULL;
      list->tail = node;
    }
  else
    {
      list->tail->next = node;
      node->next = NULL;
      list->tail = node;
    }

}

void DeleteData(LinkedList *list){
  Node *nowplace;
  Node *nextplace;

  if(list->head == NULL){
    printf("いやリストの要素があらへんがな\n");
  }
  else if(list->head->next == NULL){
    free(list->head);
    list->tail = NULL;
    list->head = NULL;
  }
  else{
    nextplace = list->head->next;
    nowplace = list->head;

    while(nextplace->next != NULL){
      nowplace = nextplace;
      nextplace = nextplace->next;
    }

    list->tail = nowplace;
    free(nextplace);
    list->tail->next = NULL;
  }
  printf("del: tail deleted\n");
}

void ClearData(LinkedList *list)
{
    Node *p = list->head;

    while ( p != NULL )
    {
        Node *tmp = p;  /* 現在のノードへのポインタを保存しておく */
        p = p->next; /* p を先に進める…進める前に p を解放するとリストを辿るためのポインタも失われる */
        free(tmp);      /* 現在のノードのメモリを解放する */
    }

    /* リストを初期化して、次の利用に備える */
    ListInit(list);

    printf("clear: list cleared\n");
}

void FindData(LinkedList *list, char *name){
  Node *nowplace;
  int count =0;

  if(list->head == NULL){
    printf("\"%s\" not found\n", name);
  }
  else{
    nowplace = list->head;

    while(nowplace->next != NULL){
      if(strcmp(nowplace->data.name, name) == 0){
	printf("no: %d, name: %s\n", nowplace->data.no, nowplace->data.name);
	count++;
      }
      nowplace = nowplace->next;
    }
    if(count == 0){
      printf("\"%s\" not found\n", name);
    }
  }
}

void SaveData(LinkedList *list, char *filename){
  FILE *fp;
  Node *nowplace;

  if ((fp = fopen(filename, "w")) == NULL) {
    printf("file open error!!\n");
    exit(1);
  }

  nowplace = list->head;

  while(nowplace != NULL){
    fprintf(fp, "no: %d, name: %s\n", nowplace->data.no, nowplace->data.name);
    nowplace = nowplace->next;
  }

  printf("list saved in \"%s\"\n", filename);

  fclose(fp);

}

void LoadData(LinkedList *list, char *filename){
  FILE *fp;
  Node *nowplace;
  int N;
  char NAME[256];

  if ((fp = fopen(filename, "r")) == NULL) {
    printf("file open error!!\n");
    exit(1);
  }


  while(fscanf(fp, "no: %d, name: %s\n", &N, NAME) != EOF){
    if( list->head == NULL){
      AddData(list, CreateNode(N, NAME));
      nowplace = list->head;
    }
    else{

      AddData(list, CreateNode(N, NAME));
      nowplace = nowplace->next;
    }

    NAME[0] = '\0'; //初期化してる
  }

  AddData(list, CreateNode(N, NAME));

  nowplace->next = NULL;
  list->tail = nowplace;

  printf("list loaded out of \"%s\"\n", filename);

  fclose(fp);
}
