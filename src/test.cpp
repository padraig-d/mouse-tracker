#include <SDL2/SDL.h>
#include <iostream>
#include "../include/Macros.hpp"

class Rectangle {
    public:
        SDL_Rect startRect = {
            .x = 40,
            .y = 40,
            .w = 50,
            .h = 50,
        };

        SDL_Rect* getRect() {
            
            return &startRect;
        }
};


int main() {
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
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


    if(!window)
    {
        std::cout << "Failed to create window\n";
        return -1;
    }
    Rectangle rectangle;
    SDL_Rect* rect = rectangle.getRect();
        
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xFF);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);


    while (true) {
        SDL_Event event;
        
        while(SDL_PollEvent(&event)) { 
            switch (event.type) {
                case SDL_QUIT:
                    SDL_Quit();
                    return 0;
            } 
        }
    }




}