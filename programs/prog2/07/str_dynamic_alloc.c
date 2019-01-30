#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define BUFSIZE 256

typedef struct Person{
  char *name;
  int birth;
} Person;

void SetPerson(Person *person, char name[], int birth){

  person->name = (char *)malloc(strlen(sizeof(name))+1);
  
  person->name = name;
  person->birth = birth;
}

void PrintPerson(Person *person){
  printf("name: %s\nbirth year: %d\n", person->name, person->birth);
}

void ReleasePersonName(Person *person){
  free(person->name);
}
  
 
int main(void)
{
    char buf[BUFSIZE];
    char *name;
    int birth;
    Person person[3];

    for(int i=0; i<3; i++){
      printf("Input your name => ");
      fgets(buf, BUFSIZE, stdin);
      
      buf[strlen(buf)-1] = '\0';
      if((name = (char *)malloc(sizeof(char)*(strlen(buf)+1))) == NULL){
	printf("ERROR!! FUCK!!\n");
      return -2;
      }
      
      //printf("the allocated memory size is %lu\n", sizeof(sizeof(char)*(strlen(buf)+1))); //!?!?!?!?!?!??!??!
      //printf("the size of buf is %lu\n", sizeof(buf));
      strcpy(name, buf);
      
      printf("Input your birth year => ");
      fgets(buf, BUFSIZE, stdin);
      
      birth = atoi(buf);
      
      SetPerson(&person[i], name, birth);
 
      putchar('\n');
      // printf("Your name: %s\n", name);
      //printf("Your birth year: %d\n", birth);
      PrintPerson(&person[i]);
      ReleasePersonName(&person[i]);

      printf("###############\n\n");
    
      
    }  
 
    //free(name); /* 動的に確保したメモリの解放 */
     
    return 0;
}
