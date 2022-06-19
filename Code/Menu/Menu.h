#pragma once
#include "SDL.h"
#include "../Game/Game.h"

class Menu{
    private:
        SDL_Window *window;
        SDL_Texture *selector;
        SDL_Texture *background;
        bool flags;
        int selection;

        SDL_Rect src, dest;

        int Mx, My;

        SDL_Rect start={356, 263, 800, 26};
        SDL_Rect load={356, 328, 800, 26};
        SDL_Rect leaderboard{356, 394, 800, 26};
        SDL_Rect quit = {356, 459, 800, 26};
        SDL_Rect render = {0, 0, 800, 640};
        SDL_Rect selectorRect  =  {0, 0, 50, 50};

    public:
        bool isRunning;
        static SDL_Event event;
        Menu(const char *title, int x, int y, int width, int height, bool fullscreen);

        static SDL_Renderer *renderer;
        void initialize();
        void draw();
        void clean();
        void update();
        void select();
};