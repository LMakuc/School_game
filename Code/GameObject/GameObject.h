#pragma once
#include "SDL.h"
#include "../Menu/Menu.h"

class GameObject {
    private:
        int xpos, ypos;

		SDL_Texture *objectTexture;


	public:
		GameObject(const char *textureSheet, int x, int y);
		~GameObject();

		void updateGameObject();
		void renderGameObject();

        void movementOfPlayer();

        int returnX(){return xpos;}
        int returnY(){return ypos;}

        SDL_Rect srcRect;
        SDL_Rect destRect;
};