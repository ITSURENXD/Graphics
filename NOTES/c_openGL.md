# 🎮 OpenGL Implementation
- The **[Code:📑](../C/OpenGL/test.c)**

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

    ### ▶️ Execution
    - Executed with: (foo is the filename without the file extension)
    ```bash
    gcc foo.c -o test -lGL -lGLU -lglut && ./foo
    ```