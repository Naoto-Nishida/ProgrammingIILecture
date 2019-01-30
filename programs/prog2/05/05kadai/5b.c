#include <stdio.h>
#include <string.h>

int load_pgm(const char *filename, int *w, int *h, unsigned char *buf){
  FILE *fpl;
  char header[3];
  int i, dummy, c;

  fpl = fopen(filename, "rb");


  if(fpl == NULL){
    printf("Error: original file missing.\n");
    return 0;
  }
  fscanf(fpl, "%s\n%d %d\n%d\n", header, w, h, &dummy);

  // printf("%s", header);

  if(strcmp(header, "P2") == 0){
    for(i=0; i<(*w)*(*h); i++){  
	fscanf(fpl, "%d ", &c);//%hhp is also good.
	*(buf+i) = (unsigned char)c; //なんでint(4バイト)を1バイトにできるんだ！？WHY JAPANESE PEOPLE!?!??
//バイナリだと1バイトで256通りの表現ができるからアスキー表示よりも表現の場合の数が多くなるのはわかる。
//けどキャストはどっちに合わせたらええの！！！？！？！->右辺にキャストを書く。
    }
    
    //printf("%d %d", *w, *h);
    //printf("2");
  }
  else{
    fread(buf, sizeof(unsigned char), (*w)*(*h), fpl);
    //printf("3");
  }

  //printf("%d %d , ", sizeof(buf), count);
    
  fclose(fpl);
  return 1;
}


int save_pgm(const char *filename, int w, int h, unsigned char *buf){

  FILE *fps;


  fps = fopen(filename, "wb+");

  if(fps == NULL){
    printf("Error: copy file missing.\n");
    return 0;
  }

  fprintf(fps, "P5\n%d %d\n255\n", w, h);
  fwrite(buf, sizeof(unsigned char), w*h, fps);
  

  fclose(fps);
  return 1;
}

