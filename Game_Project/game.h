#include "main.h"
#include "util.h"

#ifndef KEY_CODE
#define KEY_CODE
// 2018-07-26 : 김재성 : 키 Define 변경
#define HID -1
#define NO_KEY	0
#define U 1
#define D 2
#define L 3
#define R 4
#define SPACE 5
#define BUY 6


#endif // KEY_CODE

int KeyControl();
int MenuDraw();
void TitleDraw();
void InfoDraw();
int MapListDraw();
void DrawMap(int*,int*);
void gloop(int);
void mov(int*,int*,int,int);
void drawUI(int*,int*);
int iseat(int,int);
int iscoin(int,int);
int isend(int,int);
void StoreDraw();
int OpenFile();
void Seting_item_coin(int);
void CloseFile();
int inzuap(int,int,int);
