#include "util.h"

void seting(){

    system("mode con cols=56 lines=20 | title Game ");

    HANDLE ch = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cc;
    cc.bVisible = 0;
    cc.dwSize = 1;
    SetConsoleCursorInfo(ch,&cc);
}

void go(int x,int y){

    HANDLE co = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(co,pos);
}

void SetColor(int fg, int bg){
    HANDLE ch = GetStdHandle(STD_OUTPUT_HANDLE);
    int code = fg+bg*16;
    SetConsoleTextAttribute(ch, code);
}
