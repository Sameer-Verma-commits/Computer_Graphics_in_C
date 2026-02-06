#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
void drawDDA(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1, dy = y2 - y1;
    float steps = (abs(dx) > abs(dy) ? abs(dx) : abs(dy));
    float x_inc = dx / steps, y_inc = dy / steps;
    float x = x1, y = y1;
    for (int s = 0; s <= steps; s++)
    {
        putpixel(round(x), round(y), WHITE);
        x += x_inc, y += y_inc;
    }
}
int main()
{
    int x1, y1, x2, y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    printf("Enter Coordinates for x1: ");
    scanf("%d", &x1);
    printf("Enter Coordinates for y1: ");
    scanf("%d", &y1);
    printf("Enter Coordinates for x2: ");
    scanf("%d", &x2);
    printf("Enter Coordinates for y2: ");
    scanf("%d", &y2);
    drawDDA(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}