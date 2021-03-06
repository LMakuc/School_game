#pragma once
#include "SDL.h"
#include "../Game/Game.h"
#include "../TextureManager/TextureManager.h"
#include "../Menu/Menu.h"

class Animal{
    private:

        bool show = false;
        int xpos, ypos;

        SDL_Texture *objectTexture;


    public:

        SDL_Rect srcRect, destRect;

        Animal(const char *textureSheet);
        ~Animal();

        void updateAnimal();
        void renderAnimal();

        void movementOfAnimal();

        int returnX();
        int returnY();

        void found();
        //bool hitScientist(const SDL_Rect *player);

};
