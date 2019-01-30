#include <stdio.h> //標準のヘッダファイルは普通pragma onceが書いてあるっぽい。
#include <string.h>
#include "kadai5.h"
#define MAX_IMAGE_SIZE 512
#define debugA
#define debugB
#define debugC
#define debugE
#define debugF



int main(int argc, char *argv[]){
  
  int w, h, dummy; //for file access
  char header[3];
  FILE *fp1;

  int i, j; // for manipulating
  unsigned char rgb[3]; //r:0 g:1 b:2

  unsigned char buf1[1000];
  unsigned char buf2[1000];// for buffer.
  unsigned char colorBuf[500000];
  unsigned char grayBuf[200000];
  unsigned char sepiaBuf[500000];
  unsigned char negBuf[200000];
  unsigned char revBuf[200000];
  unsigned char mosaicBuf[200000];
  unsigned char b2yBuf[500000];
  
#ifdef debugA
  fp1 = fopen(argv[1], "rb");
  fscanf(fp1, "%s\n%d %d\n%d\n", header, &w, &h, &dummy);

  if(fp1 == NULL){
    printf("Error: file not found.\n");
    return -1;
  }

  printf("image size: %dx%d\n", w, h);

  if(header[1] == 0 || header[1] == 1 || header[1] == 2){
    for(i=0; i<h; i++){
      for(j=0; j<w; j++){
	fscanf(fp1, "%c %c %c", &rgb[0], &rgb[1], &rgb[2]);
	printf("(%d,%d) rgb = (%d, %d, %d)\n", j, i, (unsigned int)rgb[0], (unsigned int)rgb[1], (unsigned int)rgb[2]);
      }
    }
  }
  else{
    for(i=0; i<h; i++){
      for(j=0; j<w; j++){
	fread(rgb, sizeof(unsigned char), 3, fp1);
	printf("(%d,%d) rgb = (%d, %d, %d)\n", j, i, (int)rgb[0], (int)rgb[1], (int)rgb[2]);
      }
    }
  }
#endif

#ifdef debugB
  if(load_pgm("checker4x4_ascii.pgm", &w, &h, buf1) == 1){  
    save_pgm("copyfile1.bin", w, h, buf1);
  }
  if(load_pgm("checker4x4_binary.pgm", &w, &h, buf2) == 1){  
    save_pgm("copyfile2.bin", w, h, buf2);
  }
#endif

#ifdef debugC
  if(load_ppm("color4x4_ascii.ppm", &w, &h, buf1) == 1){  
    save_ppm("copyfile3.bin", w, h, buf1);
  }
  if(load_ppm("color4x4_binary.ppm", &w, &h, buf2) == 1){  
    save_ppm("copyfile4.bin", w, h, buf2);
  }
#endif

#ifdef debugE
  if(load_ppm("sutehage.ppm", &w, &h, colorBuf) == 1){  
    color2gray(w, h, colorBuf, grayBuf);
    gray2sepia(w, h, grayBuf, sepiaBuf);
    gray_negapos(w, h, grayBuf, negBuf);
#ifdef debugF

    gray2reverse(w, h, grayBuf, revBuf);
    gray2mosaic(w, h, grayBuf, mosaicBuf);
    black2yellow(w, h, colorBuf, b2yBuf);
#endif
  }


#endif
  
  

#ifdef debugA
  fclose(fp1);
#endif
  return 0;
}



