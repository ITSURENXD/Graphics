#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include "./Modules/Graphics.cpp"

void BSA(Coordinates_Int Beginning, Coordinates_Int Ending) {
    Coordinates_Int Difference, Temp;
    int parameter;

    // Setting Up The differences
    Difference.x = Ending.x - Beginning.x;
    Difference.y = Ending.y - Beginning.y;
    printf("\n Diff x: %f y: %f", Difference.x, Difference.y);

    // Actual working
    Temp.x=Beginning.x, Temp.y=Beginning.y;
    graphicsinits();
    printf("\n Putting pixel at ( %f , %f )", Temp.x, Temp.y);
    putpixel(Temp.x,Temp.y,WHITE);
    outtextxy(200, 20, "BSA"); 
    if (abs(Difference.x)>=abs(Difference.y)) {   
        parameter=2*Difference.y-Difference.x; 
        
        while (Temp.x<Ending.x) {
            Temp.x++;
            if(parameter<0) {
                // Temp.y Remains the same
                parameter=parameter+2*Difference.y;
            } else {
                Temp.y++;
                parameter=parameter+(2*Difference.y)-(2*Difference.x);
            }
            printf("\n Putting pixel at ( %f , %f )", Temp.x, Temp.y);
            delay(5);
            putpixel(Temp.x,Temp.y,WHITE);
        }
    } else {
        parameter=2*Difference.x-Difference.y; 
        while (Temp.y<Ending.y) {
            Temp.y++;
            if(parameter<0) {
                // Temp.y Remains the same
                parameter=parameter+2*Difference.x;
            } else {
                Temp.x++;
                parameter=parameter+(2*Difference.x)-(2*Difference.y);
            }
            printf("\n Putting pixel at ( %f , %f )", Temp.x, Temp.y);
            delay(5);
            putpixel(Temp.x,Temp.y,WHITE);
        }
    }

    // Labeling
    outtextxy(Beginning.x,Beginning.y,"(x1,y1)");
    outtextxy(Ending.x,Ending.y,"(x2,y2)");
}

int main() {
    system("cls");
    Coordinates_Int Beginning, Ending;

    //Gettting Inputs
    printf("Enter The Starting Coordinate: ");
    scanf("%d %d", &Beginning.x, &Beginning.y);
    printf("Enter The Ending Coordinate: ");
    scanf("%d %d", &Ending.x, &Ending.y);

    BSA(Beginning, Ending);
    getch();
    closegraph();
}