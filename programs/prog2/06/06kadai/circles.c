#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "ColoredCircle.h"  /* 課題で使うヘッダファイル */
 
#define MAX_NUM_CIRCLES 1024            /* 読み込み可能な円の数の最大値 */
#define CIRCLES_FILENAME "circles.txt"  /* 読み込み/書き出し先のファイル名 */
 
#ifndef M_PI
#define M_PI 3.141592653
#endif
 
int g_NumCircles = 0;                   /* 円の数 */
ColoredCircle g_ColoredCircles[MAX_NUM_CIRCLES];    /* 円の配列 */
 
int g_WindowWidth = 256;    /* ウィンドウの横幅 */
int g_WindowHeight = 256;   /* ウィンドウの縦幅 */
 
/* 円を描画する関数 */
/* 中心点の座標が (xi,yi), 半径が radius, 色が (r,g,b) で与えられるものとする */
void drawCircle(int xi, int yi, int radius, unsigned char r, unsigned char g, unsigned char b)
{
    const int num_division = 64;
    int i;
 
    glColor3ub(r,g,b);
 
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(xi,yi);
    for (i=0; i<=num_division; i++)
    {
        const float rad = i * (2*M_PI) / (float)num_division;
        const float x = radius * cosf(rad) + xi;
        const float y = radius * sinf(rad) + yi;
        glVertex2f(x,y);
    }
    glEnd();
}
 
/* 表示処理のためのコールバック関数 */
void display(void)
{
    int i;
 
    glClearColor(1.0, 1.0, 1.0, 1.0);   /* ウィンドウを消去するときの色を設定 */
    /* ウィンドウを消去 … glClearColor で指定した色で塗りつぶし */
    glClear(GL_COLOR_BUFFER_BIT);
 
    /* for 文で円の個数だけ drawCircle 関数を呼び出して円を描画。自分で実装 */
    for(i=0; i<g_NumCircles; i++){
      drawCircle(g_ColoredCircles[i].xi, g_ColoredCircles[i].yi, g_ColoredCircles[i].radius, g_ColoredCircles[i].r, g_ColoredCircles[i].g, g_ColoredCircles[i].b);
    }
 
    glutSwapBuffers();  /* ここまで指定した描画命令をウィンドウに反映 */
}
 
/* キーボード入力のためのコールバック関数 */
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ' ':   /* スペースキーを押すと円をクリア */
        g_NumCircles = 0;
        printf("Circles cleared\n");
        break;
    case 's':   /* 's' を押すとファイルに円のデータを書き込み */
        /* 円のデータをファイルに保存する次の関数を自分で実装 */
        SaveColoredCircles(CIRCLES_FILENAME, g_NumCircles, g_ColoredCircles);
        printf("Circles saved in \"%s\"\n", CIRCLES_FILENAME);
        break;
    case 'l':   /* 'l' (エル) を押すとファイルから円のデータを読み込み */
        /* 円のデータをファイルから読み込む次の関数を自分で実装 */
        LoadColoredCircles(CIRCLES_FILENAME, &g_NumCircles, g_ColoredCircles);
        printf("Circles loaded from \"%s\"\n", CIRCLES_FILENAME);
        break;
    case 'q':   /* キーボードの 'q' 'Q' 'ESC' を押すとプログラム終了 */
    case 'Q':
    case '\033':
        exit(-1);
        break;
    }
 
    glutPostRedisplay();    /* ウィンドウ描画関数を呼ぶ */
}
 
/* マウス入力のためのコールバック関数 */
void mouse(int button, int state, int x, int _y)
{
    int y = g_WindowHeight - _y;
 
    if (state == GLUT_DOWN) /* もしマウスのボタンがクリックされたら */
    {
        unsigned char r = rand() % 256;
        unsigned char g = rand() % 256;
        unsigned char b = rand() % 256;
 
        int radius = 5 + rand() % 16; /* 半径を 5 以上 20 以下に設定 */
 
        if ( g_NumCircles < MAX_NUM_CIRCLES )
        {
            /* 円のデータを設定する次の関数を自分で実装 */
            SetColoredCircle(&g_ColoredCircles[g_NumCircles++], x, y, radius, r, g, b);
            printf("added circle at (%d,%d), radius = %d, color = (%d,%d,%d)\n", x, y, radius, r, g, b);
        }
    }
 
    glutPostRedisplay();    /* ウィンドウ描画関数を呼ぶ */
}
 
/* ウィンドウサイズが変更されたときのためのコールバック関数 */
void reshape(int w, int h)
{
    if (h < 1) return;
 
    g_WindowWidth = w;
    g_WindowHeight = h;
 
    glViewport(0, 0, w, h); /* ウィンドウの描画範囲を指定 */
 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
 
    glutPostRedisplay();    /* ウィンドウ描画関数を呼ぶ */
}
 
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(g_WindowWidth, g_WindowHeight);
    glutCreateWindow("Polka dots");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
