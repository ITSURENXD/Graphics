#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include "./Modules/Graphics.cpp"

void TrignometricCircle(Coordinates_Int Centre, float Radius) {
    Coordinates_Float Temp;

    graphicsinits();
    outtextxy(200, 20, "Trignometric Circle"); 
    for (int Theta=0;Theta<360;Theta++) {
        delay(10);
        Temp.x=Centre.x+Radius*cos(Theta);
        Temp.y=Centre.y+Radius*sin(Theta);
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

    TrignometricCircle(Centre, Radius);
    getch();
    closegraph();
}