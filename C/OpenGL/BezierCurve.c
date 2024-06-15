#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

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
    glClear(GL_COLOR_BUFFER_BIT); // Clears pixel buffer

    glBegin(GL_POINTS); // Begin rendering points
        for (double t = 0.0; t <= 1.0; t += 0.0005) {
            double xt = 0;
            double yt = 0;
            for (int i = 0; i < ControlPoints; i++) {
                double binomialCoeff = combination(ControlPoints - 1, i);
                double term = binomialCoeff * pow(t, i) * pow(1 - t, ControlPoints - 1 - i);
                xt += term * Vertex[0][i];
                yt += term * Vertex[1][i];
            }
            glVertex2i((int)xt, (int)yt);
        }
    glEnd(); // End rendering points
    glFlush(); // Flushing OpenGL pipeline
}

void ControlPointInputs() {
    printf("Enter the number of control points: ");
    scanf("%d", &ControlPoints);

    for (int i = 0; i < ControlPoints; i++) {
        printf("Enter the Control Point [%d] (x,y): ", i + 1);
        scanf("%d %d", &Vertex[0][i], &Vertex[1][i]);
    }
}

void WindowInitialization(float Red, float Green, float Blue) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glColor3f(0.0f, 1.0f, 0.0f);       // Set drawing color to green
    glPointSize(5.0);                  // Set point size to 5 pixels
    glMatrixMode(GL_PROJECTION);       // Select projection matrix
    gluOrtho2D(0.0, 200, 0.0, 150);    // Set orthographic projection
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);                   // Initialize GLUT
    ControlPointInputs();                    // Get control point inputs
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(500, 500);            // Set window size
    glutInitWindowPosition(180, 90);         // Set window position
    glutCreateWindow("Displaying Dot");      // Create a window with a title
    WindowInitialization(0.0, 0.0, 0.0);     // Initialize window properties
    glutDisplayFunc(Display);                // Set display function
    glutMainLoop();                          // Enter the GLUT event processing loop
    return 0;                                // Return success
}
