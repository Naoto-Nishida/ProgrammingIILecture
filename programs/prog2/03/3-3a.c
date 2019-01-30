#include <stdio.h>

int main(){
  char *name;
  int count=0;
  char str[10];
  name=str;

  printf("input a word: ");
  scanf("%s", name);

  for(count=0; ;count++){
    if(*(name+count) == '\0'){
      break;
    }
  }

  printf("%d", count);

  return 0;
}
