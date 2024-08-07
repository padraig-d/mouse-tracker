#include <SDL2/SDL.h>
#include <iostream>
#include <random>
#include <vector>
#include "../include/macros.hpp"

int main() {
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WIDTH, HEIGHT,
                                          0);

    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    if(!window) {
        std::cout << "Failed to create window\n";
        return -1;
    }

    std::vector<Rectangle> rectangles;

    rectangles.push_back(Rectangle());
    SDL_Rect* rect = rectangles[0].getRect();



    while (true) {
        SDL_Delay(17);   // 60-ish FPS framecap

        SDL_Event event;
        int i = 0;

        prepare(renderer);

        for (Rectangle rect : rectangles) {
            rectangles[i].Hover();
            draw(renderer, rectangles[i].getRect());
            ++i;
        }

        while(SDL_PollEvent(&event)) { 
            if (event.type == SDL_QUIT) { SDL_Quit(); return 0; }
            if (event.key.keysym.sym == SDLK_q) { SDL_Quit(); return 0; }
            if (event.key.keysym.sym == SDLK_SPACE) { addRectangle(rectangles); }
        
        } 
    }
}



