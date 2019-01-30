#include <stdio.h>
#include <stdlib.h>
#include "headerB.h"


int LoadLinearSystem(const char *filename, Matrix *A, Vector *b){
  FILE *fp;
  int _rows, _cols;
  int i, j;
  int gomi; //for fscanf("\n");

  if ((fp = fopen(filename, "r")) == NULL) {
    printf("file open error!!\n");
    return 0;
  }


  fscanf(fp, "%d %d\n", &_rows, &_cols);
  printf("LoadLinerSystem: matrix size: %dx%d\n\n", _rows, _cols);

  AllocateMatrix(A, _rows, _cols);
  AllocateVector(b, _cols);


  for(i=0; i<_rows; i++){
    for(j=0; j<_cols; j++){
      fscanf(fp, "%lf ", (A->elems+i*_cols+j));
     
    }
  }
  for(j=0; j<_cols; j++){
    fscanf(fp, "%lf ", (b->elems+j));
  }

  return 1;

}

int SolveGaussJordan(Matrix *A, Vector *b){
  int _rows = A->rows;
  int _cols = A->cols;
  int i, j, k;
  double a, c;//iは割ったり引き算する元となる行ベクトルの行の位置（基準点）
  //jは列の位置、kは割ったり引き算をする先の行ベクトルの行の位置、aはかけてひく際のかける行列の要素。cはAの対角成分で除算する際の割る数

  for(i=0; i<_rows; i++){
    c = *(A->elems+i*_cols+i);
    // deviding the i-th row's components
    for(j=i; j<_cols;j++){

      *(A->elems+i*_cols+j) /= c ;
    }
    *(b->elems + i) /= c;

    // multipy and substraction

    for(k = 0; k < _rows; k++){
      if(k != i){
	a = *(A->elems + k*_cols + i);
	for(j=0; j<_cols; j++){
	  *(A->elems+ k*_cols + j) -= (a)*(*(A->elems + i*_cols + j));
	}
	*(b->elems + k) -= (*(b->elems + i))*(a);
      }
    }

    if(i<_rows-1){
      //to judge whether the row or col are 0
      if(*(A->elems + (i+1)*_cols + (i+1)) == 0){
	printf("\ndiagonal matrix is zero...\n");
	return 0;
      }
    }
  }

  return 1;
}
