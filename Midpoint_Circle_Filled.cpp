#include <graphics.h>
#include <conio.h>
void drawFilledCircle(int xc, int yc, int x, int y)
{
    // Draw horizontal lines between symmetric points
    line(xc - x, yc + y, xc + x, yc + y);
    line(xc - x, yc - y, xc + x, yc - y);
    line(xc - y, yc + x, xc + y, yc + x);
    line(xc - y, yc - x, xc + y, yc - x);
}
void MidpointCircleFilled(int xc, int yc, int r)
{
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y)
    {
        drawFilledCircle(xc, yc, x, y);

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
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    MidpointCircleFilled(150, 150, 100);
    getch();
    closegraph();
    return 0;
}