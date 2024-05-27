#include <stdio.h>
#include <GL/glut.h>
// Draws a point, line and a polygon

GLsizei wh = 500; // 32 bit int or long for window height
GLsizei ww = 500;

// Prototyping
void Display(void);
void WindowInitialization(void);

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clears pixel buffer

    glColor3f(0.0f, 1.0f, 0.0f);       // Set drawing color to green
    glBegin(GL_POINTS); //Begin Rendering points
        glVertex2i(40, 210);
    glEnd(); // End Redering Points

    glColor3f(1.0f, 0.0f, 0.0f);       // Set drawing color to red
    glBegin(GL_LINES); //Begin Rendering Lines
        glVertex2i(40,50);
        glVertex2i(100,100);
    glEnd(); // End Redering Lines

    glColor3f(0.0f, 0.0f, 1.0f);       // Set drawing color to blue
    glBegin(GL_POLYGON); //Begin Rendering Polygon
        glVertex2i(10,10);
        glVertex2i(10,30);
        glVertex2i(40,3);
        glVertex2i(60,15);
        glVertex2i(40,10);
    glEnd(); // End Redering Polygon

    glFlush(); // Flushing OpenGL Pipeline
    glutSwapBuffers;
}

void WindowInitialization(void) {
    printf("\nGL VERSION: %s", glGetString(GL_VERSION)); // Print OpenGL version
    printf("\nGL VENDOR: %s", glGetString(GL_VENDOR));   // Print OpenGL vendor
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black, last value is alpha
    glColor3f(1.0f, 1.0f, 1.0f);       // Set default drawing color to white
    glPointSize(10.0);                  // Set point size to 10 pixels
    glMatrixMode(GL_PROJECTION);        // Select projection matrix
    glLoadIdentity();                   // Load identity matrix
    gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh); // Set orthographic projection
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);                   // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(ww, wh);              // Set window size
    glutInitWindowPosition(180, 90);         // Set window position
    glutCreateWindow("Display a dot, line and polygon");       // Create a window with a title
    WindowInitialization();                  // Initialize window properties
    glutDisplayFunc(Display);                // Set display function
    glutMainLoop();                          // Enter the GLUT event processing loop
    return 0;                                // Return success
}

