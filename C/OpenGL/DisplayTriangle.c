#include <stdio.h>
#include <GL/glut.h>
#include "../Modules/GLGraphics.cpp"
// Draws a polygon

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clears pixel buffer

    glBegin(GL_TRIANGLES); //Begin Rendering polygon
        glVertex2i(50,50);
        glVertex2i(70,60);
        glVertex2i(30,60);
    glEnd(); // End Redering Polygon

    glFlush(); // Flushing OpenGL Pipeline
}

int main(int argc, char **argv) {
    PreInitialization(argc,argv,"Displaying a Triangle");
    WindowInitialization();                  // Initialize window properties
    glutDisplayFunc(Display);                // Set display function
    glutMainLoop();                          // Enter the GLUT event processing loop
    return 0;                                // Return success
}
