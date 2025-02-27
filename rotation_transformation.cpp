#include <graphics.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159

void rotatePoint(int x, int y, float angle, int *newX, int *newY) {
    float radian = angle * (PI / 180.0);  // Convert degrees to radians
    *newX = round(x * cos(radian) - y * sin(radian));
    *newY = round(x * sin(radian) + y * cos(radian));
}

void drawRotatedRectangle(int x1, int y1, int x2, int y2, float angle) {
    int newX1, newY1, newX2, newY2, newX3, newY3, newX4, newY4;

    // Calculate rotated coordinates for each corner
    rotatePoint(x1, y1, angle, &newX1, &newY1);
    rotatePoint(x2, y1, angle, &newX2, &newY2);
    rotatePoint(x2, y2, angle, &newX3, &newY3);
    rotatePoint(x1, y2, angle, &newX4, &newY4);

    // Draw the rotated rectangle
    line(newX1, newY1, newX2, newY2);
    line(newX2, newY2, newX3, newY3);
    line(newX3, newY3, newX4, newY4);
    line(newX4, newY4, newX1, newY1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    float angle;

    // Draw the original rectangle
    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);

    // Get rotation angle from user
    printf("Enter rotation angle (in degrees): ");
    scanf("%f", &angle);

    // Draw the rotated rectangle
    setcolor(YELLOW);
    drawRotatedRectangle(x1, y1, x2, y2, angle);

    delay(5000);
    closegraph();
    return 0;
}
