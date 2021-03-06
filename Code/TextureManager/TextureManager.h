#pragma once
#include "../Game/Game.h"
#include "../Menu/Menu.h"
#include "SDL_image.h"

class TextureManager {
	private:

	public:
		static SDL_Texture* LoadTexture(const char *fileName);
        static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
};