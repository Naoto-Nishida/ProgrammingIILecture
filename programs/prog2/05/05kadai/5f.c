#include <stdio.h>
#include "kadai5.h"

void gray2reverse(int w, int h, unsigned char *grayBuf, unsigned char *revBuf){
  int i;

  for(i=0; i<w*h; i++){
    *(revBuf+i) = (*(grayBuf+w*h-i));
  }

  save_pgm("sutehagereverse.pgm", w, h, revBuf);
}

void gray2mosaic(int w, int h, unsigned char *grayBuf, unsigned char *mosaicBuf){
  int i, j, k, l, c;

  for(i=0; i<h; i=i+10){
    for(j=0; j<w; j++){
      for(k=0; k<10; k++){
	for(l=0; l<10; l++){
	  c+=(int)(*(grayBuf+j+l+k*w+i*w));
	}
	
      }
      c=c/100;
      for(k=0; k<10;k++){
	for(l=0; l<10; l++){
	  *(mosaicBuf+j+w*k+l+i*w) = (unsigned char)c;
	}
      }
    }
    // cを25とかで割ると、cが255を超えるものが出てきて面白いことになる。（金属光沢みたいな感じになる）
    //もしカラーでやるとすると単純にRGB要素をそれぞれ相加平均とったらOK
  }

  save_pgm("sutehagemosaic.pgm", w, h, mosaicBuf);
}

void black2yellow(int w, int h, unsigned char *colorBuf, unsigned char *b2yBuf){
  int i;

  for(i=0; i<w*h; i++){
    if(*(colorBuf+i*3) < 20 && *(colorBuf+i*3+1) < 20 && *(colorBuf+i*3+2) <20){
       *(b2yBuf+i*3) = 255;
       *(b2yBuf+i*3+1) = 216;
       *(b2yBuf+i*3+2) = 0;
    }
    else{
      *(b2yBuf+i*3) = (*(colorBuf+i*3));
      *(b2yBuf+i*3+1) = (*(colorBuf+i*3+1));
      *(b2yBuf+i*3+2) = (*(colorBuf+i*3+2));
    }
   }	
  save_ppm("sutehageb2y.ppm", w, h, b2yBuf);

  //become Saiyan  
}
