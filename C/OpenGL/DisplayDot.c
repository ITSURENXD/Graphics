#include <stdio.h>
#include <GL/glut.h>
#include "../Modules/GLGraphics.cpp"
// Draws a dot

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clears pixel buffer

    glBegin(GL_POINTS); //Begin Rendering points
        glVertex2i(10,10);
    glEnd(); // End Redering Points

    glFlush(); // Flushing OpenGL Pipeline
}

int main(int argc, char **argv) {
    PreInitialization(argc,argv, "Displaying a Dot");
    WindowInitialization();                  // Initialize window properties
    glutDisplayFunc(Display);                // Set display function
    glutMainLoop();                          // Enter the GLUT event processing loop
    return 0;                                // Return success
}