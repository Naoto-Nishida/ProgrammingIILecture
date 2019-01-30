#include <stdio.h>
#include <string.h>
#include "kadai5.h"

void color2gray(int w, int h, unsigned char *colorBuf, unsigned char *grayBuf){

  int i, dummy=255, c;
  

    for(i=0; i<w*h; i++){
       c = 0.298912 * (double)(*(colorBuf+i*3)) + 0.586611 * (double)(*(colorBuf+i*3+1)) + 0.114478 * (double)(*(colorBuf+i*3+2));
	if(c >= 255){
	 c=255;
	}
	*(grayBuf+i) = (unsigned char)c;
    }
    
  save_pgm("sutehagegray.pgm", w, h, grayBuf);
}
void gray2sepia(int w, int h, unsigned char *grayBuf, unsigned char *sepiaBuf){
  int i, r, g, b;

  for(i=0; i<w*h; i++){
    r = (240.0/255.0)*(int)(*(grayBuf+i));
    g = (200.0/255.0)*(int)(*(grayBuf+i));
    b = (145.0/255.0)*(int)(*(grayBuf+i));
    
    *(sepiaBuf+3*i) = (unsigned char)r;
    *(sepiaBuf+3*i+1) = (unsigned char)g;
    *(sepiaBuf+3*i+2) = (unsigned char)b;
  }

  save_ppm("sutehagesepia.ppm", w, h, sepiaBuf);
}  
void gray_negapos(int w, int h, unsigned char *posBuf, unsigned char *negBuf){
  int i;

  for(i=0; i<w*h; i++){
    *(negBuf+i) = 255 - (int)(*(posBuf+i));
  }

  save_pgm("sutehagenega.pgm", w, h, negBuf);
}
