#include <stdio.h>
#include <stdlib.h>
#include "GL/glut.h"
 
int g_WindowWidth = 256;
int g_WindowHeight = 256;
 
/* 描画処理用のコールバック関数を指定 */
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();  /* ダブルバッファの切り替え */
}
 
/* アイドル時 (何も入力を受け付けていない時) の処理のためのコールバック関数を指定 */
void idle(void)
{
    display();
}
 
/* キーボード入力を受け付けるコールバック関数を指定 */
void keyboard(unsigned char key, int x, int y)
{
    /* 自分で実装 */
}
 
/* マウスクリック時に呼び出されるコールバック関数 */
void mouse(int button, int state, int x, int _y)
{
    int y = g_WindowHeight - _y;
    /* 自分で実装 */
}
 
/* 画面サイズが変更されたときの処理を行うコールバック関数を指定 */
void reshape(int width, int height)
{
    g_WindowWidth = width;
    g_WindowHeight = height;
}
 
/* 自分で独自に指定した初期化処理を行う */
void init(void)
{
    glClearColor(1,1,1,1);
}
 
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);  /* GLUT の初期化 */
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); /* 各種設定 */
    glutInitWindowSize(g_WindowWidth, g_WindowHeight); /* 最初のウィンドウサイズを指定 */
    glutCreateWindow("Test"); /* ウィンドウのタイトルを指定 */
 
    glutDisplayFunc(display); /* 描画処理用のコールバック関数を指定 */
    glutIdleFunc(idle); /* アイドル時 (何も入力を受け付けていない時) の処理のためのコールバック関数を指定 */
    glutKeyboardFunc(keyboard); /* キーボード入力を受け付けるコールバック関数を指定 */
    glutMouseFunc(mouse); /* マウスがクリックされたときの処理のためのコールバック関数を指定 */
    glutReshapeFunc(reshape); /* 画面サイズが変更されたときの処理を行うコールバック関数を指定 */
 
    init(); /* 自分で独自に指定した初期化処理を行う */
 
    glutMainLoop(); /* イベント待ち受けループに入る */
 
    return 0;
}
