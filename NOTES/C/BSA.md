# 📏 BSA Line Drawing Algorithm (Bresenham's)
- The **[Code:📑](../../C/BSA.cpp)**.
- <img src='./Resources/DDA.svg' width="700px">
- &emsp; &emsp; &emsp; &emsp;fig: for (2,2) to (7,5) 

### ⬆️ Advantages
1. Involves simple integer additions so no need for round off operation.
2. More efficent than DDA.
3. Can be used generate Circle and other curves and is not limited to just lines.
4. Produces Mathematically Accurate results.
5. Faster than DDA because even though multiplication is required, it can be easily achieved by a shift operation.

### ⬇️ Disadvantages
1. An additional calculation for parameters must be done with each step. 

&nbsp;
## 🤖 **Algorithm**
1. Input the line endpoints and store the left endpoint in (x-initial,y-initial) and right in (x-final,y-final).
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
3. Calculate the Initial Value for Parameter; 
    -  for (m<=1):&emsp; $\color{#1DACD6}P_0 = 2\Delta y - \Delta x$; 
    -  for (m>1):&emsp; $\color{#1DACD6}P_0 = 2\Delta x - \Delta y$; 
    1. If Difference on X-coordinates is greater than Y-coordinates:
    ```cpp
    parameter=2*Difference.y-Difference.x; 
    ```
    2. Else If Difference on Y-coordinates is greater than X-coordinates:
    ```cpp
    parameter=2*Difference.x-Difference.y; 
    ```
4. Set x-initial to x and y-initial to y and draw the pixel at the coordinate (round(x),round(y)).
    ```cpp
    Temp.x=Beginning.x, Temp.y=Beginning.y;
    putpixel(round(Temp.x),round(Temp.y),WHITE);;
    ```
5. Repeat until either X or Y has reached from the beginning coordinates to the ending coordinates according to the values of m:
    - Calculate Parameter according to the value of the initial parameter.
    - Set y to $y_k$ or $y_k + 1$ according to the parameter where k is the step.
    - Draw the pixel at that coordinate.
    - For ( |m| < 1): 
        1. If ($P_k < 0$):&emsp; $\color{#1DACD6}P_{k+1} = P_k + 2\Delta y$
        2. If ($P_k >= 0$):&emsp; $\color{#1DACD6}P_{k+1} = P_k + 2\Delta y - 2\Delta x$
    - For ( |m| >=1): just interchange $\Delta x$ and $\Delta y$ on parameters. 
    ```cpp
    if (Difference.x>=Difference.y)    {   
        parameter=2*Difference.y-Difference.x; 
        
        while (Temp.x<Ending.x) {
            Temp.x++;
            if(parameter<0) {
                // Temp.y Remains the same
                parameter=parameter+2*Difference.y; // p(k+1) = pk + 2*Δy;
            } else {
                
                Temp.y++;
                parameter=parameter+(2*Difference.y)-(2*Difference.x); // p(k+1) = pk + 2*Δy - 2*Δx;
            }
            putpixel(Temp.x,Temp.y,WHITE);
        }
    } else if (Difference.y>Difference.x) {
        parameter=2*Difference.x-Difference.y; 
        while (Temp.y<Ending.y) {
            Temp.y++;
            if(parameter<0) {
                // Temp.y Remains the same
                parameter=parameter+2*Difference.x; // p(k+1) = pk + 2*Δx;
            } else {
                Temp.x++;
                parameter=parameter+(2*Difference.x)-(2*Difference.y); // p(k+1) = pk + 2*Δx - 2*Δy;
            }
            putpixel(Temp.x,Temp.y,WHITE);
        }
    }
    ```

&nbsp;
# 📤 Output
- Ran using:
```powershell
g++ BSA.cpp -o BSA -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 ; ./BSA.exe
```
<img src='./Resources/BSA.gif'>