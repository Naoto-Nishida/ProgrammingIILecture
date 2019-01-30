#include <stdio.h>
 
int main(void)
{
    char str1[] = { 'm', 'a', 's', 't', '\0' }; /* "mast" と同じ */
    char str2[5];

    for(int i=0; i< 5; i++){
      str2[i] = str1[i];    
    }
      
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
 
    return 0;
}
