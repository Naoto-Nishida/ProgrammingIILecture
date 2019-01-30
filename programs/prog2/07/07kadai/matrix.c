#include "headerB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int AllocateMatrix(Matrix *mat, int rows, int cols){
  if((mat->elems = (double *)malloc(sizeof(double)*rows*cols + 1)) == NULL){
    printf("can't secure the memory.\n");
    return 0;
  }

  mat->rows = rows;
  mat->cols = cols;

  return 1;
}

void ReleaseMatrix(Matrix *mat){
  free(mat->elems);
}

void CopyMatrix(Matrix *inMat, Matrix *outMat){

  if((outMat->elems = (double *)malloc(sizeof(double)*(inMat->rows)*(inMat->cols))) == NULL){
    printf("can't secure the memory.\n");
    exit(1);
  }

  outMat->rows = inMat->rows;
  outMat->cols = inMat->cols;

  memcpy(outMat->elems, inMat->elems, sizeof(double)*(inMat->rows)*(inMat->cols));
}


void FprintMatrix(FILE *fp, Matrix *mat){
  int _rows = mat->rows;
  int _cols = mat->cols;

  for(int i=0; i<(_rows); i++){
    for(int j=0; j<(_cols); j++){
      fprintf(fp, "%lf ", *(mat->elems+j+i*(_cols)));
    }
    fprintf(fp, "\n");
  }

}
