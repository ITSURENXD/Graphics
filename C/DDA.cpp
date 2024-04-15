#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include "./Modules/Graphics.cpp"

void DDA(int x_initial, int y_initial, int x_final, int y_final) {
    float difference_x, difference_y, increment_x, increment_y, steps, x, y;

    // Setting Up The differences
    difference_x = x_final - x_initial;
    difference_y = y_final - y_initial;
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
    x=x_initial, y=y_initial;
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
    outtextxy(x_initial,y_initial,"(x1,y1)");
    outtextxy(x_final,y_final,"(x2,y2)");
}

int main() {
    system("cls");
    int x_intial,y_initial,x_final,y_final;

    //Gettting Inputs
    printf("Enter The Starting Coordinate: ");
    scanf("%d %d", &x_intial, &y_initial);
    printf("Enter The Ending Coordinate: ");
    scanf("%d %d", &x_final, &y_final);

    DDA(x_intial,y_initial,x_final,y_final);
    getch();
    closegraph();
}