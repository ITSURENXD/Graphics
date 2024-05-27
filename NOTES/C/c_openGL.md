# 🎮 OpenGL Implementation
- The **[Code:📑](../../C/OpenGL//FirstProgram.c)** (Test Program)

&nbsp;

# 📚 Basic Knowledge
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
1. [Drawing Points](./OpenGLPoints.md) 🚧
2. [Drawing Lines](./OpenGLLines.md) 🚧
3. [Drawing Polygons](./OpenGLPolygon.md) 🚧
4. [Basic Lighting](./OpenGLBasicLighting.md) 🚧