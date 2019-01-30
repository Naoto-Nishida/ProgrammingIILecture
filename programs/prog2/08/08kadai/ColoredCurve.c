#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "GL/glut.h"
#include "ColoredCurve.h"

Point *CreatePoint(int xi, int yi){
  Point *n;

  n = (Point *)malloc(sizeof(Point));
  n->xi = xi;
  n->yi = yi;

  return n;
}

/* 折れ線の初期化…リスト構造の初期化と同様 */
void CurveInit(ColoredCurve *curve){
  curve->head = NULL;
  curve->tail = NULL;
  curve->r = 0;
  curve->g = 0;
  curve->b = 0;
}

/* 折れ線をリスト構造として見たとき、要素 (つまり頂点) が何もなければ 1、そうでなければ 0 */
int CurveIsEmpty(ColoredCurve *curve){
  if(curve->head == NULL){
    return 1;
  }
  else{
    return 0;
  }
}

/* 折れ線に色を設定 */
void CurveSetColor(ColoredCurve *curve, unsigned char r, unsigned char g, unsigned char b){
  curve->r = r;
  curve->g = g;
  curve->b = b;
}

/* 折れ線を表示…各頂点も DrawCircle 関数を使って表示する */
void CurveDraw(ColoredCurve *curve){
  Point *nowplace;
  unsigned char r, g, b;

  if(CurveIsEmpty(curve)){
    return;
  }

  nowplace = curve->head;

  CurveSetColor(curve, curve->r, curve->g, curve->b); 

  glColor3ub(curve->r, curve->g, curve->b);   // 適当な色を指定…頂点ごとに色を指定することもできる

  /* 折れ線の頂点は glBegin と glEnd の間に並べて書く */
  glBegin(GL_LINE_STRIP); // 折れ線の描画の開始
  while(nowplace != NULL){
    glVertex2i(nowplace->xi, nowplace->yi);
    nowplace = nowplace->next;        // 折れ線の頂点の座標を指定
  }
  glEnd();        // 折れ線の描画の終了

  nowplace = curve->head;
  /* DrawCircle は glBegin() ... glEnd() の間に入れてはいけない */
  while(nowplace != NULL){
    DrawCircle(nowplace->xi, nowplace->yi, 5); //5が半径でいいのか？
    nowplace = nowplace->next;
  }

}

/* 折れ線の末尾に頂点 (xi, yi) を追加する */
void CurveAddPoint(ColoredCurve *curve, int xi, int yi){
  if(curve->head == NULL){
    curve->head = CreatePoint(xi, yi);
    curve->tail = curve->head;
    curve->tail->next = NULL;
  }
  else{
    curve->tail->next = CreatePoint(xi, yi);
    curve->tail = curve->tail->next;
    curve->tail->next = NULL;
  }
}

/* 座標 (xi, yi) の半径 radius 以内に頂点があれば、その頂点を折れ線から削除する */
/* 返り値は、頂点が見つかって削除されれば 1 、そうでなければ 0 */
int CurveErasePoint(ColoredCurve *curve, int xi, int yi, int radius){
  Point *nowplace;

  nowplace = curve->head;
  while(nowplace != NULL){ 
    if( pow((nowplace->xi - xi), 2) + pow((nowplace->yi - yi), 2) <= pow(radius, 2)){
      break;
    }
    nowplace = nowplace->next;
  }

  if(nowplace == curve->head){
    Point *tmp;
    tmp = curve->head;
    curve->head = curve->head->next;
    free(tmp);
    return 1;
  }
  else if(nowplace == curve->tail){
    Point *nextplace;
    nextplace = curve->head->next;
    nowplace = curve->head;

    while(nextplace->next != NULL){ 
      nowplace = nextplace;
      nextplace = nextplace->next;
    }

    free(nextplace);
    nowplace->next = NULL;
    curve->tail = nowplace;

    return 1;
  }
  else if(nowplace == NULL){
    return 0;
  }
  else{
    Point *beforeplace;
    beforeplace = curve->head;

    while(beforeplace->next != nowplace){
      beforeplace = beforeplace->next;
    }
    beforeplace->next = nowplace->next;
    free(nowplace);
    return 1;
  }
}

/* 折れ線の中で確保されたメモリを解放する */
void CurveClear(ColoredCurve *curve){
  Point *p = curve->head;

  while ( p != NULL )
  {
    Point *tmp = p;  /* 現在のノードへのポインタを保存しておく */
    p = p->next; /* p を先に進める…進める前に p を解放するとリストを辿るためのポインタも失われる */
    free(tmp);      /* 現在のノードのメモリを解放する */
  }

  /* リストを初期化して、次の利用に備える */
  CurveInit(curve);


}

/* 配列 curves[] に格納された n 本の折れ線のデータを、ファイル名 filename のファイルに書き込む */
/* 返り値は、ファイルへの書き込みに成功すれば 1 、失敗すれば 0 */
int CurveSaveFile(const char *filename, int n, ColoredCurve curves[]){
  FILE *fp;
  int i;
  Point *nowplace;

  if ((fp = fopen(filename, "w")) == NULL) {
    printf("file open error!!\n");
    return 0;
  }

  fprintf(fp, "%d\n", n);

  for(i=0; i<n; i++){
    fprintf(fp, "%d:: (%d, %d, %d)\n", i, curves[i].r, curves[i].g, curves[i].b);
    nowplace = curves[i].head;

    while(nowplace != NULL){ 
      fprintf(fp, "%d:: (%d, %d)\n", i, nowplace->xi, nowplace->yi);
      nowplace = nowplace->next;
    }
    fprintf(fp, "%d:: (-1, -1)\n", i);
  }

  fclose(fp);

  return 1;

}

/* ファイル名 filename のファイルから、配列 curves[] に折れ線のデータを読み込む。n は折れ線の本数 */
/* 返り値は、ファイルからの読み込みに成功すれば 1 、失敗すれば 0 */
int CurveLoadFile(const char *filename, int *n, ColoredCurve curves[]){ 
  FILE *fp;
  Point *nowplace;
  Point *beforeplace;
  int i=0, gomi, X, Y;

  if ((fp = fopen(filename, "r")) == NULL) {
    printf("file open error!!\n");
    return 0;
  }

  fscanf(fp, "%d\n", n);

  for(i=0; i<(*n); i++){
    fscanf(fp, "%d:: (%hhu, %hhu, %hhu)\n", &gomi, &(curves[i].r), &(curves[i].g), &(curves[i].b));


    while(fscanf(fp, "%d:: (%d, %d)\n", &gomi, &X, &Y) != EOF){
      if((X != -1)  && (curves[i].head != NULL)){
        CurveAddPoint(&curves[i], X, Y);
        nowplace = nowplace->next;
      }
      else if(curves[i].head == NULL){
        CurveAddPoint(&curves[i], X, Y);
        nowplace = curves[i].head;
      }
      else{
        break;
      }
    }

    nowplace->next = NULL;
    curves[i].tail = nowplace;
  }


  fclose(fp);
  return 1;
}
