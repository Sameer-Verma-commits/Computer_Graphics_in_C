#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    // Set drawing color
    setcolor(WHITE);

    // Horizontal line (y is constant)
    line(50, 200, 400, 200);

    // Vertical line (x is constant)
    line(200, 50, 200, 350);

    getch();
    closegraph();
    return 0;
}
