#pragma once
#include "SDL.h"
#include "SDL_image.h"
#undef main
#include <iostream>

class Game {
	private:
        bool isRunning;
		SDL_Window* window;


	public:
		Game();
		~Game();

		void initializing(const char *title, int posX, int posY, int width, int height, bool fullscreen);
		
		void handleEvents();
		void update();
		void render();
		void clean();

        static SDL_Renderer *renderer;
        static SDL_Event event;
		bool running();
        bool endOfGame();
};