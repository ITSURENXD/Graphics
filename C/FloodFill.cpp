#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include "./Modules/Graphics.cpp"
#include "./Modules/c_functions_linux.cpp"

#define MAX_SIZE 50
const char* colors[] = {"BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA", "BROWN", "LIGHTGRAY", "DARKGRAY", "LIGHTBLUE", "LIGHTGREEN", "LIGHTCYAN", "LIGHTRED", "LIGHTMAGENTA", "YELLOW", "WHITE"};

void drawCircle(Coordinates_Int Centre, int Radius) {
    graphicsinits();
    // Thick walls needed for 8 connected one
    circle(Centre.x,Centre.y, Radius-1);
    circle(Centre.x,Centre.y, Radius);
    circle(Centre.x,Centre.y, Radius+1);
}

// INPUTS
void InputsCircle(Coordinates_Int *Centre, float *Radius) {
    //Gettting Inputs
    printf("Enter The Center Coordinate: ");
    scanf("%d %d", &Centre->x, &Centre->y);
    printf("Enter The Radius of the circle: ");
    scanf("%f", Radius);
}

void InputsSeed(Coordinates_Int *Seed, Coordinates_Int Centre, int Radius) {
    do {
        printf("Enter a Seed Point for the Circle (%d,%d, %d): ", Centre.x, Centre.y, Radius);
        fflush(stdin);
        scanf("%d %d", &Seed->x, &Seed->y);
    } while ((pow(Seed->x-Centre.x,2) + pow(Seed->y-Centre.y,2) - pow(Radius,2))>0);
}

void InputsColor(int *FillColor) {
    // Colors Printing
    for (int i = 0; i < 16; i++) {
        printf("%-12s%-2d\n", colors[i], i);
    }
    //Choosing colors
    do {
        printf("Enter the Fill color in Number: ");
        scanf("%d", FillColor);
    } while (*FillColor>15);
}

// Algorithms
void FloodFill4Connected(int x, int y, int FillColor, int AreaPreviousColor) {
    if ( ((getpixel(x,y)) == AreaPreviousColor)) {
        delay(0.9);
        putpixel(x, y,FillColor);

        FloodFill4Connected(x+1,y, FillColor, AreaPreviousColor);
        FloodFill4Connected(x-1,y, FillColor, AreaPreviousColor);
        FloodFill4Connected(x,y+1, FillColor, AreaPreviousColor);
        FloodFill4Connected(x,y-1, FillColor, AreaPreviousColor);
    }
}
void FloodFill8Connected(int x, int y, int FillColor, int AreaPreviousColor) {
    if ( ((getpixel(x,y)) == AreaPreviousColor)) {
        delay(0.9);
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

void Menu(Coordinates_Int Seed, Coordinates_Int Centre,int Radius, int FillColor,int *choice) {
    system({"cls"});
    drawCircle(Centre, Radius);
    printf("\nMenu: \n1. 4 Connected Flood Fill\n2. 8 Connected Flood Fill\n Select one option:\n => ");
    scanf("%d", choice);
    switch(*choice) {
        case 0:
            printf("\n[SYSTEM ALERT] Program Exiting.");
            closegraph();
            exit(EXIT_FAILURE);
        case 1:
            FloodFill4Connected(Seed.x,Seed.y, FillColor, 0);
            break;
        case 2: 
            FloodFill8Connected(Seed.x, Seed.y, FillColor,0);
            break;
        default:
            printf("Invalid Choice Given: ");
    }
    getchx();
    cleardevice();
}


int main() {
    system("cls");
    Coordinates_Int Centre, Seed;
    float Radius;
    int FillColor,choice=0;
    // Circle Setup
    InputsCircle(&Centre, &Radius);
    // Seed Setup
    InputsSeed(&Seed, Centre, Radius);
    // Color Setup
    InputsColor(&FillColor);
    // Menu
    do {
        Menu(Seed,Centre,Radius,FillColor,&choice);
    } while (choice !=0);
    getchx();
    closegraph();
}

