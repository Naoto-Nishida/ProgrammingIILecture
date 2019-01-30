#include <stdio.h>
#include "counter.h"
 
#define N 5
  
//extern int global_counter; /* アクセスするために extern 宣言 */
 
int main(void)
{
    int i;
     
//    printf("before counting: %d\n", global_counter); /* global_counter にアクセス */
 
    for (i=0; i<N; i++)
        printf("count: %d\n", counter());
  
    return 0;
}
