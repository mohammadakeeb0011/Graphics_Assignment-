#include <graphics.h>
#include <stdio.h>

#define d 200  // Distance of viewer from the projection plane

void projectPoint(int x, int y, int z, int *px, int *py) {
    // Perspective Projection Formula
    *px = x * d / (d + z);
    *py = y * d / (d + z);
}

void drawPerspectiveCube() {
    int frontFace[4][3] = {{-50, -50, 50}, {50, -50, 50}, {50, 50, 50}, {-50, 50, 50}};
    int backFace[4][3] = {{-50, -50, 150}, {50, -50, 150}, {50, 50, 150}, {-50, 50, 150}};

    int projectedFront[4][2], projectedBack[4][2];

    // Project front face
    for (int i = 0; i < 4; i++) {
        projectPoint(frontFace[i][0] + 200, frontFace[i][1] + 200, frontFace[i][2], &projectedFront[i][0], &projectedFront[i][1]);
    }

    // Project back face
    for (int i = 0; i < 4; i++) {
        projectPoint(backFace[i][0] + 200, backFace[i][1] + 200, backFace[i][2], &projectedBack[i][0], &projectedBack[i][1]);
    }

    setcolor(WHITE);

    // Draw front face
    for (int i = 0; i < 4; i++) {
        line(projectedFront[i][0], projectedFront[i][1], projectedFront[(i + 1) % 4][0], projectedFront[(i + 1) % 4][1]);
    }

    // Draw back face
    for (int i = 0; i < 4; i++) {
        line(projectedBack[i][0], projectedBack[i][1], projectedBack[(i + 1) % 4][0], projectedBack[(i + 1) % 4][1]);
    }

    // Connect front and back faces
    for (int i = 0; i < 4; i++) {
        line(projectedFront[i][0], projectedFront[i][1], projectedBack[i][0], projectedBack[i][1]);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    drawPerspectiveCube();

    delay(5000);
    closegraph();
    return 0;
}
