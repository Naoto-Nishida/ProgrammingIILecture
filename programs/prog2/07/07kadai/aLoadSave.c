#include <stdio.h>
#include <stdlib.h>
#include "headerA.h"


int LoadImage(const char *filename, ImageData *img){
  FILE *fp;
  char header[32];
  int _w, _h, _dummy;
  int is_binary = 0;
  int is_color = 0;
  int _channels;
  
  fp = fopen(filename, "rb");

  if (fp == NULL)
    {
      fprintf(stderr, "Error: cannot open file: %s\n", filename);
      return 0;
    }

  fscanf(fp, "%s", header);

  /* ヘッダが P2 (アスキーgray) なのか P5 (バイナリgray) なのかP3(ASCIIcolor)orP6(BINARYcolor)判定 */
  if ( ! (header[0] == 'P' && (header[1] == '2' || header[1] == '5' || header[1] == '3' || header[1] == '6')) )
    {
      fprintf(stderr, "Error: invalid header: %s\n", header);
      fclose(fp);
      return 0;
    }

  /* バイナリなら 1 を代入 */
  is_binary = (header[1] == '5' || header[1] == '6');

  //if it is color, 1 is gonna be input into "is_color"
  if((is_color = (header[1] == '3' || header[1] == '6'))){
    _channels = 3;
  }
  else{
    _channels = 1;
  }

  fscanf(fp, "%d %d\n", &_w, &_h);
  fscanf(fp, "%d\n", &_dummy);


  //allocate an enough amount of heap memory
  if(AllocateImage(img, _w, _h, _channels) == 0){
     printf("Can't allocate specified amount of memory\n");
  }
	

  if(is_binary){
      fread(img->data, sizeof(unsigned char), (img->channels)*_w*_h, fp);
  }
  else{
    int xi, yi;
    if(is_color){ //ascii color case
      for (yi=0; yi<_h; yi++)
        {
  	  for (xi=0; xi<_w; xi++)
	    {
	      int r, g, b;
	      int idx = 3 * (xi + _w * yi);
	      fscanf(fp, "%d %d %d", &r, &g, &b);
	      *(img->data+idx) = (unsigned char)r;
	      *(img->data+idx+1) = (unsigned char)g;
	      *(img->data+idx+2) = (unsigned char)b;
	    }
        }
    }
    else{ //ascii gray case
      for (yi=0; yi<_h; yi++)
        {
  	  for (xi=0; xi<_w; xi++)
	    {
	      int gray;
	      int idx = (xi + _w * yi);
	      fscanf(fp, "%d ", &gray);
	      *(img->data+idx) = (unsigned char)gray;
	    }
        }
    }
  }  
    return 1;
  
}
int SaveImage(const char *filename, ImageData *img){
    FILE *fp;
  int grayorcolor=5;
  
  fp = fopen(filename, "wb");

  if ( fp == NULL )
    {
      fprintf(stderr, "Error: cannot open file: %s\n", filename);
      return 0;
    }

  //P5(binarygray)orP6(binarycolor)
  if(img->channels == 3){
    grayorcolor = 6;
  }
  
  /* ヘッダを書き込み */
  fprintf(fp, "P%d\n%d %d\n255\n", grayorcolor, img->width, img->height);

  /* バイナリデータを書き込み */
  fwrite(img->data, sizeof(unsigned char), (img->channels)*(img->width)*(img->height), fp);
  
  fclose(fp);
  fprintf(stderr, "note: ppm image saved: %s\n", filename);
  return 1;
}
