#include <iostream>
#include "SDL.h"
#include "Code/Game/Game.h"

Game* game = nullptr;

int main(int argc, const char* argv[]) {

    srand(time(NULL));

    const int FPS = 120, frameDelay = 1000 / FPS;
    unsigned int frameStart;
    int frameTime;

    bool fullscreen;
    std::cout<<"Ce zelite celozaslonsko igro vpisite 1, drugace vpisite 0: ";
    std::cin>>fullscreen;

    game = new Game();
    if(fullscreen){
        game->initializing("Wani", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, SDL_WINDOW_FULLSCREEN);
    }
    else{
        game->initializing("Wani", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, fullscreen);
    }

    while (game->running()) {


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
            break;
        }
    }

    game->clean();

    return 0;
}