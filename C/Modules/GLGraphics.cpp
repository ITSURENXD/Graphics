#ifndef GL_GLUT_WRAPPER_H
#define GL_GLUT_WRAPPER_H

#include <GL/glut.h>

#endif // GL_GLUT_WRAPPER_H

void WindowInitialization() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glColor3f(0.0f, 1.0f, 0.0f);       // Set drawing color to green
    glPointSize(10.0);                  // Set point size to 10 pixels
    glMatrixMode(GL_PROJECTION);        // Select projection matrix
    gluOrtho2D(0.0, 200, 0.0, 150); // Set orthographic projection
}

void PreInitialization(int argc, char **argv, char *Title) {
    glutInit(&argc, argv);                   // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(500, 500);              // Set window size
    glutInitWindowPosition(180, 90);         // Set window position
    glutCreateWindow(Title);       // Create a window with a title
}