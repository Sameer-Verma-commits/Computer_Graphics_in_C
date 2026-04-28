#include <graphics.h>
#include <conio.h>

void MidpointEllipse(int xc, int yc, int rx, int ry, int color)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Region 1
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy)
    {
        putpixel(xc + x, yc + y, color);
        putpixel(xc - x, yc + y, color);
        putpixel(xc + x, yc - y, color);
        putpixel(xc - x, yc - y, color);

        if (d1 < 0)
        {
            x++;
            dx += 2 * ry * ry;
            d1 += dx + ry * ry;
        }
        else
        {
            x++;
            y--;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d1 += dx - dy + ry * ry;
        }
    }

    // Region 2
    d2 = (ry * ry * (x + 0.5) * (x + 0.5)) +
         (rx * rx * (y - 1) * (y - 1)) -
         (rx * rx * ry * ry);

    while (y >= 0)
    {
        putpixel(xc + x, yc + y, color);
        putpixel(xc - x, yc + y, color);
        putpixel(xc + x, yc - y, color);
        putpixel(xc - x, yc - y, color);

        if (d2 > 0)
        {
            y--;
            dy -= 2 * rx * rx;
            d2 += rx * rx - dy;
        }
        else
        {
            y--;
            x++;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d2 += dx - dy + rx * rx;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    MidpointEllipse(150,100,100,70,WHITE);

    getch();
    closegraph();
    return 0;
}