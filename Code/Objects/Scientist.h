#pragma once
#include "SDL.h"
#include "../Game/Game.h"
#include "../TextureManager/TextureManager.h"
#include "../Menu/Menu.h";

class Scientist{
    private:

        bool show = false, wasHit = true;

        SDL_Texture *objectTexture;
        SDL_Rect srcRect, destRect;

    public:
        Scientist(const char *textureSheet);
        ~Scientist();

        void updateScientist();
        void renderScientist();

        void movementOfScientist();

        void found();
        bool hasHitScientist(const SDL_Rect *player);
        void wasHitByPlayer();
        bool mouseClickOnScientist();

        int xpos, ypos;
};
