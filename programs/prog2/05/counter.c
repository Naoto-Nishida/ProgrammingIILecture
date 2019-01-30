static int global_counter = 0;  /* static キーワードを指定 */
 
int counter(void)
{
    return ++global_counter;
}
