#include <stdio.h>
 
double average(int n, int a[]);
int maxValue(int n, int a[]);
int minValue(int n, int a[]);

int main(void)
{
  int a[5] = { 7, 1, -3, 4, 5 };
  double ave;
  int max, min, diff;
 
    ave = average(5, a);
    max = maxValue(5, a);
    min = minValue(5, a);
    diff = max - min;
     
    printf("average of a[]: %.1lf\n", ave);
    printf("max value of a[]: %d\n", max);
    printf("min value of a[]: %d\n", min);
    printf("diff of max and min: %d\n", diff);
    
    return 0;
}
 
double average(int n, int a[])
{
    int i;
    double sum;
 
    sum = 0;
 
    for (i=0; i<n; i++){
      sum += *a++;
    }
 
    return sum / n;
}

int maxValue(int n, int a[]){
  int m=-1000, i;

  for(i=0; i<n; i++){
    if(m<a[i]){
      m=a[i];
    }
  }

  return m;
}

int minValue(int n, int a[]){
  int m=1000, i;
  
  for(i=0; i<n; i++){
      if(m>a[i]){
	m=a[i];
      }
  }

  return m;
}
