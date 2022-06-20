#pragma once
#include "SDL.h"
#include "../Game/Game.h"
#include "../TextureManager/TextureManager.h"
#include "../Menu/Menu.h"

class RandomObject{
    private:
        bool show = true;

        SDL_Texture *objectTexture;
        SDL_Rect srcRect, destRect;

    public:
        RandomObject(const char *textureSheet);
        ~RandomObject();

        void updateRandomObject();
        void renderRandomObject();

        bool hasHitLaboratory(const SDL_Rect *player);

        void hide(){show = false;}

        int xpos, ypos;
};
