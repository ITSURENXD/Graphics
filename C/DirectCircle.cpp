#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include "./Modules/Graphics.cpp"

void DirectCircle(Coordinates_Int Centre, float Radius) {
    Coordinates_Float Temp;

    // Actual working
    Temp.x=Centre.x+Radius;
    graphicsinits();
    outtextxy(200, 20, "Direct Circle"); 
    for (; Temp.x>=Centre.x-Radius;Temp.x--) {
        delay(10);
        Temp.y=Centre.y+sqrt(pow(Radius,2)-pow(Temp.x-Centre.x,2));
        printf("\n Plot Values: x: %f y: %f", round(Temp.x), round(Temp.y));
        putpixel(round(Temp.x),round(Temp.y),WHITE);
        Temp.y=Centre.y-sqrt(pow(Radius,2)-pow(Temp.x-Centre.x,2));
        printf("\n Plot Values: x: %f y: %f", round(Temp.x), round(Temp.y));
        putpixel(round(Temp.x),round(Temp.y),WHITE);
    }
}

int main() {
    system("cls");
    Coordinates_Int Centre;
    float Radius;

    //Gettting Inputs
    printf("Enter The Center Coordinate: ");
    scanf("%d %d", &Centre.x, &Centre.y);
    printf("Enter The Radius of the circle: ");
    scanf("%f", &Radius);

    DirectCircle(Centre, Radius);
    getch();
    closegraph();
}