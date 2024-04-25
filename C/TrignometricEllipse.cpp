#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include "./Modules/Graphics.cpp"

void TrignometricEllipse(Coordinates_Int Centre, Coordinates_Int Radii) {
    graphicsinits();
    Coordinates_Float Temp;
     
    for (int Theta=0;Theta<360;Theta++) {
        Temp.x = Centre.x + Radii.x * cos(Theta);
        Temp.y = Centre.y + Radii.y * sin(Theta);
        putpixel(round(Temp.x), round(Temp.y), WHITE);
        delay(15);
        Temp.x++;
    }
}

int main() {
    system("cls");
    Coordinates_Int Centre, Radii;

    //Gettting Inputs
    printf("Enter The Center Coordinate: ");
    scanf("%d %d", &Centre.x, &Centre.y);
    printf("Enter The Length of Major and Minor Axis: ");
    scanf("%d %d", &Radii.x,&Radii.y);
    
    TrignometricEllipse(Centre, Radii);
    getch();
    closegraph();
}