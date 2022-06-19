#pragma once
#include "SDL.h"
#include "../Game/Game.h"
#include "../TextureManager/TextureManager.h"
#include "../Menu/Menu.h"

class Scientist{
    private:

        bool show = false, wasHit = true;

        SDL_Texture *objectTexture;

        SDL_Rect scientis = {0, 0, 32, 32};

    public:
        SDL_Rect srcRect, destRect;

        Scientist(const char *textureSheet);
        ~Scientist();

        void updateScientist(int x, int y, bool labFound);
        void renderScientist();

        void movementOfScientist(int x, int y, bool labFound);

        void found();
        bool hasHitScientist(const SDL_Rect *player);
        void wasHitByPlayer();

        int xpos, ypos;
};
