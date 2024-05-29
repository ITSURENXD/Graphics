# 🌒 MidPoint Ellipse Drawing Algorithm
- The **[Code:📑](../../C/MidpointEllipse.cpp)**.

### ⬆️ Advantages
1. Involves simple integer additions so no need for round off operation.
2. Produces Mathematically Accurate results.
3. Fast because even though multiplication is required, it can be easily achieved by a shift operation.

### ⬇️ Disadvantages
1. Due to floating point calculation actual pixel position may be away from the ellipse's path.
2. Due to Square Root Calculation, algorithm requires more computational time so becomes slower. 

&nbsp;
## 🤖 **Algorithm**
1. Input the Centre and the Radius of the Ellipse:
    ```cpp
    printf("Enter The Center Coordinate: ");
    scanf("%d %d", &Centre.x ,  &Centre.y ) ;
    printf("Enter The Length of Major and Minor Axis: ");
    scanf("%d %d", &Radii.x,&Radii.y);
    ```
3. **REGION 1**: Calculate the Initial Value for $P_{10}$; 
    -  for Integer:&emsp; $\color{#1DACD6}P_{10} = r_y^2 - r_x^2 r_y + \frac{1}{4} r_x^2$.
    ```cpp
    int Parameter1 = pow(Radii.y,2) - (pow(Radii.x,2)*Radii.y) + (pow(Radii.x,2)/4);
    ```
4. **REGION 1**: Set x-initial to 0 and y-initial to $r_y$ and draw the pixel at symmetric Coordinates in the oxtants.
    ```cpp
    Temp.x = 0; Temp.y = Radii.y;
    SymmetricPlot(Temp,Centre);
    ```
    - Here symmetric points can be calculates as:
    ```c
    void SymmetricPlot(Coordinates_Int Temp, Coordinates_Int Centre) {
        // First Quadrant 
        putpixel(Centre.x + Temp.x, Centre.y + Temp.y, WHITE);
        delay(15);
        // Second Quadrant
        putpixel(Centre.x - Temp.x, Centre.y + Temp.y, WHITE);
        delay(15);
        // Third Quadrant
        putpixel(Centre.x - Temp.x, Centre.y - Temp.y, WHITE);
        delay(15);
        // Fourth Quadrant
        putpixel(Centre.x + Temp.x, Centre.y - Temp.y, WHITE);
        delay(15);
    }
    ```
5. **REGION 1**: Repeat while Slope is greater than -1 (i.e $2r_y^2 x_k < 2r_x^2 y_k$) after which we can enter REGION 2.
    - Calculate Parameter according to the value of the initial parameter.
    - Set y to y<sub>k</sub> or y<sub>k</sub> - 1 according to the parameter where k is the step.
    - Draw the pixel at that coordinate. 
    - Increment the value of x;
    - For ($P_{1k}<0$):&emsp; $\color{#1DACD6}P_{1k+1} = P_{1k} + 2r_y^2 (x_k+1) + r_y^2$
    - For ($P_{1k}>=0$) y--:&emsp; $\color{#1DACD6}P_{1k+1} = P_{1k} + 2r_y^2 (x_k+1) - 2r_x^2 (y_k-1) + r_y^2$
    ```cpp
    while (2*pow(Radii.y,2)*(Temp.x+1) < 2*pow(Radii.x,2)*Temp.y) { 
        Parameter1, 2*pow(Radii.y,2)*(Temp.x+1), 2*pow(Radii.x,2)*Temp.y);
        Temp.x++;

        if (Parameter1<0) {
            Parameter1 = Parameter1 + (2*pow(Radii.y,2) * Temp.x) + pow(Radii.y,2);
        } else {
            Temp.y--;
            Parameter1 = Parameter1 + (2*pow(Radii.y,2) * Temp.x) - (2*pow(Radii.x,2) * Temp.y) + pow(Radii.y,2);
        }
        SymmetricPlot(Temp,Centre);
    }
    ```
6. **REGION 2**: Calculate the Initial Value for $P_{20}$; 
    -  for Integer:&emsp; $\color{#1DACD6}P_{20} = r_y^2(x_0 + \frac{1}{2})^2 + r_x^2 (y_0 -1)^2 - r_x^2 r_y^2$.
    ```cpp
   int Parameter2 = pow(Radii.y,2) * pow((Temp.x + 0.5),2) + pow(Radii.x,2)*pow((Temp.y-1),2) - pow(Radii.x,2)*pow(Radii.y,2);
    ```
7. **REGION 2**: Repeat until $y != 0$.
    - Calculate Parameter according to the value of the initial parameter.
    - Set x to x<sub>k</sub> or x<sub>k</sub> +1 according to the parameter where k is the step.
    - Draw the pixel at that coordinate.
    - Decrement the Value of y.
    - For ($P_{2k}<0$) x++:&emsp; $\color{#1DACD6}P_{2k+1} = P_{2k} + 2r_y^2 (x_k+1) - 2r_x^2 (y_k-1) + r_x^2$
    - For ($P_{2k}>=0$):&emsp; $\color{#1DACD6}P_{2k+1} = P_{2k} - 2r_x^2 (y_k-1) + r_x^2$
    ```cpp
    while (Temp.y!=0) {
        Temp.y--;

        if (Parameter2 <= 0) {
            Temp.x++;
            Parameter2 = Parameter2 + (2*pow(Radii.y,2) * Temp.x) - (2*pow(Radii.x,2) * Temp.y) + pow(Radii.x,2);
        } else {
            Parameter2 = Parameter2 - (2*pow(Radii.x,2) * Temp.y) + pow(Radii.x,2);
        }
        SymmetricPlot(Temp,Centre);
    }
    ```

&nbsp;
# 📤 Output
- Ran using:
```powershell
g++ MidpointEllipse.cpp -o MidpointEllipse -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 ; ./MidpointEllipse.exe
```
<img src='./Resources/MidpointEllipse.gif'>
