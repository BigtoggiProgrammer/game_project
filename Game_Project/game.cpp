#include "game.h"

int item = 1;

char Map[14][56] = {
    {"111111111111111111111111111111111111111111111111111"},
    {"100000000000000000000000000000000000000000000000001"},
    {"100000000000000000000000000000000000000000000000001"},
    {"100010000000000000000000000000000000000000000000001"},
    {"100010000000000000000000000000000000000000000000001"},
    {"100010000000000000000000000000000000000000000000001"},
    {"100010000000000000000030000000000000000000000000001"},
    {"100010000000000000000000000000000000000000000000001"},
    {"100010000000000000000000000000000000000000000000001"},
    {"100010000000000000000000000000000000000000000000001"},
    {"1000100000000000000000000000+00000000000000000+++01"},
    {"10s0100000000000000000000000000000000000000000+q+01"},
    {"1000100000000000000000000000000000000000000000+++01"},
    {"111111111111111111111111111111111111111111111111111"}
};

char Map2[14][56] = {
    {"111111111111111111111111111111111111111111111111111"},
    {"100310001000100000000000000000000000000000010001001"},
    {"101110131010101111111111111111111111111111110101011"},
    {"100010100+10101000100000010001000100010001q00100011"},
    {"111010110110101010101111010100010001011011101011411"},
    {"100010000010101010101010010101111100010010000010001"},
    {"101111111010101010100011110101000110111011111110101"},
    {"101000001010101010101000000101010010101000000010101"},
    {"101110101010101010001111111100010010101101111000101"},
    {"100000101010101011111000000001111010100000001011101"},
    {"111110101010001000010011011111001010001111100100101"},
    {"100010101010111111010110001000101011111000011110101"},
    {"1s100010+010000000010000100010001010000011000000001"},
    {"111111111111111111111111111111111111111111111111111"}
};

char Map3[14][56] = {
    {"111111111111111111111111111111111111111111111111111"},
    {"100310001000100000000000000000000000000000010001001"},
    {"101110131010101111111111111111111111111111110101011"},
    {"100010100+10101000100000010001000100010001q00100011"},
    {"111010110110101010101111010100010001011011101011411"},
    {"100010000010101010101010010101111100010010000010001"},
    {"101111111010101010100011110101000110111011111110101"},
    {"101000001010101010101000000101010010101000000010101"},
    {"101110101010101010001111111100010010101101111000101"},
    {"100000101010101011111000000001111010100000001011101"},
    {"111110101010001000010011011111001010001111100100101"},
    {"100010101010111111010110001000101011111000011110101"},
    {"1s100010+010000000010000100010001010000011000000001"},
    {"111111111111111111111111111111111111111111111111111"}
};

void TitleDraw(){
    SetColor(white,black);
    printf("\n\n\n\n");
    printf("        #####    ###    ###    #    ####   ##### \n");
    Sleep(300);
    printf("        #       #      #      # #   #   #  #     \n");
    Sleep(300);
    printf("        ####    ####   #     #####  ####   ####  \n");
    Sleep(300);
    printf("        #           #  #     #   #  #      #     \n");
    Sleep(300);
    printf("        #####   ####    ###  #   #  #      ##### \n");
    Sleep(300);
}

