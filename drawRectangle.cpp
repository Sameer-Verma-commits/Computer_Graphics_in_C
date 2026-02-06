#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    // Set drawing color
    setcolor(WHITE);

    // Draw rectangle
    rectangle(100, 100, 300, 200);

    getch();
    closegraph();
    return 0;
}
