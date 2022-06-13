#pragma once
#include "SDL.h"

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



        SDL_Rect srcRect;
        SDL_Rect destRect;
};