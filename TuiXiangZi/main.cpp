/*
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int main()
{
    char a[50][50]={"   ###     ",
                    "   #*#     ",
                    "   # #     ",
                    "####O######",
                    "#*  OS O *#",
                    "#####O#####",
                    "    # #    ",
                    "    #*#    ",
                    "    ###    ",
                   };
    int i,j,x,y,s1,s2,z1,z2,y1,y2,x1,x2,os1,os2,oz1,oz2,oy1,oy2,ox1,ox2;
    char ch;
    x=4;y=5; // S的初始坐标.
    s1=1;s2=4; // 上方*的坐标.
    z1=4;z2=1; // 左边*的坐标.
    x1=7;x2=5; // 下面*的坐标.
    y1=4;y2=9;
    os1=3;os2=4; // 上面O的坐标.
    oz1=4;oz2=4; // 左边O的坐标.
    oy1=4;oy2=7; // 右边O的坐标.
    ox1=5;ox2=5; // 下面O的坐标.
    for(i=0;i<=9;i++)
        puts(a[i]);

    while(a[s1][s2]!='@' || a[z1][z2]!='@' || a[x1][x2]!='@' || a[y1][y2]!='@')
    {
        ch=getch();
        if(ch=='s')
        {
            if(a[x+1][y]!='#' && a[x+1][y]!='@')
            {
                if(a[x+1][y]=='O')
                {
                    a[x+1][y]=' ';  // 清空箱子的原来位置.
                    a[x+2][y]='O'; //  箱子位置更新.
                }
                a[x][y]=' ';
                x++;
                a[x][y]='S';
            }
        }
        if(ch=='w')
        {
            if(a[x-1][y]!='#' && a[x-1][y]!='@')
            {
                if(a[x-1][y]=='O')
                {
                    a[x-1][y]=' ';
                    a[x-2][y]='O';
                }
                a[x][y]=' ';
                x--;
                a[x][y]='S';
            }
        }
        if(ch=='a')
        {
            if(a[x][y-1]!='#' && a[x][y-1]!='@')
            {
                if(a[x][y-1]=='O')
                {
                    a[x][y-1]=' ';
                    a[x][y-2]='O';
                }
                a[x][y]=' ';
                y--;
                a[x][y]='S';
            }
        }
        if(ch=='d')
        {
            if(a[x][y+1]!='#' && a[x][y+1]!='@')
            {
                if(a[x][y+1]=='O')
                {
                    a[x][y+1]=' ';
                    a[x][y+2]='O';
                }
                a[x][y]=' ';
                y++;
                a[x][y]='S';
            }
        }
        if(a[y1][y2]=='O')
            a[y1][y2]='@';
        if(a[s1][s2]=='O')
            a[s1][s2]='@';
        if(a[z1][z2]=='O')
            a[z1][z2]='@';
        if(a[x1][x2]=='O')
            a[x1][x2]='@';
        system("cls");
        for(i=0;i<=9;i++)
            puts(a[i]);
    }

    Sleep(600);
    system("cls");
    puts("You win!");
    Sleep(5000);
    return 0;
}
