#include <stdio.h>
 
void hoge(void)
{
        printf("This function is %s (line %d).\n", __FUNCTION__, __LINE__);
}
 
int main(void)
{
        printf("File name is %s.\n", __FILE__);
        hoge();
        return 0;
}
