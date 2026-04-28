#include <graphics.h>
#include <conio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    int fig[2][3] = {
        {100, 100, 1},
        {250, 250, 1}
    };

    int result[2][3];

    // Arbitrary point
    int xr = 150, yr = 100;

    // Draw original line
    line(fig[0][0], fig[0][1], fig[1][0], fig[1][1]);
    outtextxy(fig[1][0], fig[1][1], (char *)"Original Figure");
    // Angle
    float angle = 45;
    float rad = angle * M_PI / 180;

    // Translation to origin
    float T1[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {-xr, -yr, 1}
    };

    // Rotation
    float R[3][3] = {
        {cos(rad),  sin(rad), 0},
        {-sin(rad), cos(rad), 0},
        {0,         0,        1}
    };

    // Translate back
    float T2[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {xr, yr, 1}
    };

    float temp1[2][3], temp2[2][3];
    int i, j, k;

    // Step 1: fig * T1
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
        {
            temp1[i][j] = 0;
            for (k = 0; k < 3; k++){
                temp1[i][j] += fig[i][k] * T1[k][j];
            }
        }

    // Step 2: temp1 * R
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
        {
            temp2[i][j] = 0;
            for (k = 0; k < 3; k++){
                temp2[i][j] += temp1[i][k] * R[k][j];
            }
        }

    // Step 3: temp2 * T2
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
        {
            float temp = 0;
            for (k = 0; k < 3; k++){
                temp += temp2[i][k] * T2[k][j];
            }
            result[i][j] = round(temp);
        }

    // Draw rotated triangle
    line(result[0][0], result[0][1], result[1][0], result[1][1]);
    outtextxy(result[0][0], result[0][1], (char *)"Rotated Figure");

    getch();
    closegraph();
    return 0;
}