#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GL/glut.h"

#include "ColoredCurve.h"   /* 課題で使うヘッダファイル */

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define MAX_NUM_CURVES 1024             /* 読み込み可能な折れ線の数の最大値 */
#define CURVES_FILENAME "curves.txt"    /* 読み込み/書き出し先のファイル名 */

ColoredCurve g_ColoredCurves[MAX_NUM_CURVES];   /* 折れ線の配列 */
int g_CurveCurrentIndex = 0;                    /* 折れ線の配列において、いま操作している折れ線のインデックス */

int g_WindowWidth = 512;    /* ウィンドウの横幅 */
int g_WindowHeight = 512;   /* ウィンドウの縦幅 */

/* 初期化処理 */
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);   /* ウィンドウを消去するときの色を設定 */
    glLineWidth(3.f);                   /* 線の太さを指定 */
    glEnable(GL_LINE_SMOOTH);           /* 線をなめらかに表示するための設定 */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
}

/* 座標 (xi, yi) に半径 radius の円を描く関数 */
void DrawCircle(int xi, int yi, int radius)
{
    int i;
    const int nDivision = 16;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(xi, yi);
    for (i=0; i<=nDivision; i++)
    {
        const double radian = 2*M_PI*(i/(double)nDivision);
        const double x = cos(radian) * radius + xi;
        const double y = sin(radian) * radius + yi;
        glVertex2d(x, y);
    }
    glEnd();
}

/* 表示処理のためのコールバック関数 */
void display(void)
{
    int i;

    /* ウィンドウを消去 … glClearColor で指定した色で塗りつぶし */
    glClear(GL_COLOR_BUFFER_BIT);

#if 1
    for (i=0; i<=g_CurveCurrentIndex; i++)
    {
        /* 折れ線を表示する次の関数を自分で実装 */
        CurveDraw(&g_ColoredCurves[i]);
    }
#else
    /* 参考: OpenGL で折れ線を描画するには次のように書く */

    glColor3ub(10, 255, 127);   // 適当な色を指定…頂点ごとに色を指定することもできる

    /* 折れ線の頂点は glBegin と glEnd の間に並べて書く */
    glBegin(GL_LINE_STRIP); // 折れ線の描画の開始
    glVertex2i(69, 421);        // 折れ線の頂点の座標を指定
    glVertex2i(418, 415);       // 折れ線の頂点の座標を指定
    glVertex2i(252, 329);       // 折れ線の頂点の座標を指定
    glVertex2i(271, 167);       // 折れ線の頂点の座標を指定
    glVertex2i(150, 37);        // 折れ線の頂点の座標を指定
    glEnd();        // 折れ線の描画の終了

    /* 頂点に半径 5 の円を表示 */
    /* DrawCircle は glBegin() ... glEnd() の間に入れてはいけない */
    DrawCircle(69, 421, 5);
    DrawCircle(418, 415, 5);
    DrawCircle(252, 329, 5);
    DrawCircle(271, 167, 5);
    DrawCircle(150, 37, 5);

    /*********************************************************/
#endif

    glFlush();  /* ここまで指定した描画命令をウィンドウに反映 */
}

/* キーボード入力のためのコールバック関数 */
void keyboard(unsigned char key, int x, int y)
{
    int i, nCurves;

    switch (key)
    {
    case ' ':   /* スペースキーを押すと点をクリア */
        for (i=0; i<=g_CurveCurrentIndex; i++)
        {
            CurveClear(&g_ColoredCurves[i]);
        }

        g_CurveCurrentIndex = 0;

        printf("curves cleared\n");
        break;
    case 's':   /* 's' を押すとファイルに折れ線データを書き込み */
        /* 折れ線データをファイルに保存する次の関数を自分で実装 */
        if ( CurveSaveFile(CURVES_FILENAME, g_CurveCurrentIndex+1, g_ColoredCurves) )
        {
            printf("%d curves saved in \"%s\"\n", g_CurveCurrentIndex+1, CURVES_FILENAME);
        }
        break;
    case 'l':   /* 'l' (エル) を押すとファイルから折れ線データを読み込み */
        /* 折れ線データをファイルから読み込む次の関数を自分で実装 */
        if ( CurveLoadFile(CURVES_FILENAME, &nCurves, g_ColoredCurves) )
        {
            g_CurveCurrentIndex = (nCurves <= 0) ? 0 : nCurves-1; //この行なにかいてあんの？？
            printf("%d curves loaded from \"%s\"\n", nCurves, CURVES_FILENAME);
        }
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
        const int isShiftPressed = glutGetModifiers() & GLUT_ACTIVE_SHIFT;
        const int isCtrlPressed = glutGetModifiers() & GLUT_ACTIVE_CTRL;

        if ( isShiftPressed ) /* マウスクリック時に Shift キーが押されていたら */
        {
            int i;

            for (i=0; i<=g_CurveCurrentIndex; i++)
            {
                /* クリックした点 (x,y) から半径 5 ピクセル以内に頂点があれば削除 */
                /* 次の関数を自分で実装する */
                if ( CurveErasePoint(&g_ColoredCurves[i], x, y, 5) )
                    break;
            }
        }
        else if ( isCtrlPressed ) /* マウスクリック時に Ctrl キーが押されていたら */
        {
            if ( g_CurveCurrentIndex < MAX_NUM_CURVES-1 )
            {
                unsigned char r = rand() % 256;
                unsigned char g = rand() % 256;
                unsigned char b = rand() % 256;

                g_CurveCurrentIndex++;

                /* 折れ線に色を設定する関数を自分で実装 */
                CurveSetColor(&g_ColoredCurves[g_CurveCurrentIndex], r, g, b);

                /* 折れ線の末尾にクリックした点を頂点として追加する関数を自分で実装 */
                CurveAddPoint(&g_ColoredCurves[g_CurveCurrentIndex], x, y);

                printf("new curve, added point at (%d,%d), color = (%d,%d,%d)\n", x, y, r, g, b);
            }
        }
        else
        {
            if ( g_CurveCurrentIndex <= MAX_NUM_CURVES-1 )
            {
                /* 折れ線に頂点がまだ登録されていないかどうかを判定する関数を自分で実装 */
                if ( CurveIsEmpty(&g_ColoredCurves[g_CurveCurrentIndex]) )
                {
                    unsigned char r = rand() % 256;
                    unsigned char g = rand() % 256;
                    unsigned char b = rand() % 256;

                    /* 折れ線に色を設定する関数を自分で実装 */
                    CurveSetColor(&g_ColoredCurves[g_CurveCurrentIndex], r, g, b);

                    /* 折れ線の末尾にクリックした点を頂点として追加する関数を自分で実装 */
                    CurveAddPoint(&g_ColoredCurves[g_CurveCurrentIndex], x, y);

                    printf("added point at (%d,%d), color = (%d,%d,%d)\n", x, y, r, g, b);
                }
                else
                {
                    /* 折れ線の末尾にクリックした点を頂点として追加する関数を自分で実装 */
                    CurveAddPoint(&g_ColoredCurves[g_CurveCurrentIndex], x, y);

                    printf("added point at (%d,%d)\n", x, y);
                }
            }
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
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(g_WindowWidth, g_WindowHeight);
    glutCreateWindow("Curves");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    return 0;
}
