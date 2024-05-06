# 🌒 Trignometric Ellipse Drawing Algorithm
- The **[Code:📑](../../C/TrignometricEllipse.cpp)**.

### ⬆️ Advantages
1. Simple. 

### ⬇️ Disadvantages
1. Due to floating point calculation, actual pixel position may be away from the ellipse's path.

&nbsp;
## 🤖 **Algorithm**
1. Centre and the Radii of the Ellipse:
    ```cpp
    printf("Enter The Center Coordinate: ");
    scanf("%d %d", &Centre.x, &Centre.y);
    printf("Enter The Length of Major and Minor Axis: ");
    scanf("%d %d", &Radii.x,&Radii.y);
    ```
2. Repeat until Theta (The angle) reaches $360\degree$ starting from $\theta=0\degree$.
    - Calculate the c and y coordinates as: $x = x_c + r_x \cos(\theta)$ and $y = y_c + r_y \sin(\theta)$;
    - Draw the pixel at that coordinate.
    ```cpp
    for (int Theta=0;Theta<360;Theta++) {
        Temp.x = Centre.x + Radii.x * cos(Theta);
        Temp.y = Centre.y + Radii.y * sin(Theta);
        putpixel(round(Temp.x), round(Temp.y), WHITE);
        delay(15);
        Temp.x++;
    }
    ```

&nbsp;
# 📤 Output
- Ran using:
```powershell
g++ TrignometricEllipse.cpp -o TrignometricEllipse -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 ; ./TrignometricEllipse.exe
```
<img src='./Resources/TrignometricEllipse.gif'>