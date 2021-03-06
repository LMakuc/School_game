#include "Game.h"
#include "../GameObject/GameObject.h"
#include "../Map/Map.h"
#include "../RandomObjects/RandomObjects.h"
#include "../Objects/Animal.h"
#include "../Objects/Scientist.h"

#include <iomanip>
#include <sstream>

struct Leaderboard{
    char playerName[25];
    int playerScore;
};

GameObject *player;

Map *map;

RandomObject *lab;

//int level = 1;
const int numOfAnimalsAndScientists = 2;                           //če želimo več živali in znanstvenikov spremenimo
int scientistCount = numOfAnimalsAndScientists;
int scientistTab[numOfAnimalsAndScientists] = {0};
int score = 0;

Animal *dog[2];
Scientist *scientist[2];

SDL_Renderer *Game::renderer=nullptr;

SDL_Event Menu::event;



Game::Game() {

}

Game::~Game() {

}

void Game::startNewGame(){
    scientistCount=2;
    for(int i=0; i<numOfAnimalsAndScientists; i++){
        scientistTab[i]=0;
    }
    std::cout<<scientistCount<<std::endl;
    labFound = false;
    score = 0;
}

void Game::initializeNewGame() {

    std::cout<<"Initialize new game.\n";

    //initialize("Wani", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

    player = new GameObject("Assets/Objects/littlePlayer.png", 400, 320);
    //enemy = new GameObject("Assets/Enemy.png", 0, 0); za novega igralca
    map=new Map();

    lab = new RandomObject("Assets/Objects/Laboratory.png");

    for(int i=0; i<numOfAnimalsAndScientists; i++){
        dog[i] = new Animal("Assets/Objects/Dog.png");
        scientist[i] = new Scientist("Assets/Objects/Scientist.png");
    }

}

void Game::initializeReplay() {
    std::cout<<"Initialize replay.\n";

    map=new Map();

    player = new GameObject("Assets/Objects/littlePlayer.png", 400, 320);
}

void Game::updateReplay(int x, int y){

    std::cout<<"x: "<<x<<"    y: "<<y<<std::endl;
    player->updateReplay(x, y);


}

void Game::renderReplay(){
    SDL_RenderClear(Menu::renderer);
    map->drawMap();
    player->renderGameObject();
    SDL_RenderPresent(Menu::renderer);
}

void Game::handleEvents() {
	//SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type) {
		case SDL_QUIT:
			running = false;
			break;
		default:
			break;
	}

    if(Game::event.type == SDL_KEYDOWN && Game::event.key.keysym.sym == SDLK_ESCAPE){
        stopGame();
    }
}

void Game::update() {

    int animalX[numOfAnimalsAndScientists];
    int animalY[numOfAnimalsAndScientists];
    for(int i=0; i<numOfAnimalsAndScientists; i++){
        animalX[i]=dog[i]->returnX();
        animalY[i]=dog[i]->returnY();
    }

    int playerX=player->returnX();
    int playerY=player->returnY();

    std::ofstream data("Replay.txt", std::ios::app);
    data<<playerX<<std::endl;
    data<<playerY<<std::endl;
    data.close();

	player->updateGameObject();
    lab->updateRandomObject();

    if(lab->hasHitLaboratory(&player->destRect) && (event.key.keysym.sym == SDLK_KP_ENTER)) {

        std::cout << "Laboratory was found.\n";
        labFound = true;
        for (int i = 0; i < numOfAnimalsAndScientists; i++) {
            dog[i]->found();
            scientist[i]->found();
        }
        lab->hide();
    }

    if(labFound){
        for(int i=0; i<numOfAnimalsAndScientists; i++){
            for(int j=0; j<numOfAnimalsAndScientists; j++){
                if(SDL_HasIntersection(&scientist[i]->destRect, &dog[j]->destRect)){
                    if(!scientistTab[i]){
                        score++;
                        std::cout<<"Scientist "<<i+1<<" has hit dog "<<j+1<<std::endl;
                        std::cout<<"Score: "<<score<<std::endl;
                    }
                }
            }
        }
    }

    for(int i=0; i<numOfAnimalsAndScientists; i++){
        if(scientist[i]->hasHitScientist(&player->destRect) && labFound){
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
        inputLeaderboard();
        std::cout<<"End of the game!\n";
        Game::running=false;
    }

    for(int i=0; i<numOfAnimalsAndScientists; i++){
        dog[i]->updateAnimal();
        scientist[i]->updateScientist(animalX[i], animalY[i], labFound);
    }

}

void Game::render() {
	SDL_RenderClear(Menu::renderer);
    map->drawMap();

    player->renderGameObject();

    lab->renderRandomObject();

    for(int i=0; i<numOfAnimalsAndScientists; i++){
        dog[i]->renderAnimal();
        scientist[i]->renderScientist();
    }

    SDL_RenderPresent(Menu::renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned.\n";
}

bool Game::Running() {
    return running;
}

void Game::stopGame(){
    running=!running;
}

void Game::inputLeaderboard() {
    Leaderboard newPlayer;

    strcpy(newPlayer.playerName, name);
    newPlayer.playerScore=score;

    std::cout<<"Name: "<<newPlayer.playerName<<"   Score: "<<newPlayer.playerScore<<std::endl;

    std::ifstream ldb("Leaderboard.bin", std::ios::binary);
    std::ofstream tmp("tmp.bin", std::ios::binary);

    bool input = false;
    int inputted = 0;

    if(ldb.is_open()){
        for(int i=0; i<5; i++){
            Leaderboard something;
            if(ldb.read((char *)&something, sizeof(something))){
                if(something.playerScore > newPlayer.playerScore && !input){
                    input=true;
                    tmp.write((char *)&newPlayer, sizeof(newPlayer));
                    inputted++;
                }
                if(tmp.write((char *)&something, sizeof(something)))
                    inputted++;
            }
        }
        if(inputted<5 && !input){
            tmp.write((char *)&newPlayer, sizeof(newPlayer));
        }
    }
    else{
        tmp.write((char *)&newPlayer, sizeof(newPlayer));
    }

    ldb.close();
    tmp.close();



    remove("Leaderboard.bin");
    rename("tmp.bin", "Leaderboard.bin");
}

void Game::outputLeaderboard(){
    Leaderboard tmp;

    std::ifstream data("Leaderboard.bin", std::ios::binary);

    if(data.is_open()){
        for(int i=0; i<5; i++){
            while(data.read((char *)&tmp, sizeof(tmp))){
                std::cout<<i+1<<". "<<tmp.playerName<<std::setw(10)<<tmp.playerScore<<std::endl;
            }
        }
    }

    data.close();
}