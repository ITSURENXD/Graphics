#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include "./Modules/Graphics.cpp"

void SymmetricPlot(Coordinates_Int Temp, Coordinates_Int Centre) {
    // First Quadrant 
    putpixel(Centre.x + Temp.x, Centre.y + Temp.y, WHITE);
    putpixel(Centre.x + Temp.y, Centre.y + Temp.x, WHITE);
    delay(15);
    // Second Quadrant
    putpixel(Centre.x - Temp.x, Centre.y + Temp.y, WHITE);
    putpixel(Centre.x - Temp.y, Centre.y + Temp.x, WHITE);
    delay(15);
    // Third Quadrant
    putpixel(Centre.x - Temp.x, Centre.y - Temp.y, WHITE);
    putpixel(Centre.x - Temp.y, Centre.y - Temp.x, WHITE);
    delay(15);
    // Fourth Quadrant
    putpixel(Centre.x + Temp.x, Centre.y - Temp.y, WHITE);
    putpixel(Centre.x + Temp.y, Centre.y - Temp.x, WHITE);
    delay(15);
}

void MidpointCircle(Coordinates_Int Centre, float Radius) {
    graphicsinits();
    Coordinates_Int Temp;
    int Parameter = 1 - Radius;

    Temp.x = 0; Temp.y = Radius; 
    SymmetricPlot(Temp, Centre);  

    while (Temp.x <= Temp.y) {
        if (Parameter<0) {
            Parameter = Parameter + 2*Temp.x + 3;
        } else {
            Parameter = Parameter + 2*Temp.x - 2*Temp.y + 5;
            Temp.y--;
        }
        SymmetricPlot(Temp,Centre);
        Temp.x++;
    }
}

int main() {
    system("cls");
    Coordinates_Int Centre;
    float Radius;
    //Gettting Inputs
    printf("Enter The Center Coordinate: ");
    scanf("%d %d", &Centre.x ,  &Centre.y)  ;
    printf("Enter The Radius of the circle: ");
    scanf("%f", &Radius);

    MidpointCircle(Centre, Radius);
    getch();
    closegraph();
}