#include <stdio.h>
#include <math.h>
#include "ColoredCircle.h"

extern void drawCircle(int xi, int yi, int radius, unsigned char r, unsigned char g, unsigned char b);
extern void display(void);


void SetColoredCircle(ColoredCircle *c, int xi, int yi, int radius, unsigned char r, unsigned char g, unsigned char b){
  c->xi = xi;
  c->yi = yi;
  c->radius = radius;
  c->r = r;
  c->g = g;
  c->b = b;
}


int SaveColoredCircles(const char *filename, int n, ColoredCircle circles[]){
  FILE *fp;
  int i, printok;
  
  if ((fp = fopen(filename, "w")) == NULL) {
    fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
    return 0;
  }

  for(i=0; i < n; i++){
    printok = fprintf(fp, "position:(%d, %d) radius:%d color(%d, %d, %d)\n", circles[i].xi, circles[i].yi, circles[i].radius, (int)circles[i].r, (int)circles[i].g, (int)circles[i].b);
      if ( printok < 0 ) {
        fprintf(stderr, "[%d]ファイルの書込みに失敗しました.\n", i);
        fclose(fp);
        return 0;
      }
  }
  
  fclose(fp);
  return 1;
}

int LoadColoredCircles(const char *filename, int *n, ColoredCircle circles[]){
  FILE *fp;
  int i=0, R, G, B;

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
    return 0;
  }


  while(fscanf(fp, "position:(%d, %d) radius:%d color(%d, %d, %d)\n", &circles[i].xi, &circles[i].yi, &circles[i].radius, &R, &G, &B) != EOF){
    circles[i].r = (unsigned char)R;
    circles[i].g = (unsigned char)G;
    circles[i].b = (unsigned char)B;
    i++;
    (*n)++;
  }


  fclose(fp);
  return 1;

}
