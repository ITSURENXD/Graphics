#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include "./Modules/Graphics.cpp"

void DDA(Coordinates_Int Beginning, Coordinates_Int Ending) {
    Coordinates_Float Difference, Increment, Temp;
    float steps;

    // Setting Up The differences
    Difference.x = Ending.x - Beginning.x;
    Difference.y = Ending.y - Beginning.y;
    printf("\n Diff x: %f y: %f", Difference.x, Difference.y);

    // Setting up the Steps
    if (abs(Difference.x) > abs(Difference.y)) {
        steps=abs(Difference.x);
    } else {
        steps=abs(Difference.y);
    }
    printf("\n Steps: %f",steps);

    // Settting up the Increments
    Increment.x=Difference.x/steps;
    Increment.y=Difference.y/steps;
    printf("\n Increments x: %f y: %f", Increment.x, Increment.y);

    // Actual working
    Temp.x=Beginning.x, Temp.y=Beginning.y;
    graphicsinits();
    outtextxy(200, 20, "DDA"); 
    putpixel(round(Temp.x),round(Temp.y),WHITE);
    for (int i=0; i<steps;i++) {
        delay(5);
        Temp.y+=Increment.y;
        Temp.x+=Increment.x;
        printf("\n Plot Values: x: %f y: %f", round(Temp.x), round(Temp.y));
        putpixel(round(Temp.x),round(Temp.y),WHITE);
    }

    // Labeling
    outtextxy(Beginning.x,Beginning.y,"(x1,y1)");
    outtextxy(Ending.y,Ending.y,"(x2,y2)");
}

int main() {
    system("cls");
    Coordinates_Int Beginning, Ending;

    //Gettting Inputs
    printf("Enter The Starting Coordinate: ");
    scanf("%d %d", &Beginning.x, &Beginning.y);
    printf("Enter The Ending Coordinate: ");
    scanf("%d %d", &Ending.x, &Ending.y);

    DDA(Beginning, Ending);
    getch();
    closegraph();
}