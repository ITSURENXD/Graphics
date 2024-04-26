#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include "./Modules/Graphics.cpp"

#define MAX_SIZE 50

void BoundryFill4Connected(int x, int y, int FillColor, int BoundryColor) {
    if ( ((getpixel(x,y)) != BoundryColor) && ((getpixel(x,y)) != FillColor)) {
        delay(1);
        putpixel(x, y,FillColor);

        BoundryFill4Connected(x+1,y, FillColor, BoundryColor);
        BoundryFill4Connected(x-1,y, FillColor, BoundryColor);
        BoundryFill4Connected(x,y+1, FillColor, BoundryColor);
        BoundryFill4Connected(x,y-1, FillColor, BoundryColor);
    }
}
void BoundryFill8Connected(int x, int y, int FillColor, int BoundryColor) {
    if ( ((getpixel(x,y)) != BoundryColor) && ((getpixel(x,y)) != FillColor)) {
        delay(1);
        putpixel(x, y,FillColor);

        BoundryFill8Connected(x+1,y, FillColor, BoundryColor);
        BoundryFill8Connected(x-1,y, FillColor, BoundryColor);
        BoundryFill8Connected(x,y+1, FillColor, BoundryColor);
        BoundryFill8Connected(x,y-1, FillColor, BoundryColor);
        BoundryFill8Connected(x+1,y+1, FillColor, BoundryColor);
        BoundryFill8Connected(x+1,y-1, FillColor, BoundryColor);
        BoundryFill8Connected(x-1,y+1, FillColor, BoundryColor);
        BoundryFill8Connected(x-1,y-1, FillColor, BoundryColor);
    }
}

int main() {
    system("cls");
    Coordinates_Int Centre, Seed;
    const char* colors[] = {"BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA", "BROWN", "LIGHTGRAY", "DARKGRAY", "LIGHTBLUE", "LIGHTGREEN", "LIGHTCYAN", "LIGHTRED", "LIGHTMAGENTA", "YELLOW", "WHITE"};
    float Radius;
    int FillColor, BoundryColor;

    //Gettting Inputs
    printf("Enter The Center Coordinate: ");
    scanf("%d %d", &Centre.x, &Centre.y);
    printf("Enter The Radius of the circle: ");
    scanf("%f", &Radius);
    // Draws Circle
    graphicsinits();
    circle(Centre.x,Centre.y, Radius);
    // Seed values
    do {
        printf("Enter a Seed Point for the Circle (%d,%d, %d): ", Centre.x, Centre.y, Radius);
        fflush(stdin);
        scanf("%d %d", &Seed.x, &Seed.y);
    } while ((pow(Seed.x-Centre.x,2) + pow(Seed.y-Centre.y,2) - pow(Radius,2))>0);
    // Colors Printing
    for (int i = 0; i < 16; i++) {
        printf("%-12s%-2d\n", colors[i], i);
    }
    //Choosing colors
    do {
        printf("Enter the Fill color and BoundryColor in Numbers: ");
        scanf("%d %d", &FillColor, &BoundryColor);
    } while (FillColor>15 || BoundryColor>15);
    // Graphing
    BoundryFill8Connected(Seed.x, Seed.y, FillColor,BoundryColor);
    getch();
    closegraph();
}

