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

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm,(char*)"");

    // 🔷 Draw a closed boundary (rectangle + circle inside)
    setcolor(WHITE);
    rectangle(150, 150, 400, 350);
    circle(275, 250, 50);  // extra shape inside

    // Boundary color = WHITE
    // Fill color = LIGHTGRAY

    // 🔷 Call boundary fill from a point inside
    boundaryFill(200, 200, LIGHTGRAY, WHITE);

    getch();
    closegraph();
    return 0;
}