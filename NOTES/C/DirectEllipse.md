# 🌒 Direct Ellipse Drawing Algorithm
- The **[Code:📑](../../C/DirectEllipse.cpp)**.

### ⬆️ Advantages
1. Simple. 

### ⬇️ Disadvantages
1. Due to floating point calculation actual pixel position may be away from the ellipse's path.
2. Due to Square Root Calculation, algorithm requires more computational time so becomes slower. 

&nbsp;
## 🤖 **Algorithm**
1. Centre and the Radii of the Ellipse:
    ```cpp
    printf("Enter The Center Coordinate: ");
    scanf("%d %d", &Centre.x, &Centre.y);
    printf("Enter The Length of Major and Minor Axis: ");
    scanf("%d %d", &Radii.x,&Radii.y);
    ```
2. Set x to x-radius units left of the center.
    ```cpp
    Temp.x = Centre.x - Radii.x;  
    ```
3. Repeat until x reaches Radius Distance opposite way from the X-coordinate of the centre of the Ellipse.
    - Calculate the y coordinate according to the formula: $y = y_c \pm \frac{r_y}{r_x}\sqrt{r_x^2-(x-x_c)^2}$ individually.
    - Draw the pixel at the coordinates returned.
    ```cpp
    while (Temp.x < (Temp.x + Radii.x)) {
        Temp.y = Centre.y + ((Radii.y/Radii.x) * sqrt( pow(Radii.x,2)-pow((Temp.x-Centre.x),2) ) );
        putpixel(round(Temp.x), round(Temp.y), WHITE);

        Temp.y = Centre.y - ((Radii.y/Radii.x) * sqrt( pow(Radii.x,2)-pow((Temp.x-Centre.x),2) ) );
        putpixel(round(Temp.x), round(Temp.y), WHITE);

        Temp.x++;
    }
    ```

&nbsp;
# 📤 Output
- Ran using:
```powershell
g++ DirectEllipse.cpp -o DirectEllipse -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 ; ./DirectEllipse.exe
```
<img src='./Resources/DirectEllipse.gif'>