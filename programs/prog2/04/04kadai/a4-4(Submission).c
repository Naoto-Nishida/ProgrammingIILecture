#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>




void display(void)
{
  int i;

  glClear(GL_COLOR_BUFFER_BIT);	

  glFlush();

}

void resize(int w, int h)
{
  /* ウィンドウ全体をビューポートにする */
  glViewport(0, 0, w, h);

  /* 変換行列の初期化 */
  glLoadIdentity();


  /* スクリーン上の座標系をマウスの座標系に一致させる */
  glOrtho(-0.5, (GLdouble)w - 0.5, (GLdouble)h - 0.5, -0.5, -1.0, 1.0);

}

void mouse(int button, int state, int x, int y)
{

 static int x0=1, y0=1;

  switch (button) {
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN) {
      /* ボタンを押した位置から離した位置まで線を引く */
      glColor3d(1.0, 1.0, 1.0);
      glBegin(GL_LINES);
      glVertex2i(210, 120); //center(160, 120)
      glVertex2i(110, 120);
      glVertex2i(185, 78);
      glVertex2i(135, 163);
      glVertex2i(185, 163);
      glVertex2i(135, 78);
      glEnd();
      glFlush();
    }
    else {
    }
    break;
  case GLUT_MIDDLE_BUTTON:
    /* 削除 */
    break;
  case GLUT_RIGHT_BUTTON:
    /* 削除 */
    break;
  default:
   
    break;
  }
}

 
void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
  case 'q':
  case 'Q':
  case '\033':  /* '\033' は ESC の ASCII コード */
    exit(0);
  case 'f':
      glColor3d(1.0, 1.0, 1.0);
      glBegin(GL_TRIANGLE_FAN);
      glVertex2i(107, 20); //center(160, 120)
      glVertex2i(107, 220);
      glVertex2i(214, 220);
      glVertex2i(264, 120);
      glVertex2i(214, 20);
      glVertex2i(107, 20);
      glEnd();
      glColor3d(0.0, 0.0, 0.0);
      glBegin(GL_QUADS);
      glVertex2i(107, 20);
      glVertex2i(204, 220);
      glVertex2i(214, 220);
      glVertex2i(117, 20);//
      glVertex2i(204, 120);
      glVertex2i(204, 220);
      glVertex2i(214, 220);
      glVertex2i(214, 120); //
      glVertex2i(107, 115);
      glVertex2i(107, 125);
      glVertex2i(264, 125);
      glVertex2i(264, 115);
      glEnd();
      glFlush();
  default:
    break;
  }
}
//多角形の作図モード以外は規定の頂点数で勝手にひとかたまりとして認識されるっぽい。

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 1.0); //背景色を途中で変えたいときはどうすれば良いんだ？？
}

int main(int argc, char *argv[])
{
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(320, 240);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  init();
  glutMainLoop();
  return 0;
}
//参考:GLUTによる「手抜き」openGL
//https://tokoik.github.io/opengl/libglut.html
