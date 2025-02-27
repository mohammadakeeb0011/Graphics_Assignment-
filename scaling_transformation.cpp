#include <graphics.h>
#include <stdio.h>

void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

void scaleRectangle(int x1, int y1, int x2, int y2, float sx, float sy) {
    int newX1 = x1 * sx;
    int newY1 = y1 * sy;
    int newX2 = x2 * sx;
    int newY2 = y2 * sy;

    rectangle(newX1, newY1, newX2, newY2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    float sx, sy;

    // Draw the original rectangle
    setcolor(WHITE);
    drawRectangle(x1, y1, x2, y2);

    // Get scaling factors from user
    printf("Enter scaling factors Sx and Sy: ");
    scanf("%f %f", &sx, &sy);

    // Draw the scaled rectangle
    setcolor(YELLOW);
    scaleRectangle(x1, y1, x2, y2, sx, sy);

    delay(5000);
    closegraph();
    return 0;
}