int MenuDraw(){
    //SetColor(white,black);
    int x = 23,y = 12;
    go(x-2,y);
    SetColor(lightred,black);
    printf("> [");
    SetColor(white,black);
    printf("게임시작");
    SetColor(lightred,black);
    printf("]");
    SetColor(white,black);
    Sleep(300);
    go(x,y+1);
    printf(" 게임정보 ");
    Sleep(300);
    go(x,y+2);
    printf(" 상    점 ");
    Sleep(300);
    go(x,y+3);
    printf(" 종    료 ");
    while(1)
    {
        int n = KeyControl();
        switch(n)
        {
            case U :
            {
                if(y > 12)
                {
                    go(x-2,y);
                    printf(" ");
                    go(x,y);
                    printf(" ");
                    go(x+9,y);
                    printf(" ");
                    go(x-2,--y);
                    SetColor(lightred,black);
                    printf(">");
                    go(x,y);
                    printf("[");
                    go(x+9,y);
                    printf("]");
                }
                break;
            }
            case D :
            {
                if(y < 15)
                {
                    go(x-2,y);
                    printf(" ");
                    go(x,y);
                    printf(" ");
                    go(x+9,y);
                    printf(" ");
                    go(x-2,++y);
                    SetColor(lightred,black);
                    printf(">");
                    go(x,y);
                    printf("[");
                    go(x+9,y);
                    printf("]");
                }
                break;
            }

            case SPACE :
            {
                return y-12;
            }
        }
    }
}
int KeyControl(){
    char tmp = getch();
    if(tmp == 'w'||tmp == 'W') return U;
    if(tmp == 'a'||tmp == 'A') return L;
    if(tmp == 's'||tmp == 'S') return D;
    if(tmp == 'd'||tmp == 'D') return R;
    if(tmp == ' ') return SPACE;
}
void InfoDraw(){
    system("cls");
    printf("\n\n");
    printf("                       [ 조작법 ]\n\n");
    printf("                   이동 : W, A, S, D\n");
    printf("                   선택 : 스페이스바 \n\n\n\n\n\n\n");
    printf("                개발자 : 김건우,김재성        \n\n");
    printf("      스페이스바를 누르면 메인화면으로 이동합니다 .");

    while(1) {
        if(KeyControl() == SPACE)
        {
            break;
        }
    }
}

int MapListDraw(){
    int x = 24;
    int y = 6;
    system("cls");
    printf("\n\n");
    printf("                       [ 맵 선택 ]\n\n");

    go(x-2,y);
    printf("> 쉬움");
    go(x,y+1);
    printf("어려움");
    go(x,y+2);
    printf("뒤로");
    go(x-1,y);
    while(1){
        int n = KeyControl();
        switch(n){
            case U :
            {
                if(y > 6){
                    go(x-2,y);
                    printf(" ");
                    go(x-2,--y);
                    printf(">");
                }
                break;
            }
            case D :
            {
                if(y < 8)
                {
                    go(x-2,y);
                    printf(" ");
                    go(x-2,++y);
                    printf(">");
                }
                break;
            }
            case SPACE :
            {
                return y-6;
            }
        }
    }
}

char tm[14][56];

void DrawMap(int *x,int *y){
    system("cls");
    int i,j;
    for(i = 0;i < 14;i++)
    {
        for(j = 0;j < 56;j++)
        {
            char tmp = tm[i][j];
            if(tmp == '0')
            {
                SetColor(black,black);
                printf(" ");
            }
            if(tmp == '1'||tmp == '4')
            {
                SetColor(white,white);
                printf("#");
            }
            if(tmp == 's')
            {
                *y = i;
                *x = j;
                SetColor(cyan,black);
                printf("@");
            }
            if(tmp == 'q')
            {
                SetColor(lightgreen,black);
                printf("0");
            }
            if(tmp == '+')
            {
                SetColor(red,black);
                printf("#");
            }
            if(tmp == '3')
            {
                SetColor(lightcyan,black);
                printf("*");
            }
            //printf("%c",Map[i][j]);
        }
        printf("\n");
    }
    SetColor(white,black);
    //Sleep(3000);
}


