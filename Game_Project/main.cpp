#include "main.h"
#include "util.h"
#include "game.h"
using namespace std;


void Process(){
    int x = 2,y = 2;
    while(1)
    {
        TitleDraw();
        int MenuCode = MenuDraw();
        SetColor(white,black);
        if(MenuCode == 0)
        {
            //GameStart
            int n = MapListDraw();

            if(n == 0)
            {
                //printf("쉬움 선택함");
                //Sleep(1000);
                gloop(0);
                //DrawMap(&x,&y);
            }
            if(n == 1)
            {
                //printf("어려움 선택함");
                gloop(1);
                //Sleep(1000);
            }
        }
        if(MenuCode == 1)
        {
            //Game jungbo
            InfoDraw();
        }
        if(MenuCode == 2)
        {
            StoreDraw();
        }
        if(MenuCode == 3) return;
        system("cls");
        SetColor(white,black);
    }
}

int main()
{
    seting();
    Beep(2000,300);
    Process();
    return 0;
}


























