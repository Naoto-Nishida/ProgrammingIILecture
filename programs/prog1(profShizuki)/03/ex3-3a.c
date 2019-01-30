#include <stdio.h>

int main(void){
  int year, ad;
  char gengo;

  printf("H:平成, S:昭和, T:大正\n");
  scanf("%d%c", &year, &gengo);

  switch (gengo){
  case 'H':
    ad = year+1988;
    break;
  case 'S':
    ad = year+1925;
    break;
  case 'T':
    ad = year+1911;
    break;
  default:
    ad = year;
    break;
  }

  printf("西暦%d年\n", ad);
  printf("平成%d年\n", ad-1988);

  return 0;
}
    
