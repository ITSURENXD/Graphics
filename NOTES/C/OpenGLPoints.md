# 🔵 OpenGL Points
- The **[Code:📑](../../C/OpenGL/DisplayDot.c)**
- Drawing vertices/points in OpenGL.
- Drawn using **GL_POINTS**
```c 
void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
        glVertex2i(10,10);
    glEnd();
    glFlush(); 
}
```