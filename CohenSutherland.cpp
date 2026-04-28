#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define INSIDE 0   // 0000
#define LEFT   1   // 0001
#define RIGHT  2   // 0010
#define BOTTOM 4   // 0100
#define TOP    8   // 1000

// Clipping window boundaries
float xmin = 100, ymin = 100, xmax = 300, ymax = 300;

// Function to compute region code
int computeCode(float x, float y) {
int code = INSIDE;

if (x < xmin)
    code |= LEFT;
else if (x > xmax)
    code |= RIGHT;
if (y < ymin)
    code |= BOTTOM;
else if (y > ymax)
    code |= TOP;

return code;

}

// Cohen-Sutherland clipping algorithm
void cohenSutherlandClip(float x1, float y1, float x2, float y2) {
int code1 = computeCode(x1, y1);
int code2 = computeCode(x2, y2);

int accept = 0;

while (1) {
    if ((code1 == 0) && (code2 == 0)) {
        accept = 1;
        break;
    }
    else if (code1 & code2) {
        break;
    }
    else {
        float x, y;
        int code_out = code1 ? code1 : code2;

        if (code_out & TOP) {
            x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
            y = ymax;
        }
        else if (code_out & BOTTOM) {
            x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
            y = ymin;
        }
        else if (code_out & RIGHT) {
            y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
            x = xmax;
        }
        else if (code_out & LEFT) {
            y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
            x = xmin;
        }

        if (code_out == code1) {
            x1 = x;
            y1 = y;
            code1 = computeCode(x1, y1);
        }
        else {
            x2 = x;
            y2 = y;
            code2 = computeCode(x2, y2);
        }
    }
}

if (accept) {
    line(x1, y1, x2, y2);
    printf("Line Accepted");
}
else {
    printf("Line rejected");
}


}

int main() {
int gd = DETECT, gm;

initgraph(&gd, &gm, (char*)"");

// Draw clipping window
rectangle(xmin, ymin, xmax, ymax);

int x1 = 50, y1 = 50, x2 = 350, y2 = 350;

// Clipped line
cohenSutherlandClip(x1, y1, x2, y2);

getch();
closegraph();
return 0;

}
