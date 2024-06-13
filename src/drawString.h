#include "letters.h"
#include "screen.h"

#define sizeOfAlphabet 27
#define letterOffsetHeigth 5

Letter *initLetters(){
  Letter *letters;
  letters = malloc(sizeof(Letter)*sizeOfAlphabet);
 
  *(letters+sizeof(Letter)*0) = LETTER_A;
  *(letters+sizeof(Letter)*1) = LETTER_B;
  *(letters+sizeof(Letter)*2) = LETTER_C;
  *(letters+sizeof(Letter)*3) = LETTER_D;
  *(letters+sizeof(Letter)*4) = LETTER_E;
  *(letters+sizeof(Letter)*5) = LETTER_F;
  *(letters+sizeof(Letter)*6) = LETTER_G;
  *(letters+sizeof(Letter)*7) = LETTER_H;
  *(letters+sizeof(Letter)*8) = LETTER_I;
  *(letters+sizeof(Letter)*9) = LETTER_J;
  *(letters+sizeof(Letter)*10) = LETTER_K;
  *(letters+sizeof(Letter)*11) = LETTER_L;
  *(letters+sizeof(Letter)*12) = LETTER_M;
  *(letters+sizeof(Letter)*13) = LETTER_N;
  *(letters+sizeof(Letter)*14) = LETTER_O;
  *(letters+sizeof(Letter)*15) = LETTER_P;
  *(letters+sizeof(Letter)*16) = LETTER_Q;
  *(letters+sizeof(Letter)*17) = LETTER_R;
  *(letters+sizeof(Letter)*18) = LETTER_S;
  *(letters+sizeof(Letter)*19) = LETTER_T;
  *(letters+sizeof(Letter)*20) = LETTER_U;
  *(letters+sizeof(Letter)*21) = LETTER_V;
  *(letters+sizeof(Letter)*22) = LETTER_W;
  *(letters+sizeof(Letter)*23) = LETTER_X;
  *(letters+sizeof(Letter)*24) = LETTER_Y;
  *(letters+sizeof(Letter)*25) = LETTER_Z;
  *(letters+sizeof(Letter)*26) = LETTER_SPACE;

  return letters;
};

void createPWord (Letter pword[], char *word, int wordLength, Letter *letters){
  for(int p = 0; p < wordLength; p++){
    switch (word[p]){
      case ' ':
        pword[p] = *(letters + (sizeOfAlphabet-1)*sizeof(Letter));
        break;
      default:
        pword[p] = *(letters + (((int)word[p] - 65) * sizeof(Letter)));
      }
    };
};

void drawBigString(char *word, Screen *myScreen, int wordLength){
  Letter *letters = initLetters();
  Letter pword[wordLength];
  createPWord(pword, word, wordLength, letters);  

  int endOfScreenFlag = ScreenWidth - 1;

  for(;;){
    drawScreen(myScreen);
    refresh();

    for(int w = 0; w < wordLength; w++){;
      for(int i = 0; i < LetterHeigth; i++){
        for(int j = 0; j < LetterWidth; j++){
          if(endOfScreenFlag+j+(w*(LetterWidth+1)) < ScreenWidth && endOfScreenFlag > 0-(w*LetterWidth)){
            myScreen->pixels[i+letterOffsetHeigth][endOfScreenFlag+j+(w*(LetterWidth+1))] = pword[w].pixels[i][j];
          };
        };
      };
      for(int y = 0; y < LetterHeigth; y++){
        myScreen->pixels[y+letterOffsetHeigth][endOfScreenFlag + ((w+1)*LetterWidth+w)] = ' ';
      };
    };

    usleep(100000);

    endOfScreenFlag--;
    if(endOfScreenFlag < 0-((wordLength+1)*LetterWidth)-1){
      endOfScreenFlag = ScreenWidth -1 ;
    }
  }
}
