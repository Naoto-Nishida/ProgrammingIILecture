#include <stdio.h>
 
int main(void)
{
  char *str = "Hello";
 
  printf("%s\n", str);  /* 文字列を出力 */
   
  str = "Goodbye";  /* ポインタのさす場所を変更 */
 
  printf("%s\n", str);  /* 文字列を出力 */
 
  return 0;
}
