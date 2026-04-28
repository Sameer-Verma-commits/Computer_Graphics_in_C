#include <graphics.h>
#include <conio.h>

void MidpointEllipse(int xc, int yc, int rx, int ry)
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
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

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
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

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
    int xc, yc, rx, ry, e;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    printf("Enter Number of Ellipse: ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        printf("\nValues for Ellipse %d \n", i+ 1);
        printf("Enter x-Center: ");
        scanf("%d", &xc);
        printf("Enter y-Center: ");
        scanf("%d", &yc);
        printf("Enter x-Raius: ");
        scanf("%d", &rx);
        printf("Enter y-Radius: ");
        scanf("%d", &ry);
        MidpointEllipse(xc,yc,rx,ry);
    }

    getch();
    closegraph();
    return 0;
}