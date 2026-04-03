#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
int main()
{
    int tx, ty;
    float sx, sy;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    printf("Translation Value:\n");
    printf("Enter X-axis Translation (tx): ");
    scanf("%d", &tx);
    printf("Enter Y-axis Translation (ty): ");
    scanf("%d", &ty);
    printf("Scaling Factor Value:\n");
    printf("Enter X-axis Scale (sx): ");
    scanf("%f", &sx);
    printf("Enter Y-axis Scale (sy): ");
    scanf("%f", &sy);

    int R[4][3], temp[4][3];
    // Rectangle coordinates (row vectors)
    int rect[4][3] = {
        {100, 100, 1},
        {300, 100, 1},
        {300, 200, 1},
        {100, 200, 1}};

    // Draw original Rectangle
    line(rect[0][0], rect[0][1], rect[1][0], rect[1][1]);
    line(rect[1][0], rect[1][1], rect[2][0], rect[2][1]);
    line(rect[2][0], rect[2][1], rect[3][0], rect[3][1]);
    line(rect[3][0], rect[3][1], rect[0][0], rect[0][1]);
    outtextxy(rect[0][0], rect[0][1] - 20, (char *)"Original Rectangle");

    // Scaling matrix (row-vector)
    float S[3][3] = {
        {sx, 0, 0},
        {0, sy, 0},
        {0, 0, 1}};

    // multiplication of matrices.
    int i, j, a;
    float temp2;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp2 = 0;
            for (a = 0; a < 3; a++)
            {

                temp2 += rect[i][a] * S[a][j];
            }
            temp[i][j] = round(temp2);
        }
    }
    // Translation matrix (row-vector)
    int T[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {tx, ty, 1}};

    // multiplication of matrices.
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            R[i][j] = 0;
            for (a = 0; a < 3; a++)
            {

                R[i][j] += temp[i][a] * T[a][j];
            }
        }
    }

    // Draw translated Rectasngle
    line(R[0][0], R[0][1], R[1][0], R[1][1]);
    line(R[1][0], R[1][1], R[2][0], R[2][1]);
    line(R[2][0], R[2][1], R[3][0], R[3][1]);
    line(R[3][0], R[3][1], R[0][0], R[0][1]);
    outtextxy(R[0][0], R[0][1] - 20, (char *)"Translation & Scaled Rectangle");

    getch();
    closegraph();
    return 0;
}