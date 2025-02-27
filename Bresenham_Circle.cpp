#include <graphics.h>
#include <stdio.h>

void drawCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void bresenhamCircle(int xc, int yc, int r) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x = 0, y = r;
    int p = 3 - 2 * r;  // Initial decision parameter

    while (x <= y) {
        drawCircle(xc, yc, x, y);
        x++;
        if (p < 0)
            p += 4 * x + 6;
        else {
            y--;
            p += 4 * (x - y) + 10;
        }
    }

    delay(100000);
    closegraph();
}

int main() {
    int xc, yc, r;
    
    printf("Enter the coordinates of the center (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);
    
    bresenhamCircle(xc, yc, r);
    return 0;
}
