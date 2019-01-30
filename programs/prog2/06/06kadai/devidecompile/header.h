#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUMQUIZ 1024
#define itemsize 5

typedef struct {
  char question[256];
  char item1[256];
  char item2[256];
  char item3[256];
  char item4[256];
  char item5[256];
} QuizData0;

typedef struct {
  char question[256];
  char item[itemsize][256];
} QuizData;

void shuffle(int ary[],int size);

int five_opt_quiz2ex(char *argv[1], FILE *fp);

int five_opt_quizex(char *argv[1], FILE *fp);

int csv_dump(char *argv[1], FILE *fp);
