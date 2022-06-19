#include <iostream>
#include "SDL.h"
#include "Code/Game/Game.h"
#include "Code/Menu/Menu.h"

int main(int argc, const char* argv[]) {

    srand(time(NULL));

    const int FPS = 120, frameDelay = 1000 / FPS;
    unsigned int frameStart;
    int frameTime;

    bool fullscreen;
    std::cout<<"If you want to play fullscreen input 1 or else input 0: ";
    std::cin>>fullscreen;

    Menu *game=new Menu("Ne testiranju nad zivalmi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, fullscreen);
    game->initialize();

    while (game->isRunning) {
        game->update();

        frameStart = SDL_GetTicks();
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay>frameTime){
            SDL_Delay(frameDelay-frameTime);
        }
    }

    game->clean();


    return 0;
}

/*
 znotraj while(game->isRunning){
 frameStart = SDL_GetTicks();
        //std::cout<<frameTime<<std::endl;

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

        if(Game::event.type == SDL_KEYDOWN && Game::event.key.keysym.sym == SDLK_ESCAPE){
            game->stopGame();
 */