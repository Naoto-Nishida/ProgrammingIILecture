#include <stdio.h>
#include <stdlib.h>
#include "header1.h"

int main(){
  char com[10];
  LinkedList list;

  ListInit(&list);
  
  
  while(1){
    printf("\n>");

    scanf("%s", com);

    if(0 == strcmp(com, "display"))
      {
	PrintData(&list);
      }
    else if(0 == strcmp(com, "add"))
      {
	int no;
	char name[256];
	if( 2 != scanf("%d %s", &no, name)){
	  printf("Input correctly mother fxxker\n");
	  exit(1);
	}
	
	AddData(&list, CreateNode(no, name));
	printf("add: no: %d, name: %s\n", no, name);
      }
    else if(0 == strcmp(com, "del"))
      {
	DeleteData(&list);
      }
    else if(0 == strcmp(com, "clear"))
      {
	ClearData(&list);
      }
    else if(0 == strcmp(com, "find"))
      {
	char name[256];
	if( 1 != scanf("%s", name)){
	  printf("Input correctly mother fxxker!\n");
	  exit(1);
	}
	FindData(&list, name);
      }
    else if(0 == strcmp(com, "save"))
      {
	char filename[256];
	if( 1 != scanf("%s", filename)){
	  printf("Input correctly mother fxxker!\n");
	  exit(1);
	}
	SaveData(&list, filename);
      }
    else if(0 == strcmp(com, "load"))
      {
	char filename[256];
	if( 1 != scanf("%s", filename)){
	  printf("Input correctly mother fxxker!\n");
	  exit(1);
	}
	LoadData(&list, filename);
      }
    else if(0 == strcmp(com, "bye"))
      {
	printf("bye!\n");
	return 0;
      }
    else{
      printf("Input a correct command!\n");
      exit(1);
    }
  }

}
    
