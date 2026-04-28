#include <graphics.h>
#include <conio.h>
#include <math.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    int R[3][3];
    // Original triangle coordinates (row vectors)
    int tri[3][3] = {
        {100, 100, 1},
        {150, 50, 1},
        {200, 100, 1}};

    // Draw original triangle
    line(tri[0][0], tri[0][1], tri[1][0], tri[1][1]);
    line(tri[1][0], tri[1][1], tri[2][0], tri[2][1]);
    line(tri[2][0], tri[2][1], tri[0][0], tri[0][1]);
    outtextxy(tri[0][0], tri[0][1] + 20, (char *)"Original Triangle");

     // Angle
    float angle = 45;
    float rad = angle * 3.1416 / 180;
     // Rotation matrix (row vector form)
    float Rot[3][3] = {
        {cos(rad),  sin(rad), 0},
        {-sin(rad), cos(rad), 0},
        {0,         0,        1}
    };

     // multiplication of matrices.
    int i, j, a;
    float temp2;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp2 = 0;
            for (a = 0; a < 3; a++)
            {

                temp2 += tri[i][a] * Rot[a][j];
            }
            R[i][j] = round(temp2);
        }
    }
    // Draw rotated triangle
    line(R[0][0], R[0][1], R[1][0], R[1][1]);
    line(R[1][0], R[1][1], R[2][0], R[2][1]);
    line(R[2][0], R[2][1], R[0][0], R[0][1]);
    outtextxy(R[0][0], R[0][1] + 20, (char *)"Rotated Triangle");
    getch();
    closegraph();
    return 0;
}