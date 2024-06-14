#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include "./Modules/Graphics.cpp"

#define maxNoOfLines 5

void liangBarskyClip(Coordinates_Int Window[2], Coordinates_Int Line[2]) {
    int x0 = Line[0].x, y0 = Line[0].y;
    int x1 = Line[1].x, y1 = Line[1].y;
    int xmin = Window[0].x;
    int ymin = Window[0].y;
    int xmax = Window[1].x;
    int ymax = Window[1].y;

    float t0 = 0.0, t1 = 1.0;
    float p[4], q[4];
    p[0] = -(x1 - x0); q[0] = x0 - xmin;
    p[1] = x1 - x0; q[1] = xmax - x0;
    p[2] = -(y1 - y0); q[2] = y0 - ymin;
    p[3] = y1 - y0; q[3] = ymax - y0;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) return; // Parallel line is outside
        } else {
            float t = q[i] / p[i];
            if (p[i] < 0) {
                if (t > t1) return;
                if (t > t0) t0 = t;
            } else {
                if (t < t0) return;
                if (t < t1) t1 = t;
            }
        }
    }

    int clippedX0 = x0 + t0 * (x1 - x0);
    int clippedY0 = y0 + t0 * (y1 - y0);
    int clippedX1 = x0 + t1 * (x1 - x0);
    int clippedY1 = y0 + t1 * (y1 - y0);

    line(clippedX0, clippedY0, clippedX1, clippedY1);
}

void Drawing(Coordinates_Int Window[2], Coordinates_Int Lines[maxNoOfLines][2], int numberOfLines) {
    rectangle(Window[0].x, Window[0].y, Window[1].x, Window[1].y);

    setcolor(GREEN);
    for (int i = 0; i < numberOfLines; i++) {
        line(Lines[i][0].x, Lines[i][0].y, Lines[i][1].x, Lines[i][1].y);
    }
}

void DrawingClippedLines(Coordinates_Int Window[2], Coordinates_Int Lines[maxNoOfLines][2], int numberOfLines) {
    setcolor(WHITE);
    rectangle(Window[0].x, Window[0].y, Window[1].x, Window[1].y);

    setcolor(GREEN);
    for (int i = 0; i < numberOfLines; i++) {
        liangBarskyClip(Window, Lines[i]);
    }
}

void WindowInputs(Coordinates_Int Window[2]) {
    printf("Enter the Minimum Coordinate of Window: ");
    scanf("%d %d", &Window[0].x, &Window[0].y);
    printf("Enter the Maximum Coordinate of Window: ");
    scanf("%d %d", &Window[1].x, &Window[1].y);
}

void LineInputs(int *numberOfLines, Coordinates_Int Lines[maxNoOfLines][2]) {
    while ((*numberOfLines > 5) || (*numberOfLines < 1)) {
        printf("Enter the Number of Lines: ");
        scanf("%d", numberOfLines);
    }

    system("cls");
    for (int i = 0; i < *numberOfLines; i++) {
        printf("Line %d:\n", i + 1);
        printf("\tEnter the Beginning Coordinate: ");
        scanf("%d %d", &Lines[i][0].x, &Lines[i][0].y);
        printf("\tEnter the Ending Coordinate: ");
        scanf("%d %d", &Lines[i][1].x, &Lines[i][1].y);
    }
}

int main() {
    Coordinates_Int Window[2], Lines[maxNoOfLines][2];
    int numberOfLines = 100;
    WindowInputs(Window);
    LineInputs(&numberOfLines, Lines);
    graphicsinits();

    Drawing(Window, Lines, numberOfLines);
    getch();

    cleardevice();

    DrawingClippedLines(Window, Lines, numberOfLines);
    getch();
    closegraph();
}
