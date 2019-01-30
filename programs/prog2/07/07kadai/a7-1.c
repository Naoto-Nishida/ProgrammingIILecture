#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerA.h"

  

int main(){
  ImageData image[8];
  char title[30];


  for(int i=0; i<4; i++){

    switch(i){
    case 0:
      LoadImage("checker4x4_ascii.pgm", &image[i]);
      strcpy(title, "Copied_Asc_gray.pgm");
      break;
    case 1:
      LoadImage("color4x4_ascii.ppm", &image[i]);
      strcpy(title, "Copied_Asc_color.ppm");
      break;
    case 2:
      LoadImage("lenna256x256binary.ppm", &image[i]);
      strcpy(title, "Copied_Bina_color.ppm");
      break;
    case 3:
      LoadImage("sutehage400x400binary.pgm", &image[i]);
      strcpy(title, "Copied_Bina_gray.pgm");
      break;
    default:
      printf("something is wrong\n");
      return -5;
      break;
    }
    
    CopyImage(&image[i], &image[i+4]);
    SaveImage(title, &image[i+4]);

    ReleaseImage(&image[i]);
    ReleaseImage(&image[i+4]);
  }

  return 0;
}
