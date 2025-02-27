#include <graphics.h>
#include <stdio.h>

void floodFill(int x, int y, int fillColor, int oldColor) {
    int currentColor = getpixel(x, y);
    
    if (currentColor == oldColor) {
        putpixel(x, y, fillColor);
        
        // Recursive calls in 4 directions
        floodFill(x + 1, y, fillColor, oldColor);
        floodFill(x - 1, y, fillColor, oldColor);
        floodFill(x, y + 1, fillColor, oldColor);
        floodFill(x, y - 1, fillColor, oldColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw a closed polygon (rectangle)
    rectangle(100, 100, 300, 300);
    
    // Call flood fill function
    floodFill(150, 150, YELLOW, BLACK);

    delay(5000);
    closegraph();
    return 0;
}
