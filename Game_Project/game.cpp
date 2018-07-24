#include "game.h"

int item = 0,coin = 1;

char Map[14][61] = {
    {"11111111111111111111111111111111111111111111111111111111"},
    {"10000000000000000000000000000000000000000000000000000001"},
    {"10000000000000000000000000000000000000000000000000000001"},
    {"10001000000000000000000000000000000000000000000000000001"},
    {"10001000000000000000000000000000000000000000000000000001"},
    {"10001000000000000000000000000000000000000000000000000001"},
    {"10001000000000000000000000000000000000000000000000000001"},
    {"10001000000000000000000000000000000000000000000000000001"},
    {"10001000000000000000000000000000000000000000000000000001"},
    {"10001000000000000000000000000000000000000000000000000001"},
    {"1000100000000000000000000000+00000000000000000+++0000001"},
    {"10s0100000000000000000000000000000000000000000+q+0000001"},
    {"1000100000000000000000000000000000000000000000+++0000001"},
    {"11111111111111111111111111111111111111111111111111111111"}
};

char Map2[14][61] = {
    {"11111111111111111111111111111111111111111111111111111111"},
    {"10031000100010000000000000000000000000000001000100000001"},
    {"10111010101010111111111111111111111111111111010101111111"},
    {"100010100+10101000100000010001000100010001q0010001100001"},
    {"11101011011010101010111101010001000101101110101141110401"},
    {"10001000001010101010101001010111110001001000001000001111"},
    {"10111111101010101010001111010100011011101111111010111111"},
    {"10100000101010101010100000010101001010100000001010110011"},
    {"10111010101010101000111111110001001010110111100010100001"},
    {"10000010101010101111100000000111101010000000101110111011"},
    {"11111010101000100001001101111100101000111110010010111001"},
    {"10001010101011111101011000100010101111100001111010110101"},
    {"1s100010+01000000001000010001000101000001100000000010111"},
    {"1111111111111111111111111111111111111111111111111111111"}
};

char Map3[14][61] = {
    {"11111111111111111111111111111111111111111111111111111111"},
    {"10031000100010000000000000000000000000000001000100000001"},
    {"10111010101010111111111111111111111111111111010101111111"},
    {"100010100+10101000100000010001000100010001q0010001100001"},
    {"11101011011010101010111101010001000101101110101141110401"},
    {"10001000001010101010101001010111110001001000001000001111"},
    {"10111111101010101010001111010100011011101111111010111111"},
    {"10100000101010101010100000010101001010100000001010110011"},
    {"10111010101010101000111111110001001010110111100010100001"},
    {"10000010101010101111100000000111101010000000101110111011"},
    {"11111010101000100001001101111100101000111110010010111001"},
    {"10001010101011111101011000100010101111100001111010110101"},
    {"1s100010+01000000001000010001000101000001100000000010111"},
    {"1111111111111111111111111111111111111111111111111111111"}
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
    if(tmp == '_') return -1;
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
    printf("중간");
    go(x,y+2);
    printf("어려움");
    go(x,y+3);
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
                if(y < 9)
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

char tm[14][61];

void DrawMap(int *x,int *y){
    system("cls");
    int i,j;
    for(i = 0;i < 14;i++)
    {
        for(j = 0;j < 61;j++)
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
            if(tmp == 'c')
            {
                SetColor(lightgray,black);
                printf("o");
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
    item = 0;
    if(mc == 0)
    {
        memcpy(tm,Map,sizeof(tm));
    }
    if(mc == 1)
    {
        memcpy(tm,Map2,sizeof(tm));
    }
    if(mc == 2)
    {
        memcpy(tm,Map3,sizeof(tm));
    }
    long long int *temp1,*temp2;
    do
    {
        temp1 = (long long int*)malloc(sizeof(long long int));
        *temp1 %= 14;
        temp2 = (long long int*)malloc(sizeof(long long int));
        *temp2 %= 61;
    }while(tm[(int)*temp1][(int)*temp2] != '0');
    tm[(int)*temp1][(int)*temp2] = 'c';
    DrawMap(&x,&y);
    //x = 2;
    //y = 11;ss
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
                    item++;
                    tm[y-1][x] = '0';
                    Beep(2000,100);
                }
                if(iscoin(y-1,x))
                {
                    coin++;
                    Beep(2500,100);
                }
                if(isend(y-1,x))
                {
                    pl = 0;
                }
                if(tm[y-1][x] == '+')
                {
                    if(item == 0) break;
                    item--;
                    SetColor(black,black);
                    tm[y-1][x] = '0';
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
                    tm[y+1][x] = '0';
                    Beep(2000,100);
                }
                if(iscoin(y+1,x))
                {
                    coin++;
                    Beep(2500,100);
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
                    tm[y+1][x] = '0';
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
                    tm[y][x+1] = '0';
                    Beep(2000,100);
                }
                if(iscoin(y,x+1))
                {
                    coin++;
                    Beep(2500,100);
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
                    tm[y][x+1] = '0';
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
                if(iscoin(y,x-1))
                {
                    coin++;
                    Beep(2500,100);
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
                    tm[y][x-1] = '0';
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
    printf("열쇠: %02d 개",item);
    go(19,16);
    printf("코인: %02d 개",coin);
}

int iseat(int x,int y)
{
    if(tm[x][y] == '3')
    {
        tm[x][y] = '0';
        return 1;
    }
    return 0;
}

int iscoin(int x,int y)
{
    if(tm[x][y] == 'c')
    {
        tm[x][y] = '0';
        return 1;
    }
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
    printf("> 열쇠1개: 3개");
    go(x,y+1);
    printf("열쇠5개: 10개");
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
