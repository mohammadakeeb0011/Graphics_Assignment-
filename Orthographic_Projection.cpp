#include <graphics.h>
#include <stdio.h>

void drawCube() {
    int frontFace[4][2] = {{100, 100}, {200, 100}, {200, 200}, {100, 200}};
    int backFace[4][2] = {{150, 150}, {250, 150}, {250, 250}, {150, 250}};

    setcolor(WHITE);
    
    // Draw front face
    for (int i = 0; i < 4; i++) {
        line(frontFace[i][0], frontFace[i][1], frontFace[(i + 1) % 4][0], frontFace[(i + 1) % 4][1]);
    }

    // Draw back face
    for (int i = 0; i < 4; i++) {
        line(backFace[i][0], backFace[i][1], backFace[(i + 1) % 4][0], backFace[(i + 1) % 4][1]);
    }

    // Connect front and back faces
    for (int i = 0; i < 4; i++) {
        line(frontFace[i][0], frontFace[i][1], backFace[i][0], backFace[i][1]);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    drawCube();

    delay(5000);
    closegraph();
    return 0;
}
