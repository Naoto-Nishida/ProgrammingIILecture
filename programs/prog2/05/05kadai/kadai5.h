#ifndef __COUNTER_H__
#define __COUNTER_H__
 
extern int load_pgm(const char *filename, int *w, int *h, unsigned char *buf);
extern int save_pgm(const char *filename, int w, int h, unsigned char *buf);
extern int load_ppm(const char *filename, int *w, int *h, unsigned char *buf);
extern int save_ppm(const char *filename, int w, int h, unsigned char *buf);

void color2gray(int w, int h, unsigned char *colorBuf, unsigned char *grayBuf);
void gray2sepia(int w, int h, unsigned char *grayBuf, unsigned char *sepiaBuf);
void gray_negapos(int w, int h, unsigned char *posBuf, unsigned char *negBuf);

void gray2reverse(int w, int h, unsigned char *grayBuf, unsigned char *revBuf);
void gray2mosaic(int w, int h, unsigned char *grayBuf, unsigned char *mosaicBuf);
void black2yellow(int w, int h, unsigned char *colorBuf, unsigned char *b2yBuf);
#endif
