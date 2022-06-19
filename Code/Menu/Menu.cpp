#include "Menu.h"
#include "../Game/Game.h"
#include "../TextureManager//TextureManager.h";
#include <fstream>

SDL_Renderer *Menu::renderer;
SDL_Event Menu::event;

Game *game;

Menu::Menu(const char *title, int x, int y, int width, int height, bool fullscreen) {
    std::cout<<"Input your name: ";
    fgets(name, 25, stdin);
    std::cin.ignore();

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout<<"Failed to initialize: "<<SDL_GetError()<<std::endl;
        isRunning=false;
    }
    else{
        std::cout<<"Subsystem created.\n";
    }

    int flags;
    if(fullscreen){
        flags=SDL_WINDOW_FULLSCREEN;
    }
    window = SDL_CreateWindow(title, x, y, width, height, flags);

    if (window) {
        std::cout << "Window created.\n";
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (Menu::renderer) {
        std::cout << "Renderer created.\n";
    }

    isRunning = true;
    if(isRunning){
        std::cout<<"Is running.\n";
    }
}

void Menu::initialize() {
    SDL_Surface *assetBg = SDL_LoadBMP("Assets/Menu/background.bmp");
    background = SDL_CreateTextureFromSurface(Menu::renderer, assetBg);
}

void Menu::update() {
    SDL_GetMouseState(&Mx, &My);
    //std::cout<<"Mouse x: "<<Mx<<"   Mouse y: "<<My<<std::endl;
    selectorRect.x=Mx;
    selectorRect.y=My;


    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            isRunning=false;
        }
        else if(SDL_HasIntersection(&start, &selectorRect)){
            if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT){
                selection=0;
                select();
            }
        }
        else if(SDL_HasIntersection(&load, &selectorRect)) {
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                selection = 1;
                select();
            }
        }
        else if(SDL_HasIntersection(&leaderboard, &selectorRect)) {
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                selection = 2;
                select();
            }
        }
        else if(SDL_HasIntersection(&quit, &selectorRect)) {
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                isRunning=false;
            }
        }
    }

    draw();
}

void Menu::draw() {
    SDL_RenderClear(Menu::renderer);
    SDL_RenderCopy(Menu::renderer, background, NULL, &render);
    SDL_RenderPresent(Menu::renderer);
}

void Menu::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    std::cout<<"Game cleaned.\n";
}

void Menu::select() {
    const int FPS=120;
    const int frameDelay=1000/FPS;

    switch(selection){
        case 0:
            std::cout<<"Start"<<std::endl;
            game=new Game();
            game->stopGame();
            game->startNewGame();
            game->initializeNewGame();
            while(game->Running()){
                game->handleEvents();
                game->update();
                game->render();
            }
            break;
        case 1:
            std::cout<<"Load"<<std::endl;
            game=new Game();
            game->initializeNewGame();
            while(game->Running()){
                game->handleEvents();
                game->update();
                game->render();
            }
            break;
        case 2:
            std::cout<<"Leaderboard"<<std::endl;
            break;
        case 3:
            std::cout<<"Quit"<<std::endl;
            break;
    }

}

