#include <SDL2/SDL.h>
#include "macros.hpp"
#include <vector>

void prepare(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255); 
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}


void draw(SDL_Renderer* renderer, SDL_Rect* rect) {

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xFF);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);
    
}


void addRectangle(std::vector<Rectangle>& rectangles) {
    rectangles.push_back(Rectangle());
}