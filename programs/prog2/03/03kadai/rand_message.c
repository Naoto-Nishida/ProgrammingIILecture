#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]){
  int random;
  char *chara[5] = { " 24歳、衝撃のAVデビュー！本能のままに絶頂を貪る姿を曝け出す！！細いのにしっかりと引き締まった健康的な褐色ボディ。長い手脚、美巨乳、赤面しながらも、ちゃんと積極的なセックス。極度の緊張で、表情もギコチナイ…でも、その圧倒的なカラダが全てをカバーできてしまう。‘逸材だ’と、見ている内に気付かされる、最初で最後の処女作!!", 
"くん。へたっぴさ........!欲望の解放のさせ方がへた....。本当に欲しいのは...焼き鳥(こっち)......これを下のレンジでチンして....ホッカホッカにしてさ......冷えたビールで飲(や)りたい......!だろ....？ フフ....。だけど......それはあまりに値が張るから....こっちの........しょぼい柿ピーでごまかそうって言うんだ.....。", 
"が買ったのは..........ビール1本........!しかし1本飲んだらもう止まらない........!気が付けば..........豪遊っ....!2日続けて豪遊っ....!", 
"......!ただ突っ立ているだけ....至福の傍観っ............!", 
"には聞こえる・・・捨て牌三種の声・・・・・・"};

  if(argv[1] == NULL || argv[2] != NULL){
    printf("Usage: ./rand_message name\n");
  }
  else{
    srand(time(NULL));

   random = rand() % 5;

   if(random == 0){
     printf("%s%s\n", argv[1], chara[0]);
   }
   else if(random == 1){
     printf("%s%s\n", argv[1], chara[1]);
   }
   else if(random == 2){
     printf("%s%s\n", argv[1], chara[2]);
   }
   else if(random == 3){
     printf("%s%s\n", argv[1], chara[3]);
   }
   else if(random == 4){
     printf("%s%s\n", argv[1], chara[4]);
   }
  }


  return 0;
}

