#pragma once
#include "SDL.h"
#include "SDL_image.h"
#undef main
#include <iostream>
#include <fstream>
#include "../Menu/Menu.h"

class Game {
	private:
		SDL_Window* window;

public:

        bool running = false;
        bool labFound=false;

		Game();
		~Game();

		void initialize(const char *title, int posX, int posY, int width, int height, bool fullscreen);

        void initializeNewGame();
        void startNewGame();
		void handleEvents();
		void update();
		void render();
		void clean();

        static SDL_Renderer *renderer;
        static SDL_Event event;
		bool Running();
        void stopGame();

        void inputLeaderboard();
        void outputLeaderboard();

        char name[25];
};