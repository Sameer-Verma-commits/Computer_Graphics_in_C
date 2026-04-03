#include <graphics.h>
#include <conio.h>
#include <stdio.h>
int main()
{

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    int R[4][3];
    // Original square coordinates (row vectors)
    int sq[4][3] = {
        {100, 100, 1},
        {200, 100, 1},
        {200, 200, 1},
        {100, 200, 1}};
    // Draw original square
    line(sq[0][0], sq[0][1], sq[1][0], sq[1][1]);
    line(sq[1][0], sq[1][1], sq[2][0], sq[2][1]);
    line(sq[2][0], sq[2][1], sq[3][0], sq[3][1]);
    line(sq[3][0], sq[3][1], sq[0][0], sq[0][1]);
    outtextxy(sq[0][0], sq[0][1] - 20, (char *)"Original Square");

    // Translation matrix (row-vector)
    int tx = 110, ty = 110;
    int T[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {tx, ty, 1}};

    // multiplication of matrices.
    int i, j, a;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            R[i][j] = 0;
            for (a = 0; a < 3; a++)
            {

                R[i][j] += sq[i][a] * T[a][j];
            }
        }
    }
    // Draw translated square
    setcolor(RED);
    line(R[0][0], R[0][1], R[1][0], R[1][1]);
    line(R[1][0], R[1][1], R[2][0], R[2][1]);
    line(R[2][0], R[2][1], R[3][0], R[3][1]);
    line(R[3][0], R[3][1], R[0][0], R[0][1]);
    outtextxy(R[0][0], R[0][1] - 20, (char *)"Translation Square");

    getch();
    closegraph();
    return 0;
}