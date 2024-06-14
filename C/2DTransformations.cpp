#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include "./Modules/Graphics.cpp"
#include "./Modules/Transformations.cpp"

#define Dimension 3

void Drawing(int Size, int ParamSize, int MatrixA[MAXMATSIZE][MAXPARAMSIZE], int color) {
    int Fixed[MAXMATSIZE][MAXPARAMSIZE], DisplayOffset[MAXMATSIZE]={200,200,200,1};
    
    // Fixing coordinates to the center of the screen.
    printf("\n Coordinate Fixing");
    Translation(Dimension, ParamSize, DisplayOffset, MatrixA, Fixed);

    // Actual Drawing Operation
    printf("\n Now Drawing: ");
    setcolor(color);
    for (int i=0; i<ParamSize-1; i++) {
        printf("\n\tDrawing from (%d,%d) to (%d, %d)", Fixed[0][i],Fixed[1][i],MatrixA[0][i+1], MatrixA[1][i+1]);
        line(Fixed[0][i],Fixed[1][i],Fixed[0][i+1], Fixed[1][i+1]);
        delay(15);
    }
}

void Polygon2dInputs(int *ParamSize,int MatrixA[MAXMATSIZE][MAXPARAMSIZE]) {
    printf("\n---------------------------\n");
    system("cls");

    // Input Paramaters
    printf("Enter the number of Vertices: ");
    scanf("%d",ParamSize);
    (*ParamSize)++;
    
    // Inputs
    MatrixInputs(Dimension, *ParamSize, MatrixA);

    // Displaying Matrix
    printf("\n---------------------------\n");
    printf("Entered Coordinates are: ");
    MatrixDisplay(Dimension, *ParamSize,MatrixA);

    // Drawing
    graphicsinits();
    Drawing(Dimension, *ParamSize, MatrixA,WHITE);
}

// INTERFACES
void internalNormalRotationalInterface(int ParamSize,int Angle, int MatrixA[MAXMATSIZE][MAXPARAMSIZE]) {
    int Result[MAXMATSIZE][MAXPARAMSIZE];

    Rotation(Dimension, ParamSize, 0, Angle,MatrixA, Result);
    Drawing(Dimension, ParamSize, Result, MAGENTA);
}
void internalFixedPointRotationalInterface(int ParamSize,int Angle, int MatrixA[MAXMATSIZE][MAXPARAMSIZE]) {
    int FixedPoint[MAXMATSIZE],  Result[MAXMATSIZE][MAXPARAMSIZE];

    printf("Enter the Fixed Point Coordinates x and y: ");
    scanf("%d %d",&FixedPoint[0], &FixedPoint[1]);

    FixedPointRotation(Dimension, ParamSize, 0, Angle, FixedPoint, MatrixA, Result);
    Drawing(Dimension, ParamSize, Result, MAGENTA);
}
void internalNormalScalingInterface(int ParamSize, int ScalingVector[MAXMATSIZE], int MatrixA[MAXMATSIZE][MAXPARAMSIZE]) {
    int Result[MAXMATSIZE][MAXPARAMSIZE];

    Scaling(Dimension, ParamSize, ScalingVector,MatrixA, Result);
    Drawing(Dimension, ParamSize, Result, LIGHTGREEN);
}

void internalFixedPointScalingInterface(int ParamSize, int ScalingVector[MAXMATSIZE], int MatrixA[MAXMATSIZE][MAXPARAMSIZE]) {
    int FixedPoint[MAXMATSIZE],  Result[MAXMATSIZE][MAXPARAMSIZE];

    printf("Enter the Fixed Point Coordinates x and y: ");
    scanf("%d %d",&FixedPoint[0], &FixedPoint[1]);

    FixedPointScaling(Dimension, ParamSize, FixedPoint, ScalingVector,MatrixA, Result);
    Drawing(Dimension, ParamSize, Result, LIGHTGREEN);
}
void TranslationInterface(int ParamSize,int MatrixA[MAXMATSIZE][MAXPARAMSIZE]) {
    int TranslationVector[MAXMATSIZE], Result[MAXMATSIZE][MAXPARAMSIZE];

    printf("Enter the Translational vector values <tx, ty>: ");
    scanf("%d %d",&TranslationVector[0], &TranslationVector[1]);

    Translation(Dimension, ParamSize, TranslationVector,MatrixA, Result);
    Drawing(Dimension,ParamSize, Result,GREEN);
}

