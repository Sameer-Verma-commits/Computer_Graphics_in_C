#include <graphics.h>
#include <conio.h>
#include <math.h>

// Function to draw Bezier curve
void drawBezier(int x[4], int y[4]) {
    float t;
    int xt, yt;

    for (t = 0.0; t <= 1.0; t += 0.001) {
        xt = pow(1 - t, 3) * x[0] +
             3 * t * pow(1 - t, 2) * x[1] +
             3 * pow(t, 2) * (1 - t) * x[2] +
             pow(t, 3) * x[3];

        yt = pow(1 - t, 3) * y[0] +
             3 * t * pow(1 - t, 2) * y[1] +
             3 * pow(t, 2) * (1 - t) * y[2] +
             pow(t, 3) * y[3];

        putpixel(xt, yt, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, (char*)"");

    // 🔷 Predefined control points
    int x[4] = {100, 200, 300, 400};
    int y[4] = {300, 100, 400, 300};

    // Draw control polygon
    setcolor(LIGHTGRAY);
    for (int i = 0; i < 3; i++) {
        line(x[i], y[i], x[i+1], y[i+1]);
    }

    // Draw control points
    for (int i = 0; i < 4; i++) {
        circle(x[i], y[i], 3);
    }

    // Draw Bezier curve
    setcolor(WHITE);
    drawBezier(x, y);

    getch();
    closegraph();
    return 0;
}