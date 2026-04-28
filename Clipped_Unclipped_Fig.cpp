#include <graphics.h>
#include <conio.h>

#define MAX 20

typedef struct {
    float x, y;
} Point;

Point input[MAX], output[MAX], original[MAX];
int inCount, outCount;

// Clipping window
float xmin = 150, ymin = 150, xmax = 450, ymax = 350;

// Check inside
int inside(Point p, int edge) {
    switch(edge) {
        case 0: return (p.x >= xmin); // Left
        case 1: return (p.x <= xmax); // Right
        case 2: return (p.y >= ymin); // Bottom
        case 3: return (p.y <= ymax); // Top
    }
    return 0;
}

// Intersection
Point intersect(Point p1, Point p2, int edge) {
    Point p;
    float m = 0;

    if (p2.x != p1.x)
        m = (p2.y - p1.y) / (p2.x - p1.x);

    switch(edge) {
        case 0: // Left
            p.x = xmin;
            p.y = p1.y + (xmin - p1.x) * m;
            break;

        case 1: // Right
            p.x = xmax;
            p.y = p1.y + (xmax - p1.x) * m;
            break;

        case 2: // Bottom
            p.y = ymin;
            if (p2.x != p1.x)
                p.x = p1.x + (ymin - p1.y) / m;
            break;

        case 3: // Top
            p.y = ymax;
            if (p2.x != p1.x)
                p.x = p1.x + (ymax - p1.y) / m;
            break;
    }
    return p;
}

// Clipping
void clip(int edge) {
    int i;
    Point p1, p2;
    outCount = 0;

    for(i = 0; i < inCount; i++) {
        p1 = input[i];
        p2 = input[(i + 1) % inCount];

        if (inside(p1, edge) && inside(p2, edge)) {
            output[outCount++] = p2;
        }
        else if (inside(p1, edge) && !inside(p2, edge)) {
            output[outCount++] = intersect(p1, p2, edge);
        }
        else if (!inside(p1, edge) && inside(p2, edge)) {
            output[outCount++] = intersect(p1, p2, edge);
            output[outCount++] = p2;
        }
    }

    for(i = 0; i < outCount; i++)
        input[i] = output[i];

    inCount = outCount;
}

// Draw polygon
void drawPolygon(Point poly[], int count, int color) {
    int i;
    setcolor(color);
    for(i = 0; i < count; i++) {
        line(poly[i].x, poly[i].y,
             poly[(i+1)%count].x, poly[(i+1)%count].y);
    }
}

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, (char*)"");

    // 🔷 Predefined polygon
    inCount = 5;
    input[0] = (Point){100, 200};
    input[1] = (Point){200, 100};
    input[2] = (Point){500, 150};
    input[3] = (Point){550, 300};
    input[4] = (Point){300, 400};
 
    // Save original
    int i;
    for(i = 0; i < inCount; i++)
        original[i] = input[i];

    // -------- SCREEN 1: UNCLIPPED --------
    rectangle(xmin, ymin, xmax, ymax);
    outtextxy(200, 50, (char*)"Original Polygon (Unclipped)");
    drawPolygon(original, inCount, WHITE);

    getch();
    cleardevice();

    // -------- CLIPPING --------

    for(i = 0; i < 4; i++)
        clip(i);

    // -------- SCREEN 2: CLIPPED --------
    rectangle(xmin, ymin, xmax, ymax);
    outtextxy(220, 50, (char*)"Clipped Polygon");
    drawPolygon(input, inCount, WHITE);

    getch();
    closegraph();
    return 0;
}