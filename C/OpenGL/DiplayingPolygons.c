#include <stdio.h>
#include <GL/glut.h>
#include "../Modules/GLGraphics.cpp"
// Draws a polygon

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clears pixel buffer

    glBegin(GL_POLYGON); //Begin Rendering polygon
        glVertex2i(10,10);
        glVertex2i(10,30);
        glVertex2i(40,3);
        glVertex2i(60,15);
        glVertex2i(40,10);
    glEnd(); // End Redering Polygon

    glFlush(); // Flushing OpenGL Pipeline
}

int main(int argc, char **argv) {
    PreInitialization(argc,argv,"Displaying Polygon");
    WindowInitialization();                  // Initialize window properties
    glutDisplayFunc(Display);                // Set display function
    glutMainLoop();                          // Enter the GLUT event processing loop
    return 0;                                // Return success
}
