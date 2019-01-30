#ifndef WOWWOW
#define WOWWOW

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Matrix{
  int rows;
  int cols;
  double *elems;
} Matrix;

typedef struct Vector{
  int n;
  double *elems;
} Vector;


int AllocateMatrix(Matrix *mat, int rows, int cols);
void ReleaseMatrix(Matrix *mat);
void CopyMatrix(Matrix *inMat, Matrix *outMat);
void FprintMatrix(FILE *fp, Matrix *mat);

int AllocateVector(Vector *vec, int n);
void ReleaseVector(Vector *vec);
void CopyVector(Vector *inVec, Vector *outVec);
void FprintVector(FILE *fp, Vector *vec);
void MultMatrixVector(Matrix *A, Vector *V, Vector *Out);

int LoadLinearSystem(const char *filename, Matrix *A, Vector *b);
int SolveGaussJordan(Matrix *A, Vector *b);

#endif
