#include <stdio.h>
#include <stdlib.h>
 
#define N 5
 
int descending_cmp(const void *a, const void *b);
int ascending_cmp(const void *a, const void *b);
void print_array(int n, int a[]);
 
int main(void)
{
    int i;
    int A[N] = { 4, -3, 5, 1, 2 };
 
    printf("input array:\n");
    print_array(N, A);
    putchar('\n');
 
    qsort(A, N, sizeof(int), descending_cmp);
     
    printf("descending order:\n");
    print_array(N, A);
    putchar('\n');
 
    qsort(A, N, sizeof(int), ascending_cmp);
 
    printf("ascending order:\n");
    print_array(N, A);
 
    return 0;
}
 
 /* 降順、つまり徐々に値が小さくなるように並べ替えるための比較関数 */
int descending_cmp(const void *a, const void *b)
{
    /* 実際のデータ型である int にキャスト */
    int aInt = *(int *)a;
    int bInt = *(int *)b;
 
    /* bInt < aInt なら負、bInt == aInt なら 0、bInt > aInt なら正 */
    return bInt - aInt;
}
 
 /* 昇順、つまり徐々に値が大きくなるように並べ替えるための比較関数 */
int ascending_cmp(const void *a, const void *b)
{
    /* 実際のデータ型である int にキャスト */
    int aInt = *(int *)a;
    int bInt = *(int *)b;
 
    /* bInt > aInt なら負、bInt == aInt なら 0、bInt < aInt なら正 */
    return aInt - bInt;
}
 
void print_array(int n, int a[])
{
    int i;
    for (i=0; i<n; i++)
        printf("a[%d] = %d\n", i, a[i]);
}
