#include <stdio.h>
 
#define OUTPUT_FILE "binary_sample.bin"
 
int main(void)
{
    char text[] = "This is a test message.";
    int val = 124356;
    double pi = 3.141592653;
    char str[] = "abcd";
    unsigned char data[] = { 35, 57, 97, 122, 123 }; 
 
    FILE *fout;
    int i;
 
    fout = fopen(OUTPUT_FILE, "wb");
    if (fout == NULL)
    {
        fprintf(stderr, "Error: cannot open file: %s\n", OUTPUT_FILE);
        return -1;
    }
 
    fprintf(fout, "%s\n", text);
    fwrite(&val, sizeof(int), 1, fout);
    fwrite(&pi, sizeof(double), 1, fout);
    fwrite(str, sizeof(char), 4, fout);
    fwrite(data, sizeof(unsigned char), 5, fout);
 
    fclose(fout);
     
    return 0;
}
