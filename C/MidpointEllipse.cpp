#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include "./Modules/Graphics.cpp"

void SymmetricPlot(Coordinates_Int Temp, Coordinates_Int Centre) {
    // First Quadrant 
    putpixel(Centre.x + Temp.x, Centre.y + Temp.y, WHITE);
    delay(15);
    // Second Quadrant
    putpixel(Centre.x - Temp.x, Centre.y + Temp.y, WHITE);
    delay(15);
    // Third Quadrant
    putpixel(Centre.x - Temp.x, Centre.y - Temp.y, WHITE);
    delay(15);
    // Fourth Quadrant
    putpixel(Centre.x + Temp.x, Centre.y - Temp.y, WHITE);
    delay(15);
}

void MidpointEllipse(Coordinates_Int Centre, Coordinates_Int Radii) {
    graphicsinits();
    Coordinates_Int Temp;
    
    // Initial Prints
    Temp.x = 0; Temp.y = Radii.y;
    SymmetricPlot(Temp,Centre);

    // For Region 1
    printf("\nComputing for REGION 1:");
    // p10 = b^2 - a^2b + ((b^2)/4);
    int Parameter1 = pow(Radii.y,2) - (pow(Radii.x,2)*Radii.y) + (pow(Radii.x,2)/4);

    while (2*pow(Radii.y,2)*(Temp.x+1) < 2*pow(Radii.x,2)*Temp.y) { //2*(ry^2)*(x+1) <= 2*(rx^2)*y
        printf("\n\t Parameter=%d Condition1: %.0f condition2: %.0f", Parameter1, 2*pow(Radii.y,2)*(Temp.x+1), 2*pow(Radii.x,2)*Temp.y);
        Temp.x++;

        if (Parameter1<0) {
            // p1k+1 = p1k + 2*(ry^2)*(x+1) + ry^2;
            Parameter1 = Parameter1 + (2*pow(Radii.y,2) * Temp.x) + pow(Radii.y,2);
        } else {
            Temp.y--;
            // p1k+1 = p1k + 2*(ry^2)*(x+1) - 2*(rx^2)*(y-1) + ry^2;
            Parameter1 = Parameter1 + (2*pow(Radii.y,2) * Temp.x) - (2*pow(Radii.x,2) * Temp.y) + pow(Radii.y,2);
        }

        printf(" Plot (%d,%d)", Temp.x, Temp.y);
        SymmetricPlot(Temp,Centre);
    }

    // For Region 2 continuing from region 1
    printf("\nComputing for REGION 2:");
    // p20 = ry^2 * (x0 + 0.5)^2 + rx^2*(y0 - 1)^2 - a2*b^2;
    int Parameter2 = pow(Radii.y,2) * pow((Temp.x + 0.5),2) + pow(Radii.x,2)*pow((Temp.y-1),2) - pow(Radii.x,2)*pow(Radii.y,2);

    while (Temp.y!=0) {
        printf("\n\t Parameter=%d Condition1: %d condition2: %d", Parameter2, Temp.y, 0);
        Temp.y--;

        if (Parameter2<=0) {
            Temp.x++;
            // p2k+1 = p2k + 2*(ry^2)*(x+1) - 2*(rx^2)*(y-1) + rx^2;
            Parameter2 = Parameter2 + (2*pow(Radii.y,2) * Temp.x) - (2*pow(Radii.x,2) * Temp.y) + pow(Radii.x,2);
        } else {
            // p2k+1 = p2k - 2*(rx^2)*(y-1) + rx^2;
            Parameter2 = Parameter2 - (2*pow(Radii.x,2) * Temp.y) + pow(Radii.x,2);
        }

        printf(" Plot (%d,%d)", Temp.x, Temp.y);
        SymmetricPlot(Temp,Centre);
    }
    
}

int main() {
    system("cls");
    Coordinates_Int Centre, Radii;

    //Gettting Inputs
    printf("Enter The Center Coordinate: ");
    scanf("%d %d", &Centre.x ,  &Centre.y ) ;
    printf("Enter The Length of Major and Minor Axis: ");
    scanf("%d %d", &Radii.x,&Radii.y);
    
    MidpointEllipse(Centre, Radii);
    getch();
    closegraph();
}