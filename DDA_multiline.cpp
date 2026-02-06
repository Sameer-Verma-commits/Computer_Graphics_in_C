#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
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
    int x1, y1, x2, y2, line;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    printf("Enter Number of Line: ");
    scanf("%d", &line);
    for (int i = 0; i < line; i++)
    {
        printf("Coordinates for Line %d \n", i + 1);
        printf("Enter x1: ");
        scanf("%d", &x1);
        printf("Enter y1: ");
        scanf("%d", &y1);
        printf("Enter x2: ");
        scanf("%d", &x2);
        printf("Enter y2: ");
        scanf("%d", &y2);
        drawDDA(x1, y1, x2, y2);
    }

    getch();
    closegraph();
    return 0;
}