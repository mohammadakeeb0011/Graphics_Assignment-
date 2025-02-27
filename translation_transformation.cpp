#include <graphics.h>
#include <stdio.h>

void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

void translateRectangle(int x1, int y1, int x2, int y2, int dx, int dy) {
    rectangle(x1 + dx, y1 + dy, x2 + dx, y2 + dy);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    int dx, dy;

    // Draw the original rectangle
    setcolor(WHITE);
    drawRectangle(x1, y1, x2, y2);

    // Get translation values from user
    printf("Enter translation values dx and dy: ");
    scanf("%d %d", &dx, &dy);

    // Draw the translated rectangle
    setcolor(YELLOW);
    translateRectangle(x1, y1, x2, y2, dx, dy);

    delay(5000);
    closegraph();
    return 0;
}
