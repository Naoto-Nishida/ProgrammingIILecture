#include "headerB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int AllocateVector(Vector *vec, int n){
  //printf("!!!%d!1!", n);
  if((vec->elems = (double *)malloc(sizeof(double)*(n))) == NULL){
    printf("can't secure the memory.\n");
    return 0;
  }

  vec->n = n;

  return 1;
}


void ReleaseVector(Vector *vec){
  free(vec->elems);
}

void CopyVector(Vector *inVec, Vector *outVec){
  int i;
  
  if((outVec->elems = (double *)malloc(sizeof(double)*(inVec->n))) == NULL){
    printf("can't secure the memory.\n");
    exit(1);
  }

  outVec->n = inVec->n;

  //printf("##%d %lf## ", sizeof(inVec->n), *(inVec->elems));

  //memcpy(outVec->elems, inVec->elems, sizeof(double)*(inVec->n));
  //これでもできる！

  for(i=0; i<(inVec->n); i++){
    *(outVec->elems+i) = *(inVec->elems+i);
  }

}


void FprintVector(FILE *fp, Vector *vec){

  for(int i=0; i<(vec->n); i++){
    fprintf(fp, "%lf ", *(vec->elems + i));
  }
}


void MultMatrixVector(Matrix *A, Vector *V, Vector *Out){
  int _rows = A->rows;
  int _cols = A->cols;
  int i, j;

  if(_cols != V->n){
    printf("Can't multiply them!\n");
    exit(1);
  }
  
  //initialize
  for(i=0; i<(V->n); i++){
    *(Out->elems + i) = 0;
  }

  // printf("OUCH!!");
  
  /*
  for(int i=0; i<_cols ; i++){
    for(int j=0; j<_rows; j++){
      *(Out->elems +i) += (*(A->elems) +j + i*(_rows))*(*(V->elems)+j);
    }
    }*/

  for(i=0; i<_rows; i++){
    for(j=0; j<_cols; j++){
      *(Out->elems + i) += (*(A->elems+i*(_rows)+ j))*(*(V->elems + j));
    }
  }
} 
