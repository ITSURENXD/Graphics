#  💧  Flood Fill Algorithm
- The **[Code:📑](../../C/FloodFill.cpp)**.

### 🌿 Types of Flood Fill Algorithm
1. **[4 Connected](../../C/FloodFill.cpp#L49)**
2. **[8 Connected](../../C/FloodFill.cpp#L61)**

### ⬆️ Advantages
1. Handles Complex Shapes.
2. Can do multi colored boundry.

### ⬇️ Disadvantages
1. Performance Degradation.
3. Recursive call of boundry fill may cost a lot of memory.

&nbsp;
## 🤖 **Algorithm**
1. Inserting a Circle and selecting a seed point within the boundry.
    ```cpp
    void InputsCircle( Coordinates_Int *Centre, float *Radius) {
        printf("Enter The Center Coordinate: ");
        scanf("%d %d", &Centre->x, &Centre->y);
        printf("Enter The Radius of the circle: ");
        scanf("%f", Radius);
    }

    void InputsSeed(Coordinates_Int *Seed, Coordinates_Int Centre, int Radius) {
        do {
            printf("Enter a Seed Point for the Circle (%d,%d, %d): ", Centre.x, Centre.y, Radius);
            fflush(stdin);
            scanf("%d %d", &Seed->x, &Seed->y);
        } while ((pow(Seed->x-Centre.x,2) + pow(Seed->y-Centre.y,2) - pow(Radius,2))>0);
    }

    void InputsColor(int *FillColor, int *BoundryColor) {
        // Colors Printing
        for (int i = 0; i < 16; i++) {
            printf("%-12s%-2d\n", colors[i], i);
        }
        //Choosing colors
        do {
            printf("Enter the Fill color and BoundryColor in Numbers: ");
            scanf("%d %d", FillColor, BoundryColor);
        } while (*FillColor>15 || *BoundryColor>15);
    }
    ```
2. Draw the circle.
    ```cpp
    void drawCircle(Coordinates_Int Centre, int Radius) {
        graphicsinits();
        // Thick walls needed for 8 connected one
        circle(Centre.x,Centre.y, Radius-1);
        circle(Centre.x,Centre.y, Radius);
        circle(Centre.x,Centre.y, Radius+1);
    }
    ```
3. If Selected Pixel is an old fill color, replace it with a new one. 
    ```cpp
    void FloodFill4Connected(int x, int y, int FillColor, int AreaPreviousColor) {
        if ( ((getpixel(x,y)) == AreaPreviousColor)) {
            delay(0.9);
            putpixel(x, y,FillColor);

            FloodFill4Connected(x+1,y, FillColor, AreaPreviousColor);
            FloodFill4Connected(x-1,y, FillColor, AreaPreviousColor);
            FloodFill4Connected(x,y+1, FillColor, AreaPreviousColor);
            FloodFill4Connected(x,y-1, FillColor, AreaPreviousColor);
        }
    }
    void FloodFill8Connected(int x, int y, int FillColor, int AreaPreviousColor) {
        if ( ((getpixel(x,y)) == AreaPreviousColor)) {
            delay(0.9);
            putpixel(x, y,FillColor);

            FloodFill8Connected(x+1,y, FillColor, AreaPreviousColor);
            FloodFill8Connected(x-1,y, FillColor, AreaPreviousColor);
            FloodFill8Connected(x,y+1, FillColor, AreaPreviousColor);
            FloodFill8Connected(x,y-1, FillColor, AreaPreviousColor);
            FloodFill8Connected(x+1,y+1, FillColor, AreaPreviousColor);
            FloodFill8Connected(x+1,y-1, FillColor, AreaPreviousColor);
            FloodFill8Connected(x-1,y+1, FillColor, AreaPreviousColor);
            FloodFill8Connected(x-1,y-1, FillColor, AreaPreviousColor);
        }
    }
    ```

&nbsp;
# 📤 Output
- Ran using:
```powershell
g++ FloodFill.cpp -o FloodFill -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 ; ./FloodFill.exe
```
<img src='./Resources/FloodFill.gif'>