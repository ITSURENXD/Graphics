#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include "./Modules/Graphics.cpp"

#define maxNoOfLines 5

// Define the region codes
#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

int computeOutCode(int x, int y, Coordinates_Int Window[2]) {
    int xmin = Window[0].x;
    int ymin = Window[0].y;
    int xmax = Window[1].x;
    int ymax = Window[1].y;

    int code = INSIDE; // initialized as being inside of clip window

    if (x < xmin)       // to the left of clip window
        code |= LEFT;
    else if (x > xmax)  // to the right of clip window
        code |= RIGHT;
    if (y < ymin)       // below the clip window
        code |= BOTTOM;
    else if (y > ymax)  // above the clip window
        code |= TOP;

    return code;
}

void CohenSutherlandClip(Coordinates_Int Window[2], Coordinates_Int Line[2]) {
    int x0 = Line[0].x, y0 = Line[0].y;
    int x1 = Line[1].x, y1 = Line[1].y;
    int xmin = Window[0].x;
    int ymin = Window[0].y;
    int xmax = Window[1].x;
    int ymax = Window[1].y;

    // Compute region codes
    int outcode0 = computeOutCode(x0, y0, Window);
    int outcode1 = computeOutCode(x1, y1, Window);
    int accept = 0;

    while (1) {
        if ((outcode0 == 0) && (outcode1 == 0)) {
            // Bitwise OR is 0: both points inside window; trivially accept and exit loop
            accept = 1;
            break;
        } else if (outcode0 & outcode1) {
            // Bitwise AND is not 0: both points share an outside zone; trivially reject and exit loop
            break;
        } else {
            // Failed both tests, so partially outside, calculate the line segment to clip
            int x, y;
            // At least one endpoint is outside the clip rectangle; pick it.
            int outcodeOut = outcode0 ? outcode0 : outcode1;

            // Now find the intersection point using formulas y = y0 + slope * (x - x0), x = x0 + (1 / slope) * (y - y0)
            if (outcodeOut & TOP) {           // point is above the clip rectangle
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                y = ymax;
            } else if (outcodeOut & BOTTOM) { // point is below the clip rectangle
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            } else if (outcodeOut & RIGHT) {  // point is to the right of clip rectangle
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            } else if (outcodeOut & LEFT) {   // point is to the left of clip rectangle
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }

            // Now we move outside point to intersection point to clip
            if (outcodeOut == outcode0) {
                x0 = x;
                y0 = y;
                outcode0 = computeOutCode(x0, y0, Window);
            } else {
                x1 = x;
                y1 = y;
                outcode1 = computeOutCode(x1, y1, Window);
            }
        }
    }
    if (accept) {
        // Draw the clipped line
        line(x0, y0, x1, y1);
    }
}

void InitialDrawing(Coordinates_Int Window[2], Coordinates_Int Lines[maxNoOfLines][2], int numberOfLines) {
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
        CohenSutherlandClip(Window, Lines[i]);
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

    InitialDrawing(Window, Lines, numberOfLines);
    getch();
    cleardevice();
    
    DrawingClippedLines(Window, Lines, numberOfLines);
    getch();
    closegraph();
}
