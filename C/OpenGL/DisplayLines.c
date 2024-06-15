#include <stdio.h>
#include <GL/glut.h>
#include "../Modules/GLGraphics.cpp"
// Draws a line

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clears pixel buffer

    glBegin(GL_LINES); //Begin Rendering Lines
        glVertex2i(10,10);
        glVertex2i(100,100);
    glEnd(); // End Redering Lines

    glFlush(); // Flushing OpenGL Pipeline
}

int main(int argc, char **argv) {
    PreInitialization(argc, argv, "Displaying a Line");
    WindowInitialization();                  // Initialize window properties
    glutDisplayFunc(Display);                // Set display function
    glutMainLoop();                          // Enter the GLUT event processing loop
    return 0;                                // Return success
}