#include <stdio.h>
#include <string.h>

int load_ppm(const char *filename, int *w, int *h, unsigned char *buf){
  FILE *fpl;
  char header[3];
  int i, dummy, c;

  fpl = fopen(filename, "rb");


  if(fpl == NULL){
    printf("Error: original file missing.\n");
    return 0;
  }
  fscanf(fpl, "%s\n%d %d\n%d\n", header, w, h, &dummy);

  if(strcmp(header, "P3") == 0){
    for(i=0; i<(*w)*(*h)*3; i++){  
	fscanf(fpl, "%d ", &c);
	*(buf+i)= (unsigned char)c; //キャストは普通右辺にするものっぽい！？！？！？
    }
    
    //printf("%d %d", *w, *h);
    //printf("2");
  }
  else{
    fread(buf, sizeof(unsigned char), (*w)*(*h)*3, fpl);
    //printf("3");
  }

  //printf("%d %d , ", sizeof(buf), count);

 
    
  fclose(fpl);
  return 1;
}


int save_ppm(const char *filename, int w, int h, unsigned char *buf){

  FILE *fps;


  fps = fopen(filename, "wb+");

  if(fps == NULL){
    printf("Error: copy file missing.\n");
    return 0;
  }
  
  fprintf(fps, "P6\n%d %d\n255\n", w, h);
  fwrite(buf, sizeof(unsigned char), w*h*3, fps);
  

  fclose(fps);
  return 1;
}
