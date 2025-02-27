#include <graphics.h>
#include <stdio.h>

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int dx = x2 - x1, dy = y2 - y1;
    int p = 2 * dy - dx;  // Decision parameter
    int x = x1, y = y1;

    putpixel(x, y, WHITE);

    while (x < x2) {
        x++;
        if (p < 0)
            p += 2 * dy;
        else {
            y++;
            p += 2 * (dy - dx);
        }
        putpixel(x, y, WHITE);
    }

    delay(5000);
    closegraph();
}

int main() {
    int x1, y1, x2, y2;
    
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    
    bresenhamLine(x1, y1, x2, y2);
    return 0;
}