void RotationInterface(int ParamSize,int MatrixA[MAXMATSIZE][MAXPARAMSIZE]) {
    system("cls");
    int Angle, choice;
    printf("Enter the Rotational Angle: \n");
    scanf("%d", &Angle);

    system("cls");
    printf("\nMENU: \n1. Unifrom Rotation\n2. Fixed Point Rotation\n\n Select a choice=> ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            internalNormalRotationalInterface(ParamSize, Angle, MatrixA);
            break;
        case 2:
            internalFixedPointRotationalInterface(ParamSize, Angle, MatrixA);
            break;
        default:
            break;
    }
}

void ReflectionInterface(int ParamSize,int MatrixA[MAXMATSIZE][MAXPARAMSIZE]) {
    system("cls");
    int Axis, Result[MAXMATSIZE][MAXPARAMSIZE];
    printf("Enter the Axis of Reflection: \n");
    printf("\nAXES: \n1. X-Axis\n2. Y-Axis\n4. Origin\n5. X=Y Line\n\n Select a choice=> ");
    scanf("%d", &Axis);
    
    Reflection(Dimension, ParamSize, Axis-1, MatrixA, Result);
    Drawing(Dimension, ParamSize, Result, CYAN);
}

void ShearInterface(int ParamSize,int MatrixA[MAXMATSIZE][MAXPARAMSIZE]) {
    system("cls");
    int Axis, Result[MAXMATSIZE][MAXPARAMSIZE], ShearVector[MAXMATSIZE]={0,0,0,0};
    printf("Enter the Axis of Shearing: \n");
    printf("\nAXES: \n1. X-Axis\n2. Y-Axis\n\n Select a choice=> ");
    scanf("%d", &Axis);

    printf("Enter the Shear Vector values Shx and Shy: ");
    scanf("%d %d",&ShearVector[0], &ShearVector[1]);
    Shearing(Dimension, ParamSize, Axis-1, ShearVector, MatrixA, Result);
    Drawing(Dimension, ParamSize, Result, CYAN);
}

void ScalingInterface(int ParamSize,int MatrixA[MAXMATSIZE][MAXPARAMSIZE]) {
    system("cls");
    int ScalingVector[MAXMATSIZE]={0,0,0,0}, choice;
    printf("Enter the Scaling Factors values sx and sy: ");
    scanf("%d %d",&ScalingVector[0], &ScalingVector[1]);
    
    system("cls");
    printf("\nMENU: \n1. Unifrom Scaling\n2. Fixed Point Scaling\n\n Select a choice=> ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            internalNormalScalingInterface(ParamSize, ScalingVector, MatrixA);
            break;
        case 2:
            internalFixedPointScalingInterface(ParamSize, ScalingVector, MatrixA);
            break;
        default:
            break;
    }
}

void Menu(int *choice, int ParamSize,int MatrixA[MAXMATSIZE][MAXPARAMSIZE]) {
    system("cls");
    printf("\nMENU: \n1. Translation\n2. Rotation\n3. Reflection\n4. Shear\n5. Scaling\n\n Select an option=> ");
    scanf("%d", choice);
    switch(*choice) {
        case 1:
            TranslationInterface(ParamSize, MatrixA);
            break;
        case 2:
            RotationInterface(ParamSize, MatrixA);
            break;
        case 3:
            ReflectionInterface(ParamSize, MatrixA);
            break;
        case 4:
            ShearInterface(ParamSize, MatrixA);
            break;
        case 5:
            ScalingInterface(ParamSize, MatrixA);
            break;
        default:
            break;
    }
}

int main()  {
    system("cls");
    int MatrixA[MAXMATSIZE][MAXPARAMSIZE], MatrixB[MAXMATSIZE][MAXPARAMSIZE], ParamSize;
    
    int choice=0; 
    Polygon2dInputs(&ParamSize, MatrixA);
    do {
        Menu(&choice,ParamSize, MatrixA);
    } while (choice !=0);
    getch();
    closegraph();
}