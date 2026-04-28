#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

void BresenhamLine(int x1, int y1, int x2, int y2, int color)
{
    int dx, dy, p, x, y;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;

    x = x1;
    y = y1;

    putpixel(x, y, color);

    // Case 1: slope < 1
    if (dx > dy)
    {
        p = 2 * dy - dx;

        for (int i = 0; i < dx; i++)
        {
            x += sx;

            if (p < 0)
                p += 2 * dy;
            else
            {
                y += sy;
                p += 2 * (dy - dx);
            }

            putpixel(x, y, color);
        }
    }
    // Case 2: slope >= 1
    else
    {
        p = 2 * dx - dy;

        for (int i = 0; i < dy; i++)
        {
            y += sy;

            if (p < 0)
                p += 2 * dx;
            else
            {
                x += sx;
                p += 2 * (dx - dy);
            }

            putpixel(x, y, color);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    BresenhamLine(50, 50, 250, 250, WHITE);
    getch();
    closegraph();
    return 0;
}