#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include "./Modules/Graphics.cpp" 


void DDA(Coordinates_Int Beginning, Coordinates_Int Ending) {
    Coordinates_Int Difference;
    Coordinates_Float Increment, Temp;
    int steps;

    // Setting Up The differences
    Difference.x = Ending.x - Beginning.x;
    Difference.y = Ending.y - Beginning.y;
    printf("\n Diff x: %d y: %d", Difference.x, Difference.y);

    // Setting up the Steps
    if (abs(Difference.x) > abs(Difference.y)) {
        steps = abs(Difference.x);
    } else {
        steps = abs(Difference.y);
    }
    printf("\n Steps: %d", steps);

    // Setting up the Increments
    Increment.x = (float)Difference.x / steps;
    Increment.y = (float)Difference.y / steps;
    printf("\n Increments x: %f y: %f", Increment.x, Increment.y);

    // Actual working
    Temp.x = Beginning.x;
    Temp.y = Beginning.y;
    graphicsinits();
    outtextxy(200, 20, "DDA"); 
    printf("\n Putting pixel at ( %f , %f )", (float)Temp.x, (float)Temp.y);
    putpixel(round(Temp.x), round(Temp.y), WHITE);
    for (int i = 0; i < steps; i++) {
        delay(5);
        Temp.y += Increment.y;
        Temp.x += Increment.x;
        printf("\n Plot Values: x: %d y: %d", (int)round(Temp.x), (int)round(Temp.y));
        putpixel(round(Temp.x), round(Temp.y), WHITE);
    }

    // Labeling
    outtextxy(Beginning.x, Beginning.y, "(x1,y1)");
    outtextxy(Ending.x, Ending.y, "(x2,y2)");
}

int main() {
    system("cls");
    Coordinates_Int Beginning, Ending;

    // Getting Inputs
    printf("Enter The Starting Coordinate : ");
    scanf("%d %d", &Beginning.x, &Beginning.y);
    printf("Enter The Ending Coordinate: ");
    scanf("%d %d", &Ending.x, &Ending.y);

    DDA(Beginning, Ending);
    getch();
    closegraph();
}
