# 🖌️ Scan Line Polygon Fill Algorithm
- The **[Code:📑](../../C/ScanLinePolygonFill.cpp)**.

### ⬆️ Advantages
1. Simple and Efficient as it only prosesses pixels that intersect the scan line within the polygon.
2. Easier Implementation

### ⬇️ Disadvantages
1. May not Handle self-intersecting polynomial.
2. Overhead for very large polygons.

&nbsp;
## 🤖 **Algorithm**
1. Get the Data and set them to the Edge List.
    ```cpp
    printf("\nPOLYGON DEFINITION: \n\nEnter the number of edges of Polygon: ");
    scanf("%d", NumberofEdges);
    printf("\nEnter the coordinates of Polygon: \n");
    for (int i=0; i < *NumberofEdges; i++) {
        printf("\tX%d Y%d: ", i,i);
        scanf("%d %d", &EdgeList[i].x, &EdgeList[i].y);
    }
    // Setting the End point to the First Point
    EdgeList[*NumberofEdges].x = EdgeList[0].x;
    EdgeList[*NumberofEdges].y = EdgeList[0].y;
    ```
2. Find the slopes of each edge and store them in an array.
    ```cpp
    Coordinates_Int Difference;
    for (int i=0; i < *NumberofEdges; i++) {
    Difference.x = EdgeList[i+1].x - EdgeList[i].x;
    Difference.y = EdgeList[i+1].y - EdgeList[i].y;
        if (Difference.y == 0) {
            Slopes[i] = 1.0;
        } else if (Difference.x == 0) {
            Slopes[i] = 0.0;
        } else {
            Slopes[i] = (float) Difference.x / Difference.y;
        }
    }
    ```
3. Find the Minimum and Maximum of the Y element of the polygon and run scan lines from minimum to the maximum.
    ```cpp
    int yMinimum(Coordinates_Int EdgeList[], int NumberofEdges) {
        int Minimum=EdgeList[0].y;
        for (int i=1; i < NumberofEdges; i++) {
            if (EdgeList[i].y<Minimum) {
                Minimum=EdgeList[i].y;
            }
        }
        return Minimum;
    }

    int yMaximum(Coordinates_Int EdgeList[], int NumberofEdges) {
        int Maximum=EdgeList[0].y;
        for (int i=0; i < NumberofEdges; i++) {
            if (EdgeList[i].y>Maximum) {
                Maximum=EdgeList[i].y;
            }
        }
        return Maximum;
    }
    ```
    ```cpp
    for (int Scanline=yMinimum(EdgeList,NumberofEdges); Scanline < yMaximum(EdgeList, NumberofEdges); Scanline++) {
        X_IntersectionFindFill(EdgeList, NumberofEdges, Scanline, Slopes);
    }
    ```
4. Identify the Edge Intersections in X coordinates of the scan line with the polygon.
    ```cpp
    int xIntercepts[MAX_SIZE];
    int NumberofIntercepts=0;
    for (int i=0; i < NumberofEdges; i++) {
        if ( ((EdgeList[i].y <= ScanLine) && (EdgeList[i+1].y>ScanLine)) || ((EdgeList[i].y > ScanLine) && (EdgeList[i+1].y<=ScanLine))) { 
            xIntercepts[NumberofIntercepts] = (int) (EdgeList[i].x + Slopes[i]*(ScanLine - EdgeList[i].y) );
            NumberofIntercepts++;
        }
    }
    ```
5. Sort the Intersections in ascending order.
    ```c
    for (int i=0; i < NumberofIntercepts-1; i++) {
        for ( int j=i+1; j < NumberofIntercepts; j++) {
            if (xIntercepts[i] > xIntercepts[j] ) {
                int temp = xIntercepts[i];
                xIntercepts[i] = xIntercepts[j];
                xIntercepts[j] = temp;
            }
        }
    }
    ```
6. Draw the lines from the least to the greatest x intercept values starting on even indices.
    ```cpp
    for (int i=0; i < NumberofIntercepts; i+=2) {
        delay(15);
        line(xIntercepts[i], ScanLine, xIntercepts[i+1]+1, ScanLine);
    }
    ```

&nbsp;
# 📤 Output
- Ran using:
```powershell
g++ ScanLinePolygonFill.cpp -o MidpointCirlce -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 ; ./ScanLinePolygonFill.exe
```
<img src='./Resources/ScanLinePolygonFill.gif'>