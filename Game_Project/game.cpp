#include "game.h"

int item,coin;
int Wh,wh;

// s : 시작지점
// 1 : 블럭
// 0 : 길
// + : 장벽
// q : 목표물
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
    {"10001000100010000000000000000000000000000001000100000001"},
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
    {"11111111111111111111111111111111111111111111111111111111"}
};

char Map3[14][61] = {
    {"11111111111111111111111111111111111111111111111111111111"},
    {"1000100s100010001000000000001100000000000000011100001111"},
    {"10111010101010101111111111111101111111111111010101101111"},
    {"100011001+0000100010000001000100010001000400040001100001"},
    {"11101101111110101010111101010001000101101110101111111101"},
    {"10001100001010101010101001110111110001001000001000001101"},
    {"10111101101010101010001111040100011011101111111110141101"},
    {"10100000101010101010100000010101001010100000001000110041"},
    {"10111010101010101000111111110001001010110111100100100001"},
    {"10000+101010101011111000000001111010100000001611+0641011"},
    {"111110101010001000010011011111001010001111106+q+00144001"},
    {"10001010101111111101011000100010101111100001111110110101"},
    {"1010001010000000000100001000100010100000110000+000040111"},
    {"11111111111111111111111111111111111111111111111111111111"}
};

int fake[10005][2] = {{10,44},{9,45}};
int nx[4] = {1,0,-1,0},ny[4] = {0,1,0,-1};

int OpenFile()
{
    int it1,co1,it2,co2,it3,co3;
    FILE *fp;
    fp = fopen("data1.txt","r");
    fscanf(fp,"%d %d", &it1, &co1);
    fclose(fp);
    fp = fopen("data2.txt","r");
    fscanf(fp,"%d %d", &it2, &co2);
    fclose(fp);
    fp = fopen("data3.txt","r");
    fscanf(fp,"%d %d", &it3, &co3);
    int x = 17,y = 8;
    go(x-6,y-4);
    SetColor(white,black);
    printf("원하는 세이브 파일에 들어가 주십시오.");
    go(x-2,y);
    SetColor(lightred,black);
    printf("> ");
    SetColor(white,black);
    printf("열쇠: %02d개, 코인: %02d개",it1,co1);
    go(x,y+1);
    printf("열쇠: %02d개, 코인: %02d개",it2,co2);
    go(x,y+2);
    printf("열쇠: %02d개, 코인: %02d개",it3,co3);
    while(1)
    {
        int n = KeyControl();
        switch(n)
        {
            case U :
            {
                if(y > 8)
                {
                    go(x-2,y);
                    printf(" ");
                    //go(x,y);
                    //printf(" ");
                    //go(x+9,y);
                    //printf(" ");
                    go(x-2,--y);
                    SetColor(lightred,black);
                    printf(">");
                    //go(x,y);
                    //printf("[");
                    //go(x+9,y);
                    //printf("]");
                }
                break;
            }
            case D :
            {
                if(y < 10)
                {
                    go(x-2,y);
                    printf(" ");
                    //go(x,y);
                    //printf(" ");
                    //go(x+9,y);
                    //printf(" ");
                    go(x-2,++y);
                    SetColor(lightred,black);
                    printf(">");
                    //go(x,y);
                    //printf("[");
                    //go(x+9,y);
                    //printf("]");
                }
                break;
            }

            case SPACE :
            {
                Wh = y-8;
                if(y-8 == 0) return it1*10000+co1;
                if(y-8 == 1) return it2*10000+co2;
                if(y-8 == 2) return it3*10000+co3;
                //return y-12;
            }
        }
    }
    fclose(fp);
}

void Seting_item_coin(int n)
{
    item = n/10000;
    coin = n%10000;
    system("cls");
}

