#include "main.h"
#include "util.h"

#ifndef KEY_CODE
#define KEY_CODE

#define U 0
#define D 1
#define L 2
#define R 3
#define SPACE 4

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
int isend(int,int);
int StoreDraw();
