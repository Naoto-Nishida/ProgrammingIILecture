#ifndef WOWWOW
#define WOWWOW

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ImageData{
  int width;
  int height;
  int channels;
  unsigned char *data;
} ImageData;

int AllocateImage(ImageData *img, int _w, int _h, int _channels);
void ReleaseImage(ImageData *img);
void CopyImage(ImageData *imgIn, ImageData *imgOut);
int LoadImage(const char *filename, ImageData *img);
int SaveImage(const char *filename, ImageData *img);
void GaussianFilter(ImageData *imgIn, ImageData *imgOut);

#endif
