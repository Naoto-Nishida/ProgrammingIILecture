#include <stdio.h>

int main(void){
  int score;

  printf("得点入力して: \n");
  scanf("%d", &score);

  if (score >= 60){
    printf("合格！\n");
  }
  else{
    printf("落単!wwwww\n");
  }

 
}
