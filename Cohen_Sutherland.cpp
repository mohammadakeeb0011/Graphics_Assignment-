#include <graphics.h>
#include <stdio.h>

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int xmin = 100, ymin = 100, xmax = 300, ymax = 300; // Clipping window coordinates

int computeCode(int x, int y) {
    int code = 0;
    if (x < xmin) code |= LEFT;
    if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    if (y > ymax) code |= TOP;
    return code;
}

void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = 1;  // Both endpoints inside
            break;
        } else if (code1 & code2) {
            break;  // Both endpoints share an outside region, trivially rejected
        } else {
            int codeOut;
            int x, y;

            if (code1 != 0) codeOut = code1; // Pick outside point
            else codeOut = code2;

            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        setcolor(YELLOW);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, x2, y2;

    // Draw the clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Get line coordinates from user
    printf("Enter the coordinates of the line (x1, y1, x2, y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Draw the original line
    setcolor(RED);
    line(x1, y1, x2, y2);

    // Apply Cohen-Sutherland Clipping
    cohenSutherlandClip(x1, y1, x2, y2);

    delay(5000);
    closegraph();
    return 0;
}
