#include <graphics.h>
#include <conio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    // Line (2 points)
    int line1[2][3] = {
        {100, 100, 1},
        {200, 100, 1}
    };

    int result[2][3];

    // Draw original line
    line(line1[0][0], line1[0][1], line1[1][0], line1[1][1]);
    outtextxy(line1[1][0], line1[1][1], (char *)"Original Figure");

    // Translation values
    int tx = 50, ty = 50;

    // Rotation angle
    float angle = 45;
    float rad = angle * M_PI / 180;

    // Translation matrix
    float T[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {(float)tx, (float)ty, 1}
    };

    // Rotation matrix (row vector)
    float R[3][3] = {
        {cos(rad),  sin(rad), 0},
        {-sin(rad), cos(rad), 0},
        {0,         0,        1}
    };

    float temp[2][3];
    int i, j, k;

    // Step 1: line * T
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
        {
            temp[i][j] = 0;
            for (k = 0; k < 3; k++){
                temp[i][j] += line1[i][k] * T[k][j];
            }
        }

    // Step 2: temp * R
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
        {
            float temp2 = 0;
            for (k = 0; k < 3; k++){
                temp2 += temp[i][k] * R[k][j];
            }
            result[i][j]=round(temp2);
        }

    // Draw transformed line
    line(result[0][0],result[0][1],result[1][0],result[1][1]);
    outtextxy(result[0][0], result[0][1], (char *)"Rotated Figure");
    
    getch();
    closegraph();
    return 0;
}