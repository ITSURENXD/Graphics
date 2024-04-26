#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include "./Modules/Graphics.cpp"

#define MAX_SIZE 50

void FloodFill4Connected(int x, int y, int FillColor, int AreaPreviousColor) {
    if ( ((getpixel(x,y)) == AreaPreviousColor)) {
        delay(1);
        putpixel(x, y,FillColor);

        FloodFill4Connected(x+1,y, FillColor, AreaPreviousColor);
        FloodFill4Connected(x-1,y, FillColor, AreaPreviousColor);
        FloodFill4Connected(x,y+1, FillColor, AreaPreviousColor);
        FloodFill4Connected(x,y-1, FillColor, AreaPreviousColor);
    }
}
void FloodFill8Connected(int x, int y, int FillColor, int AreaPreviousColor) {
    if ( ((getpixel(x,y)) == AreaPreviousColor)) {
        delay(1);
        putpixel(x, y,FillColor);

        FloodFill8Connected(x+1,y, FillColor, AreaPreviousColor);
        FloodFill8Connected(x-1,y, FillColor, AreaPreviousColor);
        FloodFill8Connected(x,y+1, FillColor, AreaPreviousColor);
        FloodFill8Connected(x,y-1, FillColor, AreaPreviousColor);
        FloodFill8Connected(x+1,y+1, FillColor, AreaPreviousColor);
        FloodFill8Connected(x+1,y-1, FillColor, AreaPreviousColor);
        FloodFill8Connected(x-1,y+1, FillColor, AreaPreviousColor);
        FloodFill8Connected(x-1,y-1, FillColor, AreaPreviousColor);
    }
}

int main() {
    system("cls");
    Coordinates_Int Centre, Seed;
    const char* colors[] = {"BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA", "BROWN", "LIGHTGRAY", "DARKGRAY", "LIGHTBLUE", "LIGHTGREEN", "LIGHTCYAN", "LIGHTRED", "LIGHTMAGENTA", "YELLOW", "WHITE"};
    float Radius;
    int FillColor;

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
        printf("Enter the Fill color in Number: ");
        scanf("%d", &FillColor);
    } while (FillColor>15);
    // Graphing
    FloodFill8Connected(Seed.x, Seed.y, FillColor,0);
    getch();
    closegraph();
}

