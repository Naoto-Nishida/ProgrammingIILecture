#include <stdio.h>
#include <stdlib.h>
#include "headerA.h"

int AllocateImage(ImageData *img, int _w, int _h, int _channels){

  if((img->data = (char *)malloc(sizeof(char)*_channels*_w*_h)) == NULL){
    return 0;
  }

  img->width = _w;
  img->height = _h;
  img->channels = _channels;

  return 1;
}

void ReleaseImage(ImageData *img){
  free(img->data);
}

void CopyImage(ImageData *imgIn, ImageData *imgOut){

  imgOut->data = (char *)malloc(sizeof(char)*(imgIn->channels)*(imgIn->width)*(imgIn->height));//error process??
  
  imgOut->width = imgIn->width;
  imgOut->height = imgIn->height;
  imgOut->channels = imgIn->channels;

  memcpy(imgOut->data, imgIn->data, sizeof(char)*(imgIn->channels)*(imgIn->width)*(imgIn->height));
}
