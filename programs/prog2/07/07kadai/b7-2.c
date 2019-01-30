#include <stdio.h>
#include <stdlib.h>
#include "headerB.h"

int LoadLinearSystem(const char *filename, Matrix *A, Vector *b);


int main(int argc, char *argv[]){
  Matrix A, A2;
  Vector b, b2, x;
  int judge, i;
  double err = 0;
  

  if(argc != 2){
    printf("wrong command,\n ./b7-2 {filename}\n");
    return 0;
  }

  if((judge = LoadLinearSystem(argv[1], &A, &b)) == 0){
    printf("どんまい\n");
    return 0;
  }
  
  printf("\nMatrix A(%d, %d)\n", A.rows, A.cols);
  FprintMatrix(stdout, &A);
  printf("\nVector b (%d)\n", b.n);
  FprintVector(stdout, &b);
  CopyVector(&b, &b2); //b2 is the copy of the original constant vector b
  CopyMatrix(&A, &A2); //A2 is the copy of the original coefficient matrix A
  
  if(SolveGaussJordan(&A, &b) == 1){
    printf("\n\nAnswer: x(%d)\n", b.n);
    for(i=0; i<(b.n); i++){
      printf("%lf ", *(b.elems + i));
      //printf("AAA!");
    } //b is now the answer vector(equals to x)
    printf("\n");
  }
  else{
    printf("SOMETHING IS WRONG!!\n");
  }
  //printf("BB!");

  
  CopyVector(&b, &x); // x is literally the answer vector

  
  MultMatrixVector(&A2, &x, &b); //now b is Ax
  //printf("CC!");

  double c[b.n];
  
  for(i=0; i<(b.n); i++){
    c[i] = (*(b.elems + i) - *(b2.elems + i));
    err += (c[i])*(c[i]);
  }
  /*
ここで以下のようにしたらコアダンプ出る。ポインタでなぜできないのか質問.
->初期化をしてないからでした本当にありがとうございました。

  double *c;

->double d;  
->*c = &d;  ここがいるねん。ゴミアドレスを参照しようとするとバグる。

  
  for(i=0; i<(b.n); i++){
   *(c+i) = (*(b.elems + i) - *(b2.elems + i));
    err += (*(c+i))*(*(c+i));
  }
  */
  
  printf("\nError: %lf\n", err);
  


  return 1;
}

