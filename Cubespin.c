#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <time.h>

void graphicsinits() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver,&gmode,NULL);
}

void delays(float number_of_seconds){
    float milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

void cube_primit(float points[5][2]) {
    //For maual line wise basis
    for (int i=0; i<4;i++) {
        //top face
        line(points[i][0],50,points[i+1][0],50);
        //bottom face
        line(points[i][0],100,points[i+1][0],100);
        //fronts
        line(points[i][0],50,points[i][0],100);
        printf("\njoining (%f,%f) and (%f,%f)",points[i][0],points[i][0],points[i+1][0],points[i+1][1]);
    }
}

void drawer(float points[5][2]) {
    //converter
    printf("\nConverting 3D Structure to 2D");
    int topface[10],botface[10];
    int frontface[10]={(int)points[0][0],50,(int)points[1][0],50,(int)points[1][0],100,(int)points[0][0],100,(int)points[0][0],50};
    int rightface[10]={(int)points[1][0],50,(int)points[2][0],50,(int)points[2][0],100,(int)points[1][0],100,(int)points[1][0],50};
    int backface[10]={(int)points[2][0],50,(int)points[3][0],50,(int)points[3][0],100,(int)points[2][0],100,(int)points[2][0],50};
    int leftface[10]={(int)points[3][0],50,(int)points[4][0],50,(int)points[4][0],100,(int)points[3][0],100,(int)points[3][0],50};
    int counter=0;
    for(int i=0;i<10;i=i+2) {
        topface[i]=points[counter][0];
        topface[i+1]=50;
        botface[i]=points[counter][0];
        botface[i+1]=100;
        counter++;
    }

    int fills=SOLID_FILL;
    //top and bottom faces 
    printf("\nGenerating and tracking topface");
    setfillstyle(fills, RED);
    fillpoly(5,topface);
    printf("\nGenerating and tracking bottomface");
    setfillstyle(fills, RED);
    fillpoly(5,botface);
    //viewable landscape
    //Optimizations: faces won't be displayed if they go behind
    if (points[0][1]<=50 || points[1][1]<=50) {
        printf("\nGenerating and tracking frontface");
        setfillstyle(fills, GREEN);
        fillpoly(5,frontface);
    }
    if (points[1][1]<=50 || points[2][1]<=50) {
        printf("\nGenerating and tracking rightface");
        setfillstyle(fills, BLUE);
        fillpoly(5,rightface);
    }
    if (points[2][1]<=50 || points[3][1]<=50) {
        printf("\nGenerating and tracking backface");
        setfillstyle(fills, YELLOW);
        fillpoly(5,backface);
    }
    if (points[3][1]<=50 || points[4][1]<=50) {
        printf("\nGenerating and tracking leftface");
        setfillstyle(fills, RED);
        fillpoly(5,leftface);
    }
}

int main() {
    //float points[5][2]={{50,50},{100,50},{100,100},{50,100},{50,50}};
    float points[5][2]={{50,50},{100,50},{100,100},{50,100},{50,50}};
    float rloc[5][2],xrot,yrot,radians;

    graphicsinits();
    for (float degrees=0;degrees<=1440;degrees=degrees+2) {
        printf("\ndegrees: %d",degrees);
        radians = 0.01745329251994329576924*degrees;
        for(int i=0;i<5;i++) {
                rloc[i][0]=(points[i][0]-75)*cos(radians)-(points[i][1]-75)*sin(radians)+75;
                rloc[i][1]=(points[i][0]-75)*sin(radians)+(points[i][1]-75)*cos(radians)+75;
        }
        printf("\n---------------------------------------");
        drawer(rloc);
        delays(0.04);
        cleardevice();
        
    }
    getch();
    closegraph();
}