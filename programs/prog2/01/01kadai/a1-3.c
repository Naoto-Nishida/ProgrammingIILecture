#include <stdio.h>
#include <math.h>


double determinant2x2(double a, double b, double c, double d);
void mult2x2(double a0, double b0, double c0, double d0,
	     double a1, double b1, double c1, double d1,
	     double *a2, double *b2, double *c2, double *d2);
int invert2x2(double a0, double b0, double c0, double d0,
	      double *a1, double *b1, double *c1, double *d1);
int eigenvalues2x2(double a, double b, double c, double d,
		   double *lambda0, double *lambda1);
void eigenvectors2x2(double a, double b, double c, double d,
		     double e0, double e1,
                     double *v0, double *v1, double *v2, double *v3);


int main(){
  double a0, b0, c0, d0, a1, b1, c1, d1, a2, b2, c2, d2, lambda0, lambda1;
  double v0, v1, v2, v3;
  int MUSCLE; //To put in the values of returns

  printf("Input> ");
  scanf("%lf %lf %lf %lf", &a0, &b0, &c0, &d0);

  printf("matrix A:\n  %lf, %lf\n  %lf, %lf\n\n", a0, b0, c0, d0);

  printf("Input> ");
  scanf("%lf %lf %lf %lf", &a1, &b1, &c1, &d1);

  printf("matrix B:\n  %lf, %lf\n  %lf, %lf\n\n", a1, b1, c1, d1);

  
  printf("a.\ndeterminantA: %lf\n\n", determinant2x2(a0, b0, c0, d0));

  
  mult2x2(a0, b0, c0, d0, a1, b1, c1, d1, &a2, &b2, &c2, &d2);
  printf("b.\nAxB:\n  %lf, %lf\n  %lf, %lf\n\n", a2, b2, c2, d2);

  if(invert2x2(a0, b0, c0, d0, &a1, &b1, &c1, &d1) == 0){
    printf("c.\nA^-1:\n  not invertible\n");
  }
  else{
    printf("c.\nA^-1:\n  %lf, %lf\n  %lf, %lf\n\n", a1, b1, c1, d1);
    mult2x2(a0, b0, c0, d0, a1, b1, c1, d1, &a2, &b2, &c2, &d2);
    printf("A*A^-1:\n  %lf, %lf\n  %lf, %lf\n\n", a2, b2, c2, d2);
  }

  MUSCLE = eigenvalues2x2(a0, b0, c0, d0, &lambda0, &lambda1);
  printf("d.\neigenvalues of matrix A: (# of non-zero:%d)\n", MUSCLE);
  if(MUSCLE == 2){
    printf("  %lf, %lf\n\n", lambda0, lambda1);
  }
  else if(MUSCLE == 1){
    printf("  %lf\n\n", lambda0);
  }
  else{
    printf("  Eigenvalues don't exist.\n\n");
  }

  printf("e.\n");
  if(MUSCLE == 2){
    eigenvectors2x2(a0, b0, c0, d0, lambda0, lambda1, &v0, &v1, &v2, &v3);
    printf("eigenvectors:\n  (%lf, %lf), (%lf, %lf)\n\n", v0, v1, v2, v3);
  }
  else if(MUSCLE == 1){
    eigenvectors2x2(a0, b0, c0, d0, lambda0, lambda0, &v0, &v1, &v2, &v3);
    printf("eigenvectors:\n  (%lf, %lf), (%lf, %lf)\n\n", v0, v1, v2, v3);
  }
  else{
    printf("eigenvector doesn't exist.\n\n");
  }
  
  return 0;
}

double determinant2x2(double a, double b, double c, double d){
  return a*d-b*c;
}

void mult2x2(double a0, double b0, double c0, double d0,
	     double a1, double b1, double c1, double d1,
	     double *a2, double *b2, double *c2, double *d2){
  *a2 = a0*a1 + b0*c1;
  *b2 = a0*b1 + b0*d1;
  *c2 = c0*a1 + d0*c1;
  *d2 = c0*b1 + d0*d1;
}

int invert2x2(double a0, double b0, double c0, double d0,
	      double *a1, double *b1, double *c1, double *d1){
  double k= determinant2x2(a0, b0, c0, d0);

  if(k == 0){
    return 0;
  }
  else{
    *a1 = d0 / k;
    *b1 = -b0 / k;
    *c1 = -c0 / k;
    *d1 = a0 / k;
    return 1;
  }
}

int eigenvalues2x2(double a, double b, double c, double d,
		   double *lambda0, double *lambda1){
  double l = (a-d)*(a-d)+4*b*c; //This is Discriminant
  
  if(l > 0){
    *lambda0= (a+d + sqrt(l))/2;
    *lambda1= (a+d - sqrt(l))/2;

    return 2;
  }
  else if(l == 0){
    *lambda0= (a+d)/2;

    return 1;
  }
  else{
    return 0;
  }
}


void eigenvectors2x2(double a, double b, double c, double d,
		     double e0, double e1,
                     double *v0, double *v1, double *v2, double *v3){
  if(a == d && c == 0 && b == 0){
    *v0 = 1;
    *v1 = 0;
    *v2 = 1;
    *v3 = 0;
  }
  else{
    int m0 = (a-e0)*(a-e0) + b*b;
    int m1 = (a-e1)*(a-e1) + b*b;

    *v0 = b / m0; // m can't be 0 because unit vector's case was already excluded 
    *v1 = -*v0*(a-e0) / b; // b can't be 0 in this case because of the existance of eigenvectors
    *v2 = b / m1;
    *v3 = -*v1*(a-e1) / b;
  }
}  
