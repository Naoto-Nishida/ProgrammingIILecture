#include <stdio.h>

void main(){
  int A, B;
  
  printf("正の整数AとBを入力してください: \n");
  scanf("%d", &A);
  scanf("%d", &B);

  if((A+B) % 2 == 0){
    printf("丁\n");
  }
  else{
    printf("半\n");
  }
}
