#include <graphics.h>
#include <conio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    int fig[2][3] = {
        {100, 100, 1},
        {200, 100, 1}
    };

    int result[2][3];

    // Draw original line
    line(fig[0][0], fig[0][1], fig[1][0], fig[1][1]);
    outtextxy(fig[1][0], fig[1][1], (char *)"Original Figure");

    // Angle
    float angle = 45;
    float rad = angle * M_PI / 180;
    // Rotation
    float R[3][3] = {
        {cos(rad),  sin(rad), 0},
        {-sin(rad), cos(rad), 0},
        {0,         0,        1}
    };

    int i,j,k;
    // multiply matrices
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
        {
            float temp = 0;
            for (k = 0; k < 3; k++){
                temp += fig[i][k] * R[k][j];
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