#include <stdio.h>
#include <string.h>

void color2gray(int w, int h, unsigned char *colorBuf, unsigned char *grayBuf);


int main(){
  unsigned char colorBuf[100];
  unsigned char grayBuf[100];
  int w=400, h=400;
  
  printf("0");
  color2gray(w, h, colorBuf, grayBuf);
  return 0;}

void color2gray(int w, int h, unsigned char *colorBuf, unsigned char *grayBuf){
  FILE *fpl;
  FILE *fps;
  char header[3];
  int i, dummy, c, count;

  fpl = fopen("color4x4_binary.ppm", "rb"); //入れたいカラー画像名を入力
  fps = fopen("sutehagegray.pgm", "wb+"); //出力先のファイル名を指定


  printf("1");
  
  if(fps == NULL){
    printf("Error: copy file missing.\n");
    return ;
  }
  if(fpl == NULL){
    printf("Error: original file missing.\n");
    return ;
  }

  count=0;
  while (1) {    // 無限ループ
    c = fgetc(fpl);     // ファイルから1バイト読み込んで c に入れる
    if (c == EOF) {           // もしファイルの終端に達していたら
      break;                  // while ループから抜け出す
    }
    count++;
  }
  
  fseek(fpl, 0, SEEK_SET);
  
  fscanf(fpl, "%s\n%d %d\n%d\n", header, &w, &h, &dummy);
  //データにwidthheights入ってるのになんで引数でwidthheightsを渡す必要があるんだろう...
   printf("%s ", header);
   printf("%d", count);
  
  fprintf(fps, "%s\n%d %d\n%d\n", header, w, h, dummy);

  if(strcmp(header, "P3") == 0){
    for(i=0; i<(count-12)/3; i++){  
      fscanf(fpl, "%d %d %d ", (int *)(colorBuf), (int *)(colorBuf+1), (int *)(colorBuf+2));
      *(double *)(grayBuf)=0.298912 * *(double *)(colorBuf) + 0.586611 * *(double *)(colorBuf+1) + 0.114478 * *(double *)(colorBuf+2);
    fwrite(grayBuf, sizeof(unsigned char), 1, fps);
    }
     
    printf("%d %d", w, h);
    printf("2");
  }
  else{
    for(i=0; i<w*h*3; i++){
      fread((colorBuf), sizeof(unsigned char), 3, fpl);
       *(double *)(grayBuf) =0.298912 * *(double *)(colorBuf+i*3) + 0.586611 * *(double *)(colorBuf+1) + 0.114478 * *(double *)(colorBuf+2);
      fwrite(grayBuf, sizeof(unsigned char), 1, fps);
    }
      
    printf("3");
  }
  
  //printf("%d %d , ", sizeof(buf), count);
  

  fclose(fps);
  fclose(fpl);
}
//void gray2sepia(int w, int h, unsigned char *grayBuf, unsigned char *sepiaBuf);
//void gray_negapos(int w, int h, unsigned char *posBuf, unsigned char *negBuf);
