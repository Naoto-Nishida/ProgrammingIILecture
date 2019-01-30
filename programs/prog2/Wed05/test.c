#include <stdio.h>

double average1(int i, double str[]);
void average2(int i, double str[], double *a);

int main(){
  double str[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int i=10;
  double d,*a;
  a=&d;

  printf("%lf\n", average1(i, str));

  average2(i, str, a);

  printf("%lf\n", *a);


  return 0;

}

double average1(int i, double str[]){
  int j;
  double sum=0;
  
  for(j=0; j<i; j++){
    sum+=str[j];
  }
  return sum / i;

}

void average2(int i, double str[], double *a){
  int j;
  double sum=0;

  for(j=0; j<i; j++){
    sum += str[j];
  }

  *a = sum / i;
  

}