void CloseFile()
{
    FILE *fp;
    fp = fopen("input.txt","w");
    if(Wh == 0)
    {
        fp = fopen("data1.txt","w");
        fprintf(fp,"%d %d",item,coin);
    }
    if(Wh == 1)
    {
        fp = fopen("data2.txt","w");
        fprintf(fp,"%d %d",item,coin);
    }
    if(Wh == 2)
    {
        fp = fopen("data3.txt","w");
        fprintf(fp,"%d %d",item,coin);
    }
    fclose(fp);
}

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

#if 0
int KeyControl(){
    char tmp = getch();
    if(tmp == 'w'||tmp == 'W') return U;
    if(tmp == 'a'||tmp == 'A') return L;
    if(tmp == 's'||tmp == 'S') return D;
    if(tmp == 'd'||tmp == 'D') return R;
    if(tmp == 'b'||tmp == 'B') return BUY;
    if(tmp == '_') return -1;
    if(tmp == ' ') return SPACE;
}
#endif

int KeyControl(){

    int key = getch();
    if((key == 224) || (key == 0))  // 방향키 이면
    {
    	key = getch();
	switch(key)
	{
		case 72: return U;
		case 75: return L;
		case 77: return R;
		case 80: return D;
		default : return NO_KEY;  // 정의 되지 않은 키 눌림
	}
    }
    else
    {
    	if(key == 'b'||key == 'B') return BUY;
    	if(key == '_') return -1;
    	if(key == ' ') return SPACE;
	    else return NO_KEY;  // 정의되지 않은 키 눌림
    }	
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
            if(tmp == '0'||tmp == '6')
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
        wh = 1;
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
                for(int i = 0;i < 2;i++)
                {
                    if(wh&&inzuap(x,y,i))
                    {
                        tm[fake[i][0]][fake[i][1]] = '1';
                        go(fake[i][1],fake[i][0]);
                        SetColor(white,white);
                        printf("#");
                        //SetColor()
                    }
                }
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

                for(int i = 0;i < 2;i++)
                {
                    if(wh&&inzuap(x,y,i))
                    {
                        tm[fake[i][0]][fake[i][1]] = '1';
                        go(fake[i][1],fake[i][0]);
                        SetColor(white,white);
                        printf("#");
                        //SetColor()
                    }
                }
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
                for(int i = 0;i < 2;i++)
                {
                    if(wh&&inzuap(x,y,i))
                    {
                        tm[fake[i][0]][fake[i][1]] = '1';
                        go(fake[i][1],fake[i][0]);
                        SetColor(white,white);
                        printf("#");
                        //SetColor()
                    }
                }
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
                for(int i = 0;i < 2;i++)
                {
                    if(wh&&inzuap(x,y,i))
                    {
                        tm[fake[i][0]][fake[i][1]] = '1';
                        go(fake[i][1],fake[i][0]);
                        SetColor(white,white);
                        printf("#");
                        //SetColor()
                    }
                }
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

void StoreDraw()
{
    system("cls");
    int x = 20,y = 6;
    go(2,2);
    printf("코인: %02d개",coin);
    go(x-2,y);
    printf("> 열쇠1개: 코인3개");
    go(x,y+1);
    printf("열쇠5개: 코인10개");
    go(x-3,y+13);
    printf("구매하는 키는 b 입니다.");
    while(1)
    {
        int n = KeyControl();
        switch(n)
        {
            case -1 :
            {
                coin += 1000;
            }
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
            case BUY :
            {
                if(y-6 == 0)
                {
                    if(coin >= 3)
                    {
                        item += 1;
                        coin -= 3;
                        Beep(2700,200);
                        go(2,2);
                        printf("코인: %02d개",coin);
                    }
                }
                if(y-6 == 1)
                {
                    if(coin >= 10)
                    {
                        item += 5;
                        coin -= 10;
                        Beep(2700,200);
                        go(2,2);
                        printf("코인: %02d개",coin);
                    }
                }
                break;
            }
            case SPACE :
            {
                return;
            }
        }
    }
}

int inzuap(int y,int x,int k)
{
    for(int i = 0;i < 4;i++)
    {
        if(x+nx[i] == fake[k][0]&&y+ny[i] == fake[k][1]) return 1;
    }
    return 0;
}
