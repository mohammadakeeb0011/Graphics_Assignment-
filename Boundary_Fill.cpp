#include <graphics.h>
#include <stdio.h>

void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);

    if (currentColor != boundaryColor && currentColor != fillColor) {
        putpixel(x, y, fillColor);

        // Recursive calls in 4 directions
        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw a closed polygon (rectangle in this case)
    rectangle(100, 100, 300, 300);

    // Call boundary fill function
    boundaryFill(150, 150, YELLOW, WHITE);

    delay(5000);
    closegraph();
    return 0;
}