void gloop(int mc){
    int x,y;
    int pl = 1;
    if(mc == 0)
    {
        memcpy(tm,Map,sizeof(tm));
    }
    if(mc == 1)
    {
        memcpy(tm,Map2,sizeof(tm));
    }
    DrawMap(&x,&y);
    //x = 2;
    //y = 11;
    while(pl)
    {

        drawUI(&x,&y);
        switch(KeyControl())
        {
            case U :
            {
                //if(tm[x-1][y-1] == '1') break;
                if(tm[y-1][x] == '1') break;
                if(iseat(y-1,x))
                {
                    Beep(2000,100);
                    item++;
                }
                if(isend(y-1,x))
                {
                    pl = 0;
                }
                if(tm[y-1][x] == '+')
                {
                    if(iseat(y-1,x)) item++;
                    item--;
                    SetColor(black,black);
                    tm[y-1][x] = 0;
                    go(x,y-1);
                    printf(" ");
                    //DrawMap(&x,&y);
                    break;
                }
                mov(&x,&y,0,-1);
                break;
            }
            case D :
            {
                //if(tm[x][y+1] == '1') break;
                if(tm[y+1][x] == '1') break;
                if(iseat(y+1,x))
                {
                    item++;
                    Beep(2000,100);
                }
                if(isend(y+1,x))
                {
                    pl = 0;
                }
                if(tm[y+1][x] == '+')
                {
                    if(item == 0) break;
                    item--;
                    SetColor(black,black);
                    tm[y+1][x] = 0;
                    go(x,y+1);
                    printf(" ");
                    //DrawMap(&x,&y);
                    break;
                }
                mov(&x,&y,0,1);
                break;
            }
            case R :
            {
                //if(tm[x+1][y] == '1') break;
                if(tm[y][x+1] == '1') break;
                if(iseat(y,x+1))
                {
                    item++;
                    Beep(2000,100);
                }
                if(isend(y,x+1))
                {
                    pl = 0;
                }
                if(tm[y][x+1] == '+')
                {
                    if(item == 0) break;
                    item--;
                    SetColor(black,black);
                    tm[y][x+1] = 0;
                    go(x+1,y);
                    printf(" ");
                    //DrawMap(&x,&y);
                    break;
                }
                mov(&x,&y,1,0);
                break;
            }
            case L :
            {
                //if(tm[x-1][y] == '1') break;
                if(tm[y][x-1] == '1') break;
                if(iseat(y,x-1))
                {
                    item++;
                    Beep(2000,100);
                }
                if(isend(y,x-1))
                {
                    pl = 0;
                }
                if(tm[y][x-1] == '+')
                {
                    if(item == 0) break;
                    item--;
                    SetColor(black,black);
                    tm[y][x-1] = 0;
                    go(x-1,y);
                    printf(" ");
                    //DrawMap(&x,&y);
                    break;
                }
                mov(&x,&y,-1,0);
                break;
            }
            case SPACE :
            {
                pl = 0;
            }
        }
    }
}

void mov(int *x,int *y,int _x,int _y){
    SetColor(white,black);
    go(*x,*y);
    printf(" ");

    SetColor(cyan,black);
    go(*x+_x,*y+_y);
    printf("@");

    *x += _x;
    *y += _y;
}

void drawUI(int *x,int *y){
    SetColor(white,black);
    go(3,16);
    printf("위치: %02d, %02d", *x, *y);

    SetColor(yellow,black);
    go(34,16);
    printf("아이템 : %02d 개",item);
}

int iseat(int x,int y)
{
    if(tm[x][y] == '3') return 1;
    return 0;
}

int isend(int x,int y)
{
    if(tm[x][y] == 'q') return 1;
    return 0;
}

int StoreDraw()
{
    system("cls");
    int x = 22,y = 6;
    go(x-2,y);
    printf("> 과자: 500원");
    go(x,y+1);
    printf("사탕: 300원");
    while(1)
    {
        int n = KeyControl();
        switch(n)
        {
            case U :
            {
                if(y > 6)
                {
                    go(x-2,y);
                    printf(" ");
                    go(x-2,--y);
                    printf(">");
                }
                break;
            }
            case D :
            {
                if(y < 7)
                {
                    go(x-2,y);
                    printf(" ");
                    go(x-2,++y);
                    printf(">");
                }
                break;
            }
            case SPACE :
            {
                return y-6;
            }
        }
    }
}
