#ifndef GRAPHICS_WRAPPER_H
#define GRAPHICS_WRAPPER_H

#include <graphics.h>

#endif // GRAPHICS_WRAPPER_H
#ifndef TIME_WRAPPER_H
#define TIME_WRAPPER_H

#include <time.h>

#endif // TIME_WRAPPER_H

typedef struct Coordinates_Integer {
    int x;
    int y;
} Coordinates_Int;

typedef struct Coordinates_Float {
    float x;
    float y;
} Coordinates_Float;

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