#include <stdio.h>

typedef struct{
  double x ;
  double y;
  double r;
  char color[20]; //なんかtypedef使ったら文句言われたんですけど（怒）
} Circle;

int main(){
  int i;
  Circle circle[2]; //struct使わないと文句言われたんですけど。。。
  
  for(i=0; i<2; i++){
    printf("Input x and y coordinates, radius and color of cirle\n");
    scanf("%lf %lf %lf %s", &circle[i].x, &circle[i].y, &circle[i].r, circle[i].color); //第４引数は&いらない感
  }

  putchar((int)"\n");
  
  for(i=0; i<2; i++){
    printf("Circle %d\n", i);
    printf("Coordinate = (%lf,%lf), Radius = %lf, Color = %s\n", circle[i].x, circle[i].y, circle[i].r, circle[i].color);

  }
}
