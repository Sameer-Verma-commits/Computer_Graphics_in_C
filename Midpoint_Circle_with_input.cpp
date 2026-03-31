#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void MidpointCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y)
    {
        drawCircle(xc, yc, x, y);

        x++;

        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
    }
}

int main()
{
    int xc, yc, r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    printf("Enter Center Of Circles \n");
    printf("Coordinates for Xc: ");
    scanf("%d", &xc);
    printf("Coordinates for Yc: ");
    scanf("%d", &yc);
    printf("Radius r: ");
    scanf("%d", &r);
    MidpointCircle(xc, yc, r);
    getch();
    closegraph();
    return 0;
}