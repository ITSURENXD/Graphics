#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include "./Modules/Graphics.cpp"

void DDA(coordinates Beginning, coordinates Ending) {
    float difference_x, difference_y, increment_x, increment_y, steps, x, y;

    // Setting Up The differences
    difference_x = Ending.x - Beginning.x;
    difference_y = Ending.y - Beginning.y;
    printf("\n Diff x: %f y: %f", difference_x, difference_y);

    // Setting up the Steps
    if (abs(difference_x) > abs(difference_y)) {
        steps=abs(difference_x);
    } else {
        steps=abs(difference_y);
    }
    printf("\n Steps: %f",steps);

    // Settting up the Increments
    increment_x=difference_x/steps;
    increment_y=difference_y/steps;
    printf("\n Increments x: %f y: %f", increment_x, increment_y);

    // Actual working
    x=Beginning.x, y=Beginning.y;
    graphicsinits();
    outtextxy(200, 20, "DDA"); 
    putpixel(round(x),round(y),WHITE);
    for (int i=0; i<steps;i++) {
        delay(5);
        y+=increment_y;
        x+=increment_x;
        printf("\n Plot Values: x: %f y: %f", round(x), round(y));
        putpixel(round(x),round(y),WHITE);
    }

    // Labeling
    outtextxy(Beginning.x,Beginning.y,"(x1,y1)");
    outtextxy(Ending.y,Ending.y,"(x2,y2)");
}

int main() {
    system("cls");
    coordinates Beginning, Ending;

    //Gettting Inputs
    printf("Enter The Starting Coordinate: ");
    scanf("%d %d", &Beginning.x, &Beginning.y);
    printf("Enter The Ending Coordinate: ");
    scanf("%d %d", &Ending.x, &Ending.y);

    DDA(Beginning, Ending);
    getch();
    closegraph();
}