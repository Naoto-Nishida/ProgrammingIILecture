#ifndef HEAD
#define HEAD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[32];
  int no;
} Data;

typedef struct _node{
  Data data;
  struct _node *next;
} Node;

typedef struct {
  Node *head;
  Node *tail;
} LinkedList;
/*
enum command{
  display,
  add,
  del,
  clear,
  find,
  save,
  load,
  bye
  };*/

void PrintData(LinkedList *list);

void AddData(LinkedList *list, Node *node);

void DeleteData(LinkedList *list);

void ClearData(LinkedList *list);

void FindData(LinkedList *list, char *name);

void SaveData(LinkedList *list, char *filename);

void LoadData(LinkedList *list, char *filename);

void ListInit(LinkedList *list);

Node *CreateNode(int no, const char *name);

#endif
