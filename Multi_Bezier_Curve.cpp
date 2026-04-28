#include <graphics.h>
#include <conio.h>
#include <math.h>

// Function to draw one Bezier curve
void drawBezier(int x[4], int y[4], int color) {
    float t;
    int xt, yt;

    setcolor(color);

    for (t = 0.0; t <= 1.0; t += 0.001) {
        xt = pow(1 - t, 3) * x[0] +
             3 * t * pow(1 - t, 2) * x[1] +
             3 * pow(t, 2) * (1 - t) * x[2] +
             pow(t, 3) * x[3];

        yt = pow(1 - t, 3) * y[0] +
             3 * t * pow(1 - t, 2) * y[1] +
             3 * pow(t, 2) * (1 - t) * y[2] +
             pow(t, 3) * y[3];

        putpixel(xt, yt, color);
    }
}

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, (char*)"");

    //  Curve 1
    int x1[4] = {100, 150, 250, 300};
    int y1[4] = {300, 100, 100, 300};

    //  Curve 2
    int x2[4] = {300, 350, 450, 500};
    int y2[4] = {300, 500, 100, 300};

    // Curve 3
    int x3[4] = {150, 250, 350, 450};
    int y3[4] = {400, 200, 400, 200};

    // Draw all curves
    drawBezier(x1, y1, WHITE);
    drawBezier(x2, y2, DARKGRAY);
    drawBezier(x3, y3, LIGHTGRAY);

    getch();
    closegraph();
    return 0;
}