# 🔺 OpenGL Polygon
- The **[Code:📑](../../C/OpenGL/DiplayingPolygons.c)**
- Drawing a polygon in OpenGL.
- Drawn using **GL_POLYGON**
```c 
void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex2i(100,100);
        glVertex2i(120,120);
        glVertex2i(100,140);
        glVertex2i(50,140);
        glVertex2i(30,120);
        glVertex2i(50,100);
    glEnd();
    glFlush(); 
}
```