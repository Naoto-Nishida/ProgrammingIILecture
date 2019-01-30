#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define pi 3.14159265358979


int main(int argc, char *argv[]){
  int i, j, tri=-1;
  double th;
  char *op[] = { "-s", "-c", "-t" };
  char *sp[] = {"sin", "cos", "tan"};
  double theta;
  double (*p[])(double arg) = { sin, cos, tan };
  
  if(argc < 3){
    printf("Usage: ./trigonometric_arg -sct double [-rd]\n");
    printf(" -s: sin\n -c: cos\n -t: tan\n -r: radian (default)\n -d: degree\n");
    return 1;
  }
  
  for(i=1; i< argc; i++){
    if(strcmp(argv[i], "-d") == 0){
      if(i==1){
	theta = atof(argv[i+2]);
	th = atof(argv[i+2])*pi/180;
      }
      else if(i == 3){
	theta = atof(argv[i-1]);
	th = atof(argv[i-1])*pi/180;
      }
    }
    else if(strcmp(argv[i], "-r") == 0){
      tri = -2;
    }
    
    for(j=0; j < 3; j++){
      if(strcmp(argv[i], op[j]) == 0){
	th = atof(argv[i+1]);
	theta = atof(argv[i+1]);
	tri = j;
      }
    }
    if(tri == -1){
      printf("Error: unknown or invalid option.\n");
      printf("Usage: ./trigonometric_arg -sct double [-rd]\n");
      printf(" -s: sin\n -c: cos\n -t: tan\n -r: radian (default)\n -d: degree\n");
      return 1;
    }
  }
  
  
  printf("%s(%lf) = %lf\n", sp[tri], theta, p[tri](th));
  

return 0;
}
