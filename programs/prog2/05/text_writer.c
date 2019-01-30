#include <stdio.h>
#include <string.h>
 
#define OUTPUT_FILE "text_sample.txt"
 
int main(void)
{
    char text[] = "This is a test message.";
    int val = 124356;
    double pi = 3.141592653;
    char str[] = "abcd";
    unsigned char data[] = { 35, 57, 97, 122, 123 }; 
 
    FILE *fout;
    int i;
 
    fout = fopen(OUTPUT_FILE, "w");
    if (fout == NULL)
    {
        fprintf(stderr, "Error: cannot open file: %s\n", OUTPUT_FILE);
        return -1;
    }
 
    fprintf(fout, "%s\n", text);
    fprintf(fout, "%d\n", val);
    fprintf(fout, "%f\n", pi);
    fprintf(fout, "%s\n", str);
 
    for (i=0; i<5; i++)
        fprintf(fout, "%d ", (int)data[i]);
    fprintf(fout, "\n");
 
    fclose(fout);
     
    return 0;
}
