#include <stdio.h>
#define OUTPUT_FILE "text_sample.txt"
#define OUTPUT_FILE2 "binary_sample.bin"
#define MAX 200

int main(){
  int i, *val, tmp;
  char text;
  FILE *fp, *fo;
  double pi;
  char str[244];
  unsigned char data[255]; 

  //printf("-1");
  
  fp = fopen(OUTPUT_FILE, "r");
  fo=fopen(OUTPUT_FILE2, "rb");
  
  //printf("0");
  if (fp == NULL)
    {
      fprintf(stderr, "Error: cannot open file: %s\n", OUTPUT_FILE);
      return -1;
    }

  if (fo == NULL)
    {
      fprintf(stderr, "Error: cannot open file: %s\n", OUTPUT_FILE2);
      return -1;
    }
  

  fread(&text, sizeof(char), 24, fo);
  printf("%s\n", &text);
  
  fread(&val, sizeof(int), 1, fo);
  printf("%d\n", val);
  fread(&pi, sizeof(double), 1, fo);
  printf("%lf\n", pi);
  fread(str, sizeof(char), 5, fo);
  str[4] = '\0';
  printf("%s\n", &str);
  fread(data, sizeof(unsigned char), 5, fo);
  printf("%s \n", data[]);

  fclose(fp);
  fclose(fo);
  
  return 0;
}
