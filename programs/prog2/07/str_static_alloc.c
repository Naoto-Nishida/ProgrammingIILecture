#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define BUFSIZE 256

typedef struct Person{
  char Name[BUFSIZE];
  int birth;
} Person;

void SetPerson(Person *person, char buf[], char name[]){
  strcpy(person->Name, name);
  person->birth = atoi(buf);
}

void PrintPerson(Person *person){
  printf("the name: %s\nthe birth year: %d\n", person->Name, person->birth);
}
 
int main(void)
{
  Person person[3];
  char buf[BUFSIZE][3];
  char name[BUFSIZE][3];
  int birth[3];

  for(int i=0; i<3; i++){ 
    printf("Input your name => ");
    fgets(&name[0][i], BUFSIZE, stdin);
 
    //name[strlen(&name[0][i])-1][i] = '\0';
 
    printf("Input your birth year => ");
    fgets(&buf[0][i], BUFSIZE, stdin);
 
    // birth[i] = atoi(&buf[0][i]);
 
    putchar('\n');
    //printf("Your name: %s\n", &name[0][i]);
    //printf("Your birth year: %d\n", birth[i]);

    // printf("the bites of name memory: %lu\n", sizeof(&name[0][i]));
    SetPerson(&person[i], &buf[0][i], &name[0][i]);
    PrintPerson(&person[i]);
    printf("\n##################\n");
  }
    
 
    return 0;
}
