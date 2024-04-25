#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include "./Modules/Graphics.cpp"

void DirectEllipse(Coordinates_Int Centre, Coordinates_Int Radii) {
    Coordinates_Float Temp;
    graphicsinits();
    Temp.x=Centre.x-Radii.x; 
    while (Temp.x<Temp.x+Radii.x) {
        Temp.y=Centre.y+((Radii.y/Radii.x)*sqrt(pow(Radii.x,2)-pow((Temp.x-Centre.x),2)));
        putpixel(round(Temp.x),round(Temp.y),WHITE);
        Temp.y=Centre.y-((Radii.y/Radii.x)*sqrt(pow(Radii.x,2)-pow((Temp.x-Centre.x),2)));
        putpixel(round(Temp.x),round(Temp.y),WHITE);
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
    DirectEllipse(Centre, Radii);
    getch();
    closegraph();
}