#include <stdio.h>

void main(){
  int a, i=1;

  printf("正の整数を入力してください: ");
  scanf("%d", &a);

  if(a > 0){
    while(i<a){
      printf("%d ", i);

      i++;
    }
    printf("%d\n", i);
  }
  else{
    printf("正しい入力ではありません\n");
  }

  



}
