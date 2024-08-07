#include <SDL2/SDL.h>
#include "macros.hpp"
#include <iostream>
#include <random>

SDL_Rect* Rectangle::getRect() {
    return &startRect;
}

void Rectangle::Hover() { // tip for how random works https://www.youtube.com/watch?v=oW6iuFbwPDg
    std::random_device rd;
    std::uniform_int_distribution<int> dist(35, 45);

    startRect.x = dist(rd);
    startRect.y = dist(rd);

}
        
void Rectangle::Pos() {
    std::cout << "x = " << startRect.x << "\n" << startRect.y << "\n";
}
