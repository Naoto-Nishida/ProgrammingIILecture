#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define N 5
 
int descending_cmp(const void *a, const void *b);
int ascending_cmp(const void *a, const void *b);
void print_array(int n, char *a[]);
 
int main(void)
{
    int i;
    char *A[N] = { "Red", "Green", "Blue", "Yellow", "White" };
 
    printf("input array:\n");
    print_array(N, A);
    putchar('\n');
 
    qsort(A, N, sizeof(char *), descending_cmp);
     
    printf("descending order:\n");
    print_array(N, A);
    putchar('\n');
 
    qsort(A, N, sizeof(char *), ascending_cmp);
 
    printf("ascending order:\n");
    print_array(N, A);
 
    return 0;
}
 
 /* 降順、つまり徐々に値が小さくなるように並べ替えるための比較関数 */
int descending_cmp(const void *a, const void *b)
{
    /* 実際のデータ型である int にキャスト */
    char *aInt = *(char **)a;
    char *bInt = *(char **)b;
 
    /* bInt < aInt なら負、bInt == aInt なら 0、bInt > aInt なら正 */
    return strlen(bInt) - strlen(aInt);
}
 
 /* 昇順、つまり徐々に値が大きくなるように並べ替えるための比較関数 */
int ascending_cmp(const void *a, const void *b)
{
    /* 実際のデータ型である int にキャスト */
  //    char *aInt = *(char **)a;
  // char *bInt = *(char **)b;
  char *aInt = *(*(char *)a);
  char *bInt = *(*(char *)b);
 
    /* bInt > aInt なら負、bInt == aInt なら 0、bInt < aInt なら正 */
    return (int)(strlen(aInt) - strlen(bInt));
}
 
void print_array(int n, char *a[])
{
    int i;
    for (i=0; i<n; i++)
        printf("a[%d] = %s\n", i, a[i]);
}
