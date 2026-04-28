#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

void BresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx, dy, p, x, y;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;

    x = x1;
    y = y1;

    putpixel(x, y, WHITE);

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

            putpixel(x, y, WHITE);
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

            putpixel(x, y, WHITE);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    // Rectangle coordinates
    int x1 = 100, y1 = 100; //Top-Left
    int x2 = 300, y2 = 200; //Bottom-Right

    // Draw 4 sides using Bresenham
    BresenhamLine(x1, y1, x2, y1); // Top
    BresenhamLine(x2, y1, x2, y2); // Right
    BresenhamLine(x2, y2, x1, y2); // Bottom
    BresenhamLine(x1, y2, x1, y1); // Left
    getch();
    closegraph();
    return 0;
}