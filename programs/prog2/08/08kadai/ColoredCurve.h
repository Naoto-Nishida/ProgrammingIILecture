#ifndef _COLORED_CURVE_H_
#define _COLORED_CURVE_H_
 
/* 折れ線の頂点を表す構造体 */
typedef struct _point {
    /* 自分で定義する。必要なのは点の座標 xi, yi および次の点へのポインタ next */
  int xi, yi;
  struct _point *next;
} Point;
 
/* 折れ線をリスト構造として表現した構造体 */
typedef struct {
    /* 自分で定義する。必要なのはリスト構造の先頭へのポインタ head, 末尾へのポインタ tail, 色情報 r, g, b */
  Point *head;
  Point *tail;
  unsigned char r, g, b;
} ColoredCurve;
 
/* 座標 (xi, yi) に半径 radius の円を描く関数。この関数の実体 (定義) は curve.c に書いてある */
extern void DrawCircle(int xi, int yi, int radius);
 
/* 以下のすべての関数を自分で実装する */
 
/* 折れ線の頂点を表す構造体 Point のメモリを確保し、座標 xi, yi を代入して返す  */
Point *CreatePoint(int xi, int yi);
 
/* 折れ線の初期化…リスト構造の初期化と同様 */
void CurveInit(ColoredCurve *curve);
 
/* 折れ線をリスト構造として見たとき、要素 (つまり頂点) が何もなければ 1、そうでなければ 0 */
int CurveIsEmpty(ColoredCurve *curve);
 
/* 折れ線に色を設定 */
void CurveSetColor(ColoredCurve *curve, unsigned char r, unsigned char g, unsigned char b);
 
/* 折れ線を表示…各頂点も DrawCircle 関数を使って表示する */
void CurveDraw(ColoredCurve *curve);
 
/* 折れ線の末尾に頂点 (xi, yi) を追加する */
void CurveAddPoint(ColoredCurve *curve, int xi, int yi);
 
/* 座標 (xi, yi) の半径 radius 以内に頂点があれば、その頂点を折れ線から削除する */
/* 返り値は、頂点が見つかって削除されれば 1 、そうでなければ 0 */
int CurveErasePoint(ColoredCurve *curve, int xi, int yi, int radius);
 
/* 折れ線の中で確保されたメモリを解放する */
void CurveClear(ColoredCurve *curve);
 
/* 配列 curves[] に格納された n 本の折れ線のデータを、ファイル名 filename のファイルに書き込む */
/* 返り値は、ファイルへの書き込みに成功すれば 1 、失敗すれば 0 */
int CurveSaveFile(const char *filename, int n, ColoredCurve curves[]);
 
/* ファイル名 filename のファイルから、配列 curves[] に折れ線のデータを読み込む。n は折れ線の本数 */
/* 返り値は、ファイルからの読み込みに成功すれば 1 、失敗すれば 0 */
int CurveLoadFile(const char *filename, int *n, ColoredCurve curves[]);
 
#endif /* _COLORED_CURVE_H_ */
