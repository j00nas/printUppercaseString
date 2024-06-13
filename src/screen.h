#define ScreenWidth 50
#define ScreenHeigth 20

typedef struct{
  char pixels[ScreenHeigth][ScreenWidth];
} Screen;

void drawScreen(Screen *myScreen){
  for(int i = 0; i < ScreenHeigth; i++){
    for(int j = 0; j < ScreenWidth; j++){
      mvprintw(i,j, "%s", &myScreen->pixels[i][j]);
    } 
    mvprintw(i, ScreenWidth, "\n");
  } 
};

Screen initScreen(){
  Screen myScreen;
  for(int i = 0; i < ScreenHeigth; i++){
    for(int j = 0; j < ScreenWidth; j++){
      myScreen.pixels[i][j] = ' ';
    } 
  } 
  return myScreen;
};

