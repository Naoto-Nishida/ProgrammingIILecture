#include <stdio.h>

void main(){
  int b[100];
  int i;
     
  for(i = 0; i < 100; i++){
    if((i+1) % 10 == 0){
     b[i] = 0;
     printf("%d\n", b[i]);
    }
    else{
      b[i] = 0;
      printf("%d ", b[i]);
    }
  }
    

   

}
