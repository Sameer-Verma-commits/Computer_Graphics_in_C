#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Function to draw cube using simple projection
void drawCube(int cube[8][3]) {
    int i;

    // Front face
    for(i = 0; i < 4; i++) {
        line(cube[i][0], cube[i][1],
             cube[(i+1)%4][0], cube[(i+1)%4][1]);
    }

    // Back face
    for(i = 4; i < 8; i++) {
        line(cube[i][0], cube[i][1],
             cube[4 + (i+1)%4][0], cube[4 + (i+1)%4][1]);
    }

    // Connecting edges
    for(i = 0; i < 4; i++) {
        line(cube[i][0], cube[i][1],
             cube[i+4][0], cube[i+4][1]);
    }
}

// Function to translate cube (Row Vector Method)
void translate(int cube[8][3], int tx, int ty, int tz) {
    int i;

    for(i = 0; i < 8; i++) {
        cube[i][0] = cube[i][0] + tx;
        cube[i][1] = cube[i][1] + ty;
        cube[i][2] = cube[i][2] + tz;
    }
}

int main() {
    int gd = DETECT, gm;

    // Cube vertices (x, y, z)
    int cube[8][3] = {
        {100,100,100},
        {200,100,100},
        {200,200,100},
        {100,200,100},
        {120,120,200},
        {220,120,200},
        {220,220,200},
        {120,220,200}
    };

    int tx = 50, ty = 50, tz = 50;

    initgraph(&gd, &gm, (char*)"");

    // Draw original cube
    setcolor(WHITE);
    drawCube(cube);
    outtextxy(80,80,(char*)"Original Cube");
    // Apply translation
    translate(cube, tx, ty, tz);

    // Draw translated cube
    setcolor(LIGHTGRAY);
    drawCube(cube);
    outtextxy(130,130,(char*)"Translated Cube");
    getch();
    closegraph();
    return 0;
}