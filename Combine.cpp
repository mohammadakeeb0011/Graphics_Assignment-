#include <graphics.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159

void transformPoint(int x, int y, float sx, float sy, float angle, int tx, int ty, int *newX, int *newY) {
    float radian = angle * (PI / 180.0);  // Convert angle to radians

    // Apply Scaling
    float scaledX = x * sx;
    float scaledY = y * sy;

    // Apply Rotation
    float rotatedX = scaledX * cos(radian) - scaledY * sin(radian);
    float rotatedY = scaledX * sin(radian) + scaledY * cos(radian);

    // Apply Translation
    *newX = round(rotatedX + tx);
    *newY = round(rotatedY + ty);
}

void transformRectangle(int x1, int y1, int x2, int y2, float sx, float sy, float angle, int tx, int ty) {
    int newX1, newY1, newX2, newY2, newX3, newY3, newX4, newY4;

    // Apply transformation to each corner of the rectangle
    transformPoint(x1, y1, sx, sy, angle, tx, ty, &newX1, &newY1);
    transformPoint(x2, y1, sx, sy, angle, tx, ty, &newX2, &newY2);
    transformPoint(x2, y2, sx, sy, angle, tx, ty, &newX3, &newY3);
    transformPoint(x1, y2, sx, sy, angle, tx, ty, &newX4, &newY4);

    // Draw the transformed rectangle
    line(newX1, newY1, newX2, newY2);
    line(newX2, newY2, newX3, newY3);
    line(newX3, newY3, newX4, newY4);
    line(newX4, newY4, newX1, newY1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    float sx, sy, angle;
    int tx, ty;

    // Draw the original rectangle
    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);

    // Get transformation parameters from user
    printf("Enter scaling factors (Sx, Sy): ");
    scanf("%f %f", &sx, &sy);

    printf("Enter rotation angle (in degrees): ");
    scanf("%f", &angle);

    printf("Enter translation values (Tx, Ty): ");
    scanf("%d %d", &tx, &ty);

    // Apply combined transformation
    setcolor(YELLOW);
    transformRectangle(x1, y1, x2, y2, sx, sy, angle, tx, ty);

    delay(5000);
    closegraph();
    return 0;
}
