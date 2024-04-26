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
void InputsCircle( Coordinates_Int *Centre, float *Radius) {
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

void InputsColor(int *FillColor, int *BoundryColor) {
    // Colors Printing
    for (int i = 0; i < 16; i++) {
        printf("%-12s%-2d\n", colors[i], i);
    }
    //Choosing colors
    do {
        printf("Enter the Fill color and BoundryColor in Numbers: ");
        scanf("%d %d", FillColor, BoundryColor);
    } while (*FillColor>15 || *BoundryColor>15);
}

// Algorithms

void BoundryFill4Connected(int x, int y, int FillColor, int BoundryColor) {
    if ( ((getpixel(x,y)) != BoundryColor) && ((getpixel(x,y)) != FillColor)) {
        delay(0.9);
        putpixel(x, y,FillColor);

        BoundryFill4Connected(x+1,y, FillColor, BoundryColor);
        BoundryFill4Connected(x-1,y, FillColor, BoundryColor);
        BoundryFill4Connected(x,y+1, FillColor, BoundryColor);
        BoundryFill4Connected(x,y-1, FillColor, BoundryColor);
    }
}

void BoundryFill8Connected(int x, int y, int FillColor, int BoundryColor) {
    if ( ((getpixel(x,y)) != BoundryColor) && ((getpixel(x,y)) != FillColor)) {
        delay(0.9);
        putpixel(x, y,FillColor);

        BoundryFill8Connected(x-1,y, FillColor, BoundryColor);
        BoundryFill8Connected(x+1,y, FillColor, BoundryColor);
        BoundryFill8Connected(x,y-1, FillColor, BoundryColor);
        BoundryFill8Connected(x,y+1, FillColor, BoundryColor);
        BoundryFill8Connected(x-1,y-1, FillColor, BoundryColor);
        BoundryFill8Connected(x-1,y+1, FillColor, BoundryColor);
        BoundryFill8Connected(x+1,y-1, FillColor, BoundryColor);
        BoundryFill8Connected(x+1,y+1, FillColor, BoundryColor);
    }
}

void Menu(Coordinates_Int Seed, Coordinates_Int Centre,int Radius, int FillColor, int BoundryColor,int *choice) {
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
            BoundryFill4Connected(Seed.x,Seed.y, FillColor, BoundryColor);
            break;
        case 2: 
            BoundryFill8Connected(Seed.x, Seed.y, FillColor,BoundryColor);
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
    float Radius; int FillColor, BoundryColor, choice=0;

    // Circle Setup
    InputsCircle(&Centre, &Radius);
    // Seed Setup
    InputsSeed(&Seed, Centre, Radius);
    // Color Setup
    InputsColor(&FillColor,&BoundryColor);

    // Graphing
    do {
        Menu(Seed, Centre, Radius, FillColor, BoundryColor, &choice);
    } while (choice != 0);

    getchx();
    closegraph();
}

