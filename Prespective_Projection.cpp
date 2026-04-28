#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Perspective projection function
void project(int x, int y, int z, int *xp, int *yp, int d) {
    *xp = (x * d) / (z + d);
    *yp = (y * d) / (z + d);
}

// Draw cube using projected points
void drawCube(int cube[8][3], int d) {
    int i;
    int xp[8], yp[8];

    // Project all 8 vertices
    for(i = 0; i < 8; i++) {
        project(cube[i][0], cube[i][1], cube[i][2], &xp[i], &yp[i], d);

        // Shift to screen center
        xp[i] += 300;
        yp[i] += 200;
    }

    // Front face
    for(i = 0; i < 4; i++) {
        line(xp[i], yp[i], xp[(i+1)%4], yp[(i+1)%4]);
    }

    // Back face
    for(i = 4; i < 8; i++) {
        line(xp[i], yp[i], xp[4 + (i+1)%4], yp[4 + (i+1)%4]);
    }

    // Side edges
    for(i = 0; i < 4; i++) {
        line(xp[i], yp[i], xp[i+4], yp[i+4]);
    }
}

int main() {
    int gd = DETECT, gm;

    // Cube vertices (3D)
    int cube[8][3] = {
        {50, 50, 50},
        {150, 50, 50},
        {150, 150, 50},
        {50, 150, 50},
        {70, 70, 150},
        {170, 70, 150},
        {170, 170, 150},
        {70, 170, 150}
    };

    int d = 200; // distance of viewer

    initgraph(&gd, &gm, (char*)"");

    setcolor(WHITE);
    drawCube(cube, d);

    getch();
    closegraph();
    return 0;
}