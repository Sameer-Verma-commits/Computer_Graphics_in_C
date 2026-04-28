#include <graphics.h>
#include <conio.h>

// Recursive Boundary Fill function
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

// Recursive Flood Fill function
void floodFill(int x, int y, int oldColor, int newColor) {
    int current = getpixel(x, y);

    // Fill only if current pixel matches old color
    if (current == oldColor) {
        putpixel(x, y, newColor);

        floodFill(x + 1, y, oldColor, newColor);
        floodFill(x - 1, y, oldColor, newColor);
        floodFill(x, y + 1, oldColor, newColor);
        floodFill(x, y - 1, oldColor, newColor);
    }
}
int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm,(char*)"");

    // Draw a closed boundary (rectangle + circle inside)
    setcolor(WHITE);
    // LEFT RECTANGLE (Boundary Fill)
    rectangle(100, 150, 300, 350);
    outtextxy(120, 120, (char*)"Boundary Fill");

    boundaryFill(150, 200, LIGHTGRAY, WHITE);

    // RIGHT RECTANGLE (Flood Fill)
    rectangle(350, 150, 550, 350);
    outtextxy(380, 120, (char*)"Flood Fill");

    int oldColor = getpixel(400, 200);
    floodFill(400, 200, oldColor, LIGHTGRAY);
    getch();
    closegraph();
    return 0;
}