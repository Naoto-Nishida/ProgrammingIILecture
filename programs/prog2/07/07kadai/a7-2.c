#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerB.h"

int main(){
  Matrix mat, mat2;
  Vector vec, vec2;
  int _rows, _cols, _n;

  printf("how's the scale of the matrix?: ");
  scanf("%d", &_rows);
  scanf("%d", &_cols);

  mat.rows = _rows;
  mat.cols = _cols;  


  AllocateMatrix(&mat, _rows, _cols);

  printf("input the matrix's elements : ");
  for(int i=0; i<(_rows)*(_cols); i++){
    scanf("%lf", (mat.elems + i)); 
  }

  CopyMatrix(&mat, &mat2);
  printf("\nmatrix A: \n");
  FprintMatrix(stdout, &mat);
//  FprintMatrix(stdout, &mat2);



  printf("\n\nhow's the scale of the vector?: ");
  scanf("%d", &_n);

  AllocateVector(&vec, _n);

  printf("input the vector's elements : \n");
  for(int i=0; i<_n; i++){
    scanf("%lf", (vec.elems +i));
  }
//printf("aa");
  CopyVector(&vec, &vec2);
//printf("ii");
//printf("######%d######", _n);
//printf("%d %d:" vec.n, vec2.n);
printf("\nvector B: \n");
  FprintVector(stdout, &vec);
//  FprintVector(stdout, &vec2);
//printf("uu");
  MultMatrixVector(&mat, &vec, &vec2);
  
  printf("\n\nAxB :\n");
  FprintVector(stdout, &vec2);
  printf("\n");

  ReleaseMatrix(&mat);
  ReleaseMatrix(&mat2);
  ReleaseVector(&vec);
  ReleaseVector(&vec2);

  return 0;
}
