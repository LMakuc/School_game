#include "Game.h"
#include "../GameObject/GameObject.h"
#include "../Map/Map.h"
#include "../RandomObjects/RandomObjects.h"
#include "../Objects/Animal.h"
#include "../Objects/Scientist.h"

GameObject *player;

Map *map;

RandomObject *lab;

int level = 1;
const int numOfAnimalsAndScientists = 2;                           //če želimo več živali in znanstvenikov spremenimo
int scientistCount = numOfAnimalsAndScientists;
int scientistTab[numOfAnimalsAndScientists] = {0};

Animal *dog[5];
Scientist *scientist[5];

SDL_Renderer *Game::renderer=nullptr;

SDL_Event Game::event;



Game::Game() {

}

Game::~Game() {

}

void Game::initializing(const char* title, int posX, int posY, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		std::cout << "Subsystem created.\n";

		window = SDL_CreateWindow(title, posX, posY, width, height, flags);
		if (window) {
			std::cout << "Window created.\n";
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created.\n";
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

    //player = new GameObject("Assets/Player.png", 100, 100);
	player = new GameObject("Assets/Objects/littlePlayer.png", 400, 320);
	                                                            //enemy = new GameObject("Assets/Enemy.png", 0, 0); za novega igralca
    map=new Map();

    lab = new RandomObject("Assets/Objects/Laboratory.png");

    for(int i=0; i<numOfAnimalsAndScientists; i++){
        dog[i] = new Animal("Assets/Objects/Dog.png");
        scientist[i] = new Scientist("Assets/Objects/Scientist.png");
    }

}

void Game::handleEvents() {
	//SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update() {


	player->updateGameObject();
    lab->updateRandomObject();

    if(lab->hasHitLaboratory(&player->destRect) && (event.key.keysym.sym == SDLK_KP_ENTER)) {

        std::cout << "Laboratory was found.\n";
        for (int i = 0; i < numOfAnimalsAndScientists; i++) {
            dog[i]->found();
            scientist[i]->found();
        }
        lab->hide();
    }

    for(int i=0; i<numOfAnimalsAndScientists; i++){
        if(scientist[i]->hasHitScientist(&player->destRect)){
            //std::cout<<"Scientist " <<i<<" was hit.\n";
            scientist[i]->wasHitByPlayer();
            for(int j=0; j<numOfAnimalsAndScientists; j++){
                if(scientistTab[i]==0){
                    scientistTab[i] = 1;
                    scientistCount--;
                    std::cout<<"Scientist "<<i<<" was hit.\n";
                    std::cout<<"Scientist count: "<<scientistCount<<std::endl;
                }
            }

        }
    }

    if(scientistCount == 0){
        std::cout<<"End of the game!\n";
        endOfGame();
    }

    for(int i=0; i<numOfAnimalsAndScientists; i++){
        dog[i]->updateAnimal();
        scientist[i]->updateScientist();
    }

}

void Game::render() {
	SDL_RenderClear(renderer);

    map->drawMap();

    player->renderGameObject();

    lab->renderRandomObject();

    for(int i=0; i<numOfAnimalsAndScientists; i++){
        dog[i]->renderAnimal();
        scientist[i]->renderScientist();
    }

    SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned.\n";
}

bool Game::running() {
    return isRunning;
}

bool Game::endOfGame() {
    isRunning=false;
    return isRunning;
}