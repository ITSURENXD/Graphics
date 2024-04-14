#include <SDL2/SDL.h>
#include <stdio.h>

// Window dimensions
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Point coordinates
const int POINT_X = 400;
const int POINT_Y = 300;

// Function to draw a point on the SDL renderer
void drawPoint(SDL_Renderer *renderer, int x, int y) {
    SDL_RenderDrawPoint(renderer, x, y);
}

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window and renderer
    SDL_Window *window = SDL_CreateWindow("Point Plotter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Unable to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "Unable to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set renderer color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Clear the renderer
    SDL_RenderClear(renderer);

    // Set renderer color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Draw the point
    drawPoint(renderer, POINT_X, POINT_Y);

    // Present the renderer
    SDL_RenderPresent(renderer);

    // Main loop
    SDL_Event event;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
