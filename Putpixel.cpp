#include <graphics.h>
#include <conio.h>
#include <stdio.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    outtextxy(10, 10, (char *)"Display a Single Pixel At 50,50");
    putpixel(50, 50, WHITE);
    getch();
    closegraph();
    return 0;
}