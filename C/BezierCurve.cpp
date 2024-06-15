#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include "./Modules/Graphics.cpp"

#define MAXPOINTS 10
int ControlPoints;
int Vertex[2][MAXPOINTS];

long factorial(int num) {
    if (num <= 1) return 1;
    return num * factorial(num - 1);
}

long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

long combination(int n, int r) {
    return permutation(n, r) / factorial(r);
}

void Display() {
    graphicsinits();
    cleardevice();

    for (double t = 0.0; t <= 1.0; t += 0.0005) {
        double xt = 0;
        double yt = 0;
        for (int i = 0; i < ControlPoints; i++) {
            double binomialCoeff = combination(ControlPoints - 1, i);
            double term = binomialCoeff * pow(t, i) * pow(1 - t, ControlPoints - 1 - i);
            xt += term * Vertex[0][i];
            yt += term * Vertex[1][i];
        }
        putpixel((int)xt, (int)yt, GREEN);
    }
}

void ControlPointInputs() {
    system("cls");
    printf("Enter the number of control points: ");
    scanf("%d", &ControlPoints);

    for (int i = 0; i < ControlPoints; i++) {
        printf("Enter the Control Point [%d] (x,y): ", i + 1);
        scanf("%d %d", &Vertex[0][i], &Vertex[1][i]);
    }
}

int main(int argc, char **argv) {
    ControlPointInputs();                    // Get control point inputs
    Display();
    getch();
    closegraph();
    return 0;                                // Return success
}
