# 🎮 OpenGL Implementation
- The **[Code:📑](../../C/OpenGL//FirstProgram.c)** (Test Program)
- Open Graphics Library is a low-level graphics library specification. 
- The specification is Open to all windows but can't be exactly called open source.
- The 'open' in openGL doesn't mean it is Open Source but rather that the specification is open to other operating system.
- It is platform independent. 
- It provides the programmer with a small set of geometric primitives: points, polygons, imags, and bitmaps.
- The GLUT (OpenGL Utility Toolkit) to help in development of complicated 3D such as a sphere, torus, teapot. and features such as opening windows and handling interrupts from mouse or keyboard.

&nbsp;

# 📚 Basic Knowledge
- The basic knowledge regarding OpenGL

    ### Library
    - OpenGL libraries can be added in C as 
    ```c
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <GL/glut.h>
    ```
    ### Data Types
    - Comparisons between the C/C++ Types and OpenGL types

    | C/C++ Type            | Data Type                 | OpenGL name               |
    |-----------------------|---------------------------|---------------------------|
    | Signed Char           | 8 bit integer             | GLbyte                    |
    | Short                 | 16 bit integer            | GLshort                   |
    | Int or Long           | 32 bit integer            | GLint, GLsizei            |
    | Float                 | 32 bit floating point     | GLfloat, GLclampf         |
    | Double                | 64 bit floating point     | GLdouble, GLclampd        |
    | Unsigned Char         | 8 bit unsigned integer    | GLubyte, GLboolean        |
    | Unsigned Short        | 16 bit unsigned integer   | GLushort                  |
    | Unsigned int or long  | 32 bit unsigned integer   | GLuint, GLenum, GLbitfield|  

    ### Drawing Primitives
    - Triggered using:
    ```c
    glBegin(#Value);
        glVertex2i(x,y);
        // other vertices
    glend();
    glflush();
    ```
    | Value                 | Meaning                                           |
    |-----------------------|---------------------------------------------------|
    | GL_POINTS             | Individual points/vertices                        | 
    | GL_LINES              | Individual Line Segments                          |
    | GL_LINE_STRIP         | Connected Line Segments                           |
    | GL_LINE_LOOP          | Connected Line Segments joining $1^{st}$ and last |
    | GL_TRIANGLES          | Vertex Triples Interpreted as Triangles           |
    | GL_TRIANGLES_STRIP    | Linked Strip of Triangles                         |
    | GL_TRIANGLES_FAN      | Linked Fan of Triangles                           |
    | GL_QUADS              | Vertex Quadruples interpreted as Quadrilaterals   |
    | GL_QUADS_STRIP        | Linked strip of Quadrilaterals                    |
    | GL_POLYGON            | boundary of simple, convex polygon                |

    ### Basic Setup
    - This setups of the environment and windows to display things
    ```c
    void Display(void) {
        glClear(GL_COLOR_BUFFER_BIT);

        // CODE HERE

        glFlush();
    }
    void WindowInitialization(float Red, float Green, float Blue) {
        glClearColor(0.0, 0.0, 0.0, 0.0); 
        glColor3f(0.0f, 1.0f, 0.0f);       
        glPointSize(10.0);                  
        glMatrixMode(GL_PROJECTION);       
        gluOrtho2D(0.0, 200, 0.0, 150); 
    }

    int main(int argc, char **argv) {
        glutInit(&argc, argv);                   
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
        glutInitWindowSize(500, 500);            
        glutInitWindowPosition(180, 90);        
        glutCreateWindow("Name of window");       
        WindowInitialization(0.0,0.0,0.0);                  
        glutDisplayFunc(Display);                
        glutMainLoop();                         
        return 0;                               
    }
    ```

# 🛠️ Setup Procedures
- To compile the application 
    ### 📋 Rquirements
    - Requirements I had to install to run it on fedora linux.
    1. #### OpenGL Library
    ```bash
    sudo dnf install mesa-libGL-devel
    ```
    2. #### OpenGL Utility Toolkit (GLU) library
    ```bash
    sudo dnf install mesa-libGLU-devel
    ```
    3. #### FreeGlut
    ```bash
    sudo dnf install freeglut-devel
    ```

    ### ▶️ Execution Script
    - Executed with: (foo is the filename without the file extension)
    ```bash
    gcc test1.c -o test1 -lGL -lGLU -lglut && ./test1
    ```

# 🧰 Applications 🚧
- OpenGL's use is demonstrated as
1. [Drawing Points](./OpenGLPoints.md)
2. [Drawing Lines](./OpenGLLines.md) 
3. [Drawing Polygons](./OpenGLPolygon.md) 
4. [Basic Lighting](./OpenGLBasicLighting.md) 🚧