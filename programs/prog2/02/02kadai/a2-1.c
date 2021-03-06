#include <stdio.h>
 
void copyArray(int n, int inArray[], int outArray[]);
void printArray(int n, int a[]);
void reverseArray(int n, int inArray[], int outArray[]); //bの答え
 
int main(void)
{
    int a[5] = { 1, 1, 2, 3, 5 };
    int b[5];
     
    printf("array a[]:\n");
    printArray(5, a);   
 
    copyArray(5, a, b);
 
    printf("array b[]:\n");
    printArray(5, b);

    printf("reverse of a[]:\n");
    reverseArray(5, a, b);
    printArray(5, b);
 
    return 0;
}
 
void copyArray(int n, int inArray[], int outArray[])
{
  for(int i=0; i<n; i++){
    outArray[i] = inArray[i];
  }
}
 
void printArray(int n, int a[])
{
    int i;
 
    for (i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    putchar('\n');
}

void reverseArray(int n, int inArray[], int outArray[]){
  int i;
  
  for(i=0; i<n; i++){
    outArray[n-1-i]=inArray[i];
  }
}
