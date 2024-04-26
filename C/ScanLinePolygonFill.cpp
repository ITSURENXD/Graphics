#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include "./Modules/Graphics.cpp"

#define MAX_SIZE 50

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

void PolygonInputs(Coordinates_Int EdgeList[], int *NumberofEdges, float Slopes[]) {
    // Taking the Number of Edges
    printf("\nPOLYGON DEFINITION: \n\nEnter the number of edges of Polygon: ");
    scanf("%d", NumberofEdges);
    // Entering the Edges to the Array
    printf("\nEnter the coordinates of Polygon: \n");
    for (int i=0; i < *NumberofEdges; i++) {
        printf("\tX%d Y%d: ", i,i);
        scanf("%d %d", &EdgeList[i].x, &EdgeList[i].y);
    }
    // Setting the End point to the First Point
    EdgeList[*NumberofEdges].x = EdgeList[0].x;
    EdgeList[*NumberofEdges].y = EdgeList[0].y;


    // Slope Setups
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
}

void PolygonDraw(Coordinates_Int EdgeList[], int NumberofEdges) {
    for (int i=0; i < NumberofEdges; i++) {
        line(EdgeList[i].x, EdgeList[i].y, EdgeList[i+1].x, EdgeList[i+1].y);
    }
}

void X_IntersectionFindFill(Coordinates_Int EdgeList[], int NumberofEdges, int ScanLine, float Slopes[]) {
    // For a Given Scan Line
    int xIntercepts[MAX_SIZE];
    int NumberofIntercepts=0;
    for (int i=0; i < NumberofEdges; i++) {
        // Listing Intersections on a scanline
        // ScanLine Separates Two adjacentPoints in incresing slopr or decreasing slope which means there is an intersection
        if ( ((EdgeList[i].y <= ScanLine) && (EdgeList[i+1].y>ScanLine)) || ((EdgeList[i].y > ScanLine) && (EdgeList[i+1].y<=ScanLine))) { 
            // x intercept = x + (Δx/Δy) * (scanline -y);
            xIntercepts[NumberofIntercepts] = (int) (EdgeList[i].x + Slopes[i]*(ScanLine - EdgeList[i].y) );
            NumberofIntercepts++;
        }
    }

    // Sorting Intersections
    for (int i=0; i < NumberofIntercepts-1; i++) {
        for ( int j=i+1; j < NumberofIntercepts; j++) {
            if (xIntercepts[i] > xIntercepts[j] ) {
                int temp = xIntercepts[i];
                xIntercepts[i] = xIntercepts[j];
                xIntercepts[j] = temp;
            }
        }
    }
    
    // Drawing
    for (int i=0; i < NumberofIntercepts; i+=2) {
        delay(15);
        line(xIntercepts[i], ScanLine, xIntercepts[i+1]+1, ScanLine);
    }
}

int main() {
    system("cls");
    int NumberofEdges; float Slopes[MAX_SIZE];
    Coordinates_Int EdgeList[MAX_SIZE];

    PolygonInputs(EdgeList, &NumberofEdges, Slopes); 

    graphicsinits();
    PolygonDraw( EdgeList, NumberofEdges);

    // Scan Lines Rasterizing
    for (int Scanline=yMinimum(EdgeList,NumberofEdges); Scanline < yMaximum(EdgeList, NumberofEdges); Scanline++) {
        X_IntersectionFindFill(EdgeList, NumberofEdges, Scanline, Slopes);
    }

    getch();
    closegraph();
}