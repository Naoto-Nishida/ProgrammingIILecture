#ifndef __COLORED_CIRCLE_H__
#define __COLORED_CIRCLE_H__
 
typedef struct ColoredCircle {
    /* 自分で定義する。必要なのは点の座標 xi, yi, 半径 radius および色情報 r, g, b */
  int xi, yi;
  int radius;
  unsigned char r, g, b;

} ColoredCircle;
 
/* 円 c に引数で指定した値を設定 */
void SetColoredCircle(ColoredCircle *c, int xi, int yi, int radius, unsigned char r, unsigned char g, unsigned char b);
 
/* n 個の円のデータをテキストファイルに書き込み…成功すれば返り値は 1、失敗すれば 0。書き込む形式は自分で決めてよい。 */
int SaveColoredCircles(const char *filename, int n, ColoredCircle circles[]);
 
/* n 個の円のデータをテキストファイルから読み込み…成功すれば返り値は 1、失敗すれば 0。読み込む形式は自分で決めてよい。 */
int LoadColoredCircles(const char *filename, int *n, ColoredCircle circles[]);
 
#endif
