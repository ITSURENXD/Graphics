#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include "./Modules/Graphics.cpp"

float rounder(float number) {return number+0.5;}

void DDA(int x_initial, int y_initial, int x_final, int y_final) {
    outtextxy(200,20,"DDA");
    float difference_x, difference_y, increment_x, increment_y, steps, x, y;

    // Setting Up The differences
    difference_x = x_final - x_initial;
    difference_y = y_final - y_initial;

    // Setting up the Steps
    if (abs(difference_x) > abs(difference_y)) {
        steps=abs(difference_x);
    } else {
        steps=abs(difference_y);
    }

    // Settting up the Increments
    increment_x=difference_x/steps;
    increment_y=difference_y/steps;

    // Actual working
    x=x_initial, y=y_initial;
    for (int i=0; i<steps;i++) {
        delay(5);
        y+=increment_y;
        x+=increment_x;
        putpixel(rounder(x),rounder(y),WHITE);
    }

    // Labeling
    outtextxy(x_initial,y_initial,"(x1,y1)");
    outtextxy(x_final,y_final,"(x2,y2)");
}

int main() {
    graphicsinits();
    system("cls");

    int x_intial,y_initial,x_final,y_final;
    //Gettting Inputs
    printf("Enter The Starting Coordinate: ");
    scanf("%d %d", &x_intial, &y_initial);
    printf("Enter The Ending Coordinate: ");
    scanf("%d %d", &x_final, &y_final);

    DDA(x_intial,y_initial,x_final,y_final);
    getch();
}