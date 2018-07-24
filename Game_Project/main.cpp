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
            gloop(n);
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
        if(MenuCode == 3)
        {
            CloseFile();
            return;
        }
        system("cls");
        SetColor(white,black);
    }
}

int main()
{
    seting();
    Seting_item_coin(OpenFile());
    Beep(2000,300);
    Process();
    return 0;
}


























