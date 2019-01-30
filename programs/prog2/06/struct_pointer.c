#include <stdio.h>
#include <string.h>
 
/* 構造体の宣言 はじめ */
struct Student {   /* 構造体の型名 */
    /* メンバ変数: 基本の型のデータを並べたもの */
    char name[20];
    int language;
    int math;
    int english;
    double deviation;
}; /* 末尾にセミコロン「;」がつくことに注意 */
/* 構造体の宣言 おわり */
  
int main(int argc, char *argv[])
{
    struct Student shizuki;  /* 構造体変数の宣言 */
    struct Student students[10]; /* 配列も使える */
    struct Student mikawa = { "mikawa", 80, 100, 90, 62.5 };  /* 初期化はこういう書き方も OK */
      
    /* ドット演算子を使って、構造体の要素ごとにアクセス */
    strcpy(shizuki.name, "shizuki");
    shizuki.language = 80;
    shizuki.math = 100;
    shizuki.english = 90;
    shizuki.deviation = 62.5;
      
    /* 値の表示 */
    printf("name: %s\n", mikawa.name);
    printf("language: %d\n", mikawa.language);
    printf("math: %d\n", mikawa.math);
    printf("english: %d\n", mikawa.english);
    printf("deviation: %f\n", mikawa.deviation);
    putchar('\n');
  
    /* 普通の型と同じように値をコピーできる */
    students[0] = mikawa;
  
    /* 同じ値になっているか確認 */
    printf("name: %s\n", students[0].name);
    printf("language: %d\n", students[0].language);
    printf("math: %d\n", students[0].math);
    printf("english: %d\n", students[0].english);
    printf("deviation: %f\n", students[0].deviation);
  
    return 0;
}
