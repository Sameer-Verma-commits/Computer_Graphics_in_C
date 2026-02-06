#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
void drawDDA(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = (abs(dx) > abs(dy) ? abs(dx) : abs(dy));
    float x_inc = dx / steps;
    float y_inc = dy / steps;
    float x = x1;
    float y = y1;
    for (int s = 0; s <= steps; s++)
    {
        putpixel(round(x), round(y), WHITE);
        x += x_inc;
        y += y_inc;
    }
}
int main()
{
    int X[3], Y[3];
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    printf("Drawing Triangle: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("Enter Coordinates x for %c: ", char('A' + i));
        scanf("%d", &X[i]);
        printf("Enter Coordinates y for %c: ", char('A' + i));
        scanf("%d", &Y[i]);
    }
    drawDDA(X[0], Y[0], X[1], Y[1]); // A->B line
    drawDDA(X[0], Y[0], X[2], Y[2]); // A->C line
    drawDDA(X[1], Y[1], X[2], Y[2]); // B->C line
    getch();
    closegraph();
    return 0;
}