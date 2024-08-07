#define WIDTH 800
#define HEIGHT 600
#include <SDL2/SDL.h>
#include <vector>



class Rectangle {
    public:
        SDL_Rect startRect = {
            .x = 40,
            .y = 40,
            .w = 10,
            .h = 10,
        };

    SDL_Rect* getRect();
    void Hover();
    void Pos();

};

void prepare(SDL_Renderer* renderer);
void draw(SDL_Renderer* renderer, SDL_Rect* rect);
void addRectangle(std::vector<Rectangle>& rectangles);