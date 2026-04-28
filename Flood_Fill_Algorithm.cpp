#include <graphics.h>
#include <conio.h>

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

    initgraph(&gd, &gm, (char*)"");

    // 🔷 Draw a closed shape
    setcolor(WHITE);
    rectangle(150, 150, 400, 350);

    // Get the background color inside the shape
    int oldColor = getpixel(200, 200);

    // 🔷 Apply Flood Fill
    floodFill(200, 200, oldColor, LIGHTGRAY);

    getch();
    closegraph();
    return 0;
}