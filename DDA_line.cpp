#include <graphics.h>
#include <stdio.h>
#include <math.h>

void DDA(int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    float dx = x2 - x1, dy = y2 - y1, steps;
    steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
    float Xinc = dx / steps, Yinc = dy / steps;
    float X = x1, Y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(X), round(Y), WHITE);
        X += Xinc;
        Y += Yinc;
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
    
    DDA(x1, y1, x2, y2);
    return 0;
}
