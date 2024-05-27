#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clears pixel buffer and depth buffer

    glutSolidSphere(1.0,100,16);
    //glutSolidTeapot(0.5); 
    glFlush(); // Flushing OpenGL Pipeline
}

void LightingSettingsInit(void) {
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shinines[] = {50.0};
    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0}; // Changed to directional light
    GLfloat ambient_light[] = {0.2, 0.2, 0.2, 1.0}; // Adjust ambient light here
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shinines);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light); // Set ambient light
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}


void reshape(int w, int h) {
    glViewport(0,0, (GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w<=h) {
        glOrtho(-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w, 1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    } else {
        glOrtho(-1.5*(GLfloat)h/(GLfloat)w, 1.5*(GLfloat)h/(GLfloat)w, -1.5, 1.5,-10.0, 10.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);                      // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(800, 600);               // Set window size
    glutInitWindowPosition(180, 90);            // Set window position
    glutCreateWindow("Displaying Sphere");      // Create a window with a title
    LightingSettingsInit();                     // Set the Lighting Settings
    glutDisplayFunc(Display);                   // Set the Display
    glutReshapeFunc(reshape);                   // Reshape 
    glutMainLoop();                             // Enter the GLUT event processing loop
    return 0;                                   // Return success
}
