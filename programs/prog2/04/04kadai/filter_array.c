#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define MAXNUMS 1000
#define FIXEDSEED 3
 
int isSquareNumber(int n);
int isPrimeNumber(int n);
int isPowerOfTwo(int n);
 
int filterIntegers(int n, int inArray[], int outArray[], int (*judge)(int n));
 
void printIntegers(int n, int a[]);
 
int main(int argc, char **argv)
{
    int inputIntegers[MAXNUMS];
    int filteredIntegers[MAXNUMS];
    int i, nIntegers, nFiltered;
 
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s num\n", argv[0]);
        return -1;
    }
 
    nIntegers = atoi(argv[1]);
     
    if (nIntegers < 0 || nIntegers > MAXNUMS)
    {
        fprintf(stderr, "Error: invalid num: %d\n", nIntegers);
        return -2;
    }
 
    srand(FIXEDSEED);
 
    /* 乱数で 1000 以下の自然数を入力 */
    for (i=0; i<nIntegers; i++)
    {
        inputIntegers[i] = 1 + rand() % 1000;
    }
 
    printf("input (%d integers):\n", nIntegers);
    printIntegers(nIntegers, inputIntegers);
    putchar('\n');
 
    nFiltered = filterIntegers(nIntegers, inputIntegers, filteredIntegers, isSquareNumber);
 
    printf("square numbers (%d integers):\n", nFiltered);
    printIntegers(nFiltered, filteredIntegers);
    putchar('\n');
 
    nFiltered = filterIntegers(nIntegers, inputIntegers, filteredIntegers, isPrimeNumber);
 
    printf("prime numbers (%d integers):\n", nFiltered);
    printIntegers(nFiltered, filteredIntegers);
    putchar('\n');
     
    nFiltered = filterIntegers(nIntegers, inputIntegers, filteredIntegers, isPowerOfTwo);
 
    printf("power of two (%d integers):\n", nFiltered);
    printIntegers(nFiltered, filteredIntegers);
 
    return 0;
}
 
int isSquareNumber(int n)
{
  int i;
  for(i=1; i*i<=n; i++){
    if(n == i*i){
      return 1;
    }
  }
  return 0;
}
 
int isPrimeNumber(int n)
{
  int i;
  for(i=2;i<(n/2+1);i++){
    if(n % i == 0){
      return 0;
    }
    
  }
  return 1;
}
 
int isPowerOfTwo(int n)
{
  int i;
  for(i=1; pow(2, i)<=n; i++){
    if(pow(2, i) == n){
      return 1;
    }
  }
  return 0;
}
 
int filterIntegers(int n, int inArray[], int outArray[], int (*judge)(int n))
{
  int i, j=0;
  for(i=0; i<n; i++){
    //    printf("inArray[%d] = %d\n", i, inArray[i]);
    if((*judge)(inArray[i]) == 1){
      outArray[j]=inArray[i];
      j++;
    }
  }
  return j;
}
 
void printIntegers(int n, int a[])
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%d", a[i]);
        if (i != (n-1)) putchar(',');
        if ((i+1) % 10 == 0) putchar('\n');
    }
    if (n % 10 != 0) putchar('\n');
}
