#include <stdio.h>
 
void readInteger(int *i)    /* この行は正しいものとする */
{
    printf("input integer: ");
    scanf("%d", i);
}
 
void writeFile(char *filename, int i)   /* この行は正しいものとする */
{
    FILE *fp = fopen(filename, "w"); /* この行は正しいものとする */
    if ( fp == NULL ) /* この行は正しいものとする */
    {
        fprintf(stderr, "Error: cannot open file: %s\n", filename); /* この行は正しいものとする */
        return;
    }
 
    fprintf(fp, "input: %d\n", i);
    fclose(fp);
}
 
int main(void)
{
    int i;    /* この行は正しいものとする */
 
    readInteger( &i );
    writeFile( "test.txt", i );
 
    return 0;
}
