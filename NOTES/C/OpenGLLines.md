# ➖ OpenGL Lines
- The **[Code:📑](../../C/OpenGL/DisplayLines.c)**
- Drawing Lines in OpenGL.
- Drawn using **GL_LINES**
```c 
void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
        glVertex2i(10,10);
        glVertex2i(100,100);
    glEnd();
    glFlush(); 
}
```