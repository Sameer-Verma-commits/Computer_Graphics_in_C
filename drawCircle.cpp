#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    // Get center of the screen
    int x = getmaxx() / 2;
    int y = getmaxy() / 2;

    // Set color
    setcolor(WHITE);

    // Draw circle at center
    circle(x, y, 100);

    getch();
    closegraph();
    return 0;
}
