# 📏 DDA Line Drawing Algorithm (Digital Differential Analyzer)
- The **[Code:📑](../../C/DDA.cpp)**.
- <img src='./Resources/DDA.svg' width="700px">
- &emsp; &emsp; &emsp; &emsp;fig: for (2,2) to (7,5) 

### ⬆️ Advantages
1. Simplest Method as it involves only integer additions.
2. Faster method for calculating pixels than the direct method.
3. Eliminates Multiplication in the equations by making use of raster characteristics.

### ⬇️ Disadvantages
1. Floating Point Arithmetic is still time consuming used internally like when calculating the increments.
2. While Fast, the roud-off Errors make the line jagged.
3. Rounding-off is time consuming still. 

&nbsp;
## 🤖 **Algorithm**
1. Input the line endpoints and store the left endpiont in (x-initial,y-initial) and right in (x-final,y-final).
    ```cpp
    printf("Enter The Starting Coordinate: ");
    scanf("%d %d", &Beginning.x, &Beginning.y);
    printf("Enter The Ending Cooardinate: ");
    scanf("%d %d", &Ending.x, &Ending.y);
    ```
2. Calculate the values for Differences in x and y. 
    ```cpp
    Difference.x = Ending.x - Beginning.x;
    Difference.y = Ending.y - Beginning.y;
    ```
3. Calculate steps as the absolute value of the largest difference.
    ```cpp
    if (abs(Difference.x) > abs(Difference.y)) {
        steps=abs(Difference.x);
    } else {
        steps=abs(Difference.y);
    }
    ```
4. Calculate the incremental values in x and y.
    ```cpp
    Increment.x=Difference.x/steps;
    Increment.y=Difference.y/steps;
    ```
5. Set x to x-initial and y to y-initial and draw the pixel at coordinate (round(x),round(y))
    ```cpp
    Temp.x=Beginning.x, Temp.y=Beginning.y;
    putpixel(round(Temp.x),round(Temp.y),WHITE);;
    ```
6. Repeat until steps is reached to its end.
    - Set x to x + x-increment.
    - Set y to y + y-increment.
    - Draw the pixel at coordinate (round(x),round(y));
    ```cpp
    for (int i=0; i<steps;i++) {
        delay(5);
        Temp.y+=Increment.y;
        Temp.x+=Increment.x;
        putpixel(round(Temp.x),round(Temp.y),WHITE);
    }
    ```

&nbsp;
# 📤 Output
- Ran using:
```powershell
g++ DDA.cpp -o DDA -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 ; ./DDA.exe
```
<img src='./Resources/DDA.gif'>