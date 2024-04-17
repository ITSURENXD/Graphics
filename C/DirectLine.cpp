#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include "./Modules/Graphics.cpp"

void DirectLine(Coordinates_Int Beginning, Coordinates_Int Ending) {
    Coordinates_Float Difference, Temp;

    // Setting Up The differences
    Difference.x = Ending.x - Beginning.x;
    Difference.y = Ending.y - Beginning.y;
    printf("\n Diff x: %f y: %f", Difference.x, Difference.y);

    float Slope = Difference.y/Difference.x;
    float Constant = Beginning.y-Slope*Beginning.x;
    printf("\n Slope: %f Constant: %f", Slope, Constant);

    // Actual working
    Temp.x=Beginning.x;
    graphicsinits();
    outtextxy(200, 20, "Direct Line Algorithm"); 
    for (; Temp.x<=Ending.x;Temp.x=Temp.x+1) {
        delay(5);
        Temp.y=(Slope*Temp.x)+Constant;
        printf("\n Plot Values: x: %f y: %f", round(Temp.x), round(Temp.y));
        putpixel(round(Temp.x),round(Temp.y),WHITE);
    }

    // Labeling
    outtextxy(Beginning.x,Beginning.y,"(x1,y1)");
    outtextxy(Ending.y,Ending.y,"(x2,y2)");
}

int main()  {
    system("cls");
    Coordinates_Int Beginning, Ending;

    //Gettting Inputs
    printf("Enter The Starting Coordinate: ");
    scanf("%d %d", &Beginning.x, &Beginning.y);
    printf("Enter The Ending Coordinate: ");
    scanf("%d %d", &Ending.x, &Ending.y);

    DirectLine(Beginning, Ending);
    getch();
    closegraph();
}