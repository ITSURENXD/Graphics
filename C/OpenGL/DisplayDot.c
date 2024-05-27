#include <stdio.h>
#include <GL/glut.h>
// Draws a dot

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clears pixel buffer

    glBegin(GL_POINTS); //Begin Rendering points
        glVertex2i(10,10);
    glEnd(); // End Redering Points

    glFlush(); // Flushing OpenGL Pipeline
}

void WindowInitialization(float Red, float Green, float Blue) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glColor3f(0.0f, 1.0f, 0.0f);       // Set drawing color to green
    glPointSize(10.0);                  // Set point size to 10 pixels
    glMatrixMode(GL_PROJECTION);        // Select projection matrix
    gluOrtho2D(0.0, 200, 0.0, 150); // Set orthographic projection
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);                   // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(500, 500);              // Set window size
    glutInitWindowPosition(180, 90);         // Set window position
    glutCreateWindow("Displaying Dot");       // Create a window with a title
    WindowInitialization(0.0,0.0,0.0);                  // Initialize window properties
    glutDisplayFunc(Display);                // Set display function
    glutMainLoop();                          // Enter the GLUT event processing loop
    return 0;                                // Return success
}