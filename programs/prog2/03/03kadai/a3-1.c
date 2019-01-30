#include <stdio.h>
#include <string.h>
#define MAX 255

int main(){
  int i, j, buffer;
  char *stradress[6];
  char str[5][MAX];

  printf("Input:\n");

  for(i=0; i<5; i++){
    printf("string %d =", i+1);
    scanf("%s", str[i]);
    stradress[i]= str[i];
  }

  printf("Output:\n");

  for(i=0; i<5; i++){
    for(j=i+1; j<5; j++){
      if(strlen(stradress[i]) > strlen(stradress[j])){
	stradress[5] = stradress[i];
	stradress[i] = stradress[j];
	stradress[j] = stradress[5];
      }
    }
  }

  for(i=0; i<5; i++){
    printf("%s\n", stradress[i]);
  }
  

  return 0;
}
