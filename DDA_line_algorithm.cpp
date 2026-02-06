#include <graphics.h>
#include <conio.h>
#include <math.h>
void drawDDA(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = (abs(dx) > abs(dy) ? abs(dx) : abs(dy));
    float x_inc = dx / steps;
    float y_inc = dy / steps;
    float x = x1;
    float y = y1;
    for (int s = 0; s <= steps; s++)
    {
        putpixel(round(x), round(y), WHITE);
        x += x_inc;
        y += y_inc;
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    drawDDA(50, 50, 250, 250);
    getch();
    closegraph();
    return 0;
}