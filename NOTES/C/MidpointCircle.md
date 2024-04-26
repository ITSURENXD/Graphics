# ⭕ MidPoint Circle Drawing Algorithm
- The **[Code:📑](../../C/MidpointCircle.cpp)**.

### ⬆️ Advantages
1. Involves simple integer additions so no need for round off operation.
2. Produces Mathematically Accurate results.
3. Fast because even though multiplication is required, it can be easily achieved by a shift operation.

### ⬇️ Disadvantages
1. Due to floating point calculation actual pixel position may be away from the circular path.
2. Due to Square Root Calculation, algorithm requires more computational time so becomes slower. 

&nbsp;
## 🤖 **Algorithm**
1. Input the line endpoints and store the Centre and the Radius of the Circle:
    ```cpp
    printf("Enter The Center Coordinate: ");
    scanf("%d %d", &Centre.x, &Centre.y);
    printf("Enter The Radius of the circle: ");
    scanf("%f", &Radius);
    ```
3. Calculate the Initial Value for Parameter; 
    -  for Integer:&emsp; $P_0 = 1 - r$.
    ```cpp
    int Parameter = 1 - Radius; 
    ```
4. Set 0 to x-initial and Radius to y-initial and draw the pixel at symmetric Coordinates in the oxtants.
    ```cpp
    Temp.x = 0; Temp.y = Radius; 
    SymmetricPlot(Temp, Centre);  
    ```
    - Here symmetric points can be calculates as:
    ```c
    void SymmetricPlot(Coordinates_Int Temp, Coordinates_Int Centre) {
        // First Quadrant 
        putpixel(Centre.x + Temp.x, Centre.y + Temp.y, WHITE);
        putpixel(Centre.x + Temp.y, Centre.y + Temp.x, WHITE);
        delay(15);
        // Second Quadrant
        putpixel(Centre.x - Temp.x, Centre.y + Temp.y, WHITE);
        putpixel(Centre.x - Temp.y, Centre.y + Temp.x, WHITE);
        delay(15);
        // Third Quadrant
        putpixel(Centre.x - Temp.x, Centre.y - Temp.y, WHITE);
        putpixel(Centre.x - Temp.y, Centre.y - Temp.x, WHITE);
        delay(15);
        // Fourth Quadrant
        putpixel(Centre.x + Temp.x, Centre.y - Temp.y, WHITE);
        putpixel(Centre.x + Temp.y, Centre.y - Temp.x, WHITE);
        delay(15);
    }
    ```
5. Repeat until either X or Y has reached equal values that is one octant is completed:
   - Calculate Parameter according to the value of the initial parameter.
    - Set y to y<sub>k</sub> or y<sub>k</sub> - 1 according to the parameter where k is the step.
    - Draw the pixel at that coordinate.
    - For ($P_k<0$):&emsp; $P_{k+1} = P_{k} + 2x + 3$
    - For ($P_k>=0$) y--:&emsp; $P_{k+1} = P_{k} + 2x -2y + 5 $
    ```cpp
    while (Temp.x <= Temp.y) {
        if (Parameter<0) {
            Parameter = Parameter + 2*Temp.x + 3;
        } else {
            Parameter = Parameter + 2*Temp.x - 2*Temp.y + 5;
            Temp.y--;
        }
        SymmetricPlot(Temp,Centre);
        Temp.x++;
    }
    ```

&nbsp;
# 📤 Output
- Ran using:
```powershell
g++ MidpointCircle.cpp -o MidpointCirlce -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 ; ./MidpointCircle.exe
```
<img src='./Resources/MidpointCircle.gif'>