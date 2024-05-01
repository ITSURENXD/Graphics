# 🚧 Boundry Fill Algorithm
- The **[Code:📑](../../C/BoundryFill.cpp)**.

### 🌿 Types of Boundry Fill Algorithm
1. **[4 Connected](../../C/BoundryFill.cpp#L49)**
2. **[8 Connected](../../C/BoundryFill.cpp#L61)**

### ⬆️ Advantages
1. Handles Complex Shapes.
2. Easier Implementation

### ⬇️ Disadvantages
1. Performance Degradation.
2. Can't do multi colored boundry.
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
3. If Selected Pixel is not a Fill Color or a Boundry color, Fill the pixel and 4 or 8 adjacent ones.
    ```cpp
    void BoundryFill4Connected(int x, int y, int FillColor, int BoundryColor) {
        if ( ((getpixel(x,y)) != BoundryColor) && ((getpixel(x,y)) != FillColor)) {
            delay(0.9);
            putpixel(x, y,FillColor);

            BoundryFill4Connected(x+1,y, FillColor, BoundryColor);
            BoundryFill4Connected(x-1,y, FillColor, BoundryColor);
            BoundryFill4Connected(x,y+1, FillColor, BoundryColor);
            BoundryFill4Connected(x,y-1, FillColor, BoundryColor);
        }
    }

    void BoundryFill8Connected(int x, int y, int FillColor, int BoundryColor) {
        if ( ((getpixel(x,y)) != BoundryColor) && ((getpixel(x,y)) != FillColor)) {
            delay(0.9);
            putpixel(x, y,FillColor);

            BoundryFill8Connected(x-1,y, FillColor, BoundryColor);
            BoundryFill8Connected(x+1,y, FillColor, BoundryColor);
            BoundryFill8Connected(x,y-1, FillColor, BoundryColor);
            BoundryFill8Connected(x,y+1, FillColor, BoundryColor);
            BoundryFill8Connected(x-1,y-1, FillColor, BoundryColor);
            BoundryFill8Connected(x-1,y+1, FillColor, BoundryColor);
            BoundryFill8Connected(x+1,y-1, FillColor, BoundryColor);
            BoundryFill8Connected(x+1,y+1, FillColor, BoundryColor);
        }
    }
    ```

&nbsp;
# 📤 Output
- Ran using:
```powershell
g++ BoundryFill.cpp -o BoundryFill -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 ; ./BoundryFill.exe
```
<img src='./Resources/BoundryFill.gif'>