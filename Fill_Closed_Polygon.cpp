#include <graphics.h>
#include <conio.h>

// Boundary Fill (4-connected)
void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
    int current = getpixel(x, y);

    if (current != boundaryColor && current != fillColor) {
        putpixel(x, y, fillColor);

        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
    }
}

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, (char*)"");

    //  Draw a closed polygon (pentagon)
    int x[] = {200, 300, 400, 350, 250};
    int y[] = {150, 100, 150, 300, 300};
    int n = 5;

    setcolor(WHITE);
    //  Draw edges manually (ensures closure)
    for (int i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }

    //  Fill inside polygon
    boundaryFill(300, 200, LIGHTGRAY, WHITE);

    getch();
    closegraph();
    return 0;
}