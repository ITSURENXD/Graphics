#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include "./Modules/Graphics.cpp"

#define ControlPoints 4


void ControlPointInputs( int Vertex[2][ControlPoints]) {
    for (int i=0; i < ControlPoints; i++) {
        printf("Enter the Control Point [%d] (x,y): ", i+1);
        scanf("%d %d", &Vertex[0][i], &Vertex[1][i]);
    }
}

// Not Necessary
void ControlPointOutputs(int Vertex[2][ControlPoints]) {
    for (int i=0; i < ControlPoints; i++) {
        printf("\nControl Poins [%d] (x,y): %d %d", i+1, Vertex[0][i], Vertex[1][i]);
        putpixel(Vertex[0][i], Vertex[1][i], 7);
    }
}

void Bezier(int Vertex[2][ControlPoints]) {
    for (double t=0.0; t < 1.0; t+=0.0005) { 
        double xt = pow(1-t,3)*Vertex[0][0] + 3*t*pow(1-t,2)*Vertex[0][1] + 3*(1-t)*pow(t,2)*Vertex[0][2] + pow(t,3)*Vertex[0][3];
        double yt = pow(1-t,3)*Vertex[1][0] + 3*t*pow(1-t,2)*Vertex[1][1] + 3*(1-t)*pow(t,2)*Vertex[1][2] + pow(t,3)*Vertex[1][3];
        printf("\n Plot Pixel at (%g, %g) with valuue of t=%g", xt, yt, t);
        putpixel(xt, yt, 2);
    }
    
}

int main()  {
    int Vertex[2][ControlPoints];
    ControlPointInputs(Vertex);
    graphicsinits();
    ControlPointOutputs(Vertex);
    Bezier(Vertex);
    getch();
    closegraph();
}