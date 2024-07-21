#include <SDL2/SDL.h>
#include <iostream>

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          680, 480,
                                          0);

    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    if(!window)
    {
        std::cout << "Failed to create window\n";
        return -1;
    }

    
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255); 
    SDL_RenderClear(renderer);
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