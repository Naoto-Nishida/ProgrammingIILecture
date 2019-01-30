#include <stdio.h>
#include <string.h>
#define MAX_IMAGE_SIZE 512

int main(int argc, char *argv[]){
  int i, j, w, h, dummy;
  //unsigned char str[sizeof(unsigned char)];
  unsigned int tmp2;
  int tmp;
  char header[3];
  FILE *fp;

  fp = fopen(argv[1],"rb");
  
  fscanf(fp, "%s\n%d %d\n%d\n", header, &w, &h, &dummy);

  if(strcmp(header, "P1") == 0 ||strcmp(header, "P2") == 0||strcmp(header, "P3") == 0){
    printf("image size: %dX%d\n", w, h);
    
    for(i=0; i<h; i++){
      for(j=0; j<w; j++){
	fscanf(fp, "%d", &tmp);
	printf("(%d,%d) gray = %d\n", j, i, tmp);
      }
    }
  }

  if(strcmp(header, "P4") == 0 ||strcmp(header, "P5") == 0||strcmp(header, "P6") == 0){
    for(i=0; i<h; i++){
      for(j=0; j<w; j++){
	fread(&tmp2, sizeof(unsigned char), 1, fp);
	printf("(%d,%d) gray = %u\n", j, i, tmp2);
      }
    }
  }


  return 0;
}
