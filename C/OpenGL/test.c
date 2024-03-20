#include <GL/glut.h>

// Function to plot a point at specified coordinates (x, y)
void plotPoint(float x, float y) {
    // Set color to red
    static int r=0,g=1,b=1;
    glColor3f((r++)%2, (g++)%2, (b++)%2);

    // Set point size to 10 (larger pixel)
    glPointSize(10.0);

    // Plot a pixel at the specified coordinates (x, y)
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set up the viewport
    glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    
    // Set up orthographic projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-600, 600, -600, 600); // Assuming a window size of 800x600 pixels
    
    // Set the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Plot points at specified coordinates
    /*int x=0,y=0;
    for (int i=x-5;i<x+5;i++) {
        for (int j=y-5; j<y+5;j++) {
            plotPoint(i, j);
        }
    }
    */
   plotPoint(0,0);
   plotPoint(400,0);
   plotPoint(0,10);

    // Swap the front and back buffers to display the rendered image
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    
    // Set window size
    glutInitWindowSize(1200, 1200);

    // Set window position
    glutInitWindowPosition(100, 100);

    // Create window with title
    glutCreateWindow("Automated Point Plotting");

    // Set the clear color (background color) to black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the GLUT event loop
    glutMainLoop();

    return 0;
}
