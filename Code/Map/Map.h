#pragma once

#include "../Game/Game.h"
#include "../Menu/Menu.h"

class Map{
    private:

        SDL_Rect src, dest;
        SDL_Texture *bottomBorder, *topBorder, *leftBorder, *rightBorder;
        SDL_Texture *bottomLeft, *bottomRight, *topLeft, *topRight;
        SDL_Texture *background, *blackBacground;

        int map[20][25];

    public:

        Map();
        ~Map();

        void loadMap(int arr[20][25]);
        void drawMap();
};