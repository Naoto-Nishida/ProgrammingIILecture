#include <stdio.h>
#include <string.h>
#define MAX_IMAGE_SIZE 512
//#define debugA
//#define debugB
#define debugC


int load_pgm(const char *filename, int *w, int *h, unsigned char *buf);
int save_pgm(const char *filename, int w, int h, unsigned char *buf);
int load_ppm(const char *filename, int *w, int *h, unsigned char *buf);
int save_ppm(const char *filename, int w, int h, unsigned char *buf);



int main(int argc, char *argv[]){
  
  int w, h, dummy; //for file access
  char header[3];
  FILE *fp1;

  int i, j; // for manipulating
  unsigned char rgb[3]; //r:0 g:1 b:2

  unsigned char buf1[1000];
  unsigned char buf2[1000];// for buffer.
  
#ifdef debugA
  fp1 = fopen(argv[1], "rb");
  fscanf(fp1, "%s\n%d %d\n%d\n", header, &w, &h, &dummy);

  if(fp1 == NULL){
    printf("Error: file not found.\n");
    return -1;
  }

  printf("image size: %dx%d\n", w, h);

  if(header[1] == 0 || header[1] == 1 || header[1] == 2){
    for(i=0; i<h; i++){
      for(j=0; j<w; j++){
	fscanf(fp1, "%c %c %c", &rgb[0], &rgb[1], &rgb[2]);
	printf("(%d,%d) rgb = (%d, %d, %d)\n", j, i, (unsigned int)rgb[0], (unsigned int)rgb[1], (unsigned int)rgb[2]);
      }
    }
  }
  else{
    for(i=0; i<h; i++){
      for(j=0; j<w; j++){
	fread(rgb, sizeof(unsigned char), 3, fp1);
	printf("(%d,%d) rgb = (%d, %d, %d)\n", j, i, (int)rgb[0], (int)rgb[1], (int)rgb[2]);
      }
    }
  }
#endif

#ifdef debugB
  if(load_pgm("checker4x4_ascii.pgm", &w, &h, buf1) == 1){  
    save_pgm("copyfile1.bin", w, h, buf1);
  }
  if(load_pgm("checker4x4_binary.pgm", &w, &h, buf2) == 1){  
    save_pgm("copyfile2.bin", w, h, buf2);
  }
#endif

#ifdef debugC
  if(load_ppm("color4x4_ascii.pgm", &w, &h, buf1) == 1){  
    save_pgm("copyfile3.bin", w, h, buf1);
  }
  if(load_ppm("color4x4_binary.pgm", &w, &h, buf2) == 1){  
    save_pgm("copyfile4.bin", w, h, buf2);
  }
#endif

  
  

#ifdef debugA
  fclose(fp1);
#endif
  return 0;
}


int load_pgm(const char *filename, int *w, int *h, unsigned char *buf){
  FILE *fpl;
  char header[3];
  int i, dummy;

  fpl = fopen(filename, "rb");


  if(fpl == NULL){
    printf("Error: original file missing.");
    return 0;
  }
  fscanf(fpl, "%s\n%d %d\n%d\n", header, w, h, &dummy);
  fseek(fpl, 0, SEEK_SET);

  // printf("%s", header);

  if(strcmp(header, "P2") == 0){
    for(i=0; i<(*w)*(*h)*3+12; i++){  //12byte is the size of metadata
	fscanf(fpl, "%c", (buf+i));
    }
    *h *=3;
    //buf gets the 255, 0 and space as char
    //so (255 255 0 0 )is 3 times higher in byte than(ff00)
    
    //printf("%d %d", *w, *h);
    //printf("2");
  }
  else{
    fread(buf, sizeof(unsigned char), (*w)*(*h)+12, fpl);
    //printf("3");
  }
    
  fclose(fpl);
  return 1;
}


int save_pgm(const char *filename, int w, int h, unsigned char *buf){

  FILE *fps;


  fps = fopen(filename, "wb+");

  if(fps == NULL){
    printf("Error: copy file missing.");
    return 0;
  }

  fwrite(buf, sizeof(unsigned char), w*h+12, fps);
  

  fclose(fps);
  return 1;
}


int load_ppm(const char *filename, int *w, int *h, unsigned char *buf){
  FILE *fpl;
  char header[3];
  int i, dummy;

  fpl = fopen(filename, "rb");


  if(fpl == NULL){
    printf("Error: original file missing.");
    return 0;
  }
  fscanf(fpl, "%s\n%d %d\n%d\n", header, w, h, &dummy);
  fseek(fpl, 0, SEEK_SET);

  // printf("%s", header);

  if(strcmp(header, "P3") == 0){
    for(i=0; i<(*w)*(*h)*3+12; i++){  //12byte is the size of metadata
      fscanf(fpl, "%d", ((int *)buf+i));
    }
    *h *=3;
    //buf gets the 255, 0 and space as char
    //so (255 255 0 0 )is 3 times higher in byte than(ff00)
    //if buf is defined as int, it could be used for every case
    //because buf can get 255 and 0 as the same size.
    //printf("%d %d", *w, *h);
    //printf("2");
  }
  else{
    fread(buf, sizeof(unsigned char), (*w)*(*h)+12, fpl);
    //printf("3");
  }
    
  fclose(fpl);
  return 1;



}



int save_ppm(const char *filename, int w, int h, unsigned char *buf){




}
